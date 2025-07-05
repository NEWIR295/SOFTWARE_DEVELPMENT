#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , cmdMgr(std::make_unique<CommandManager>())
    , automation(std::make_unique<AutomationContext>())
    , sensor(std::make_unique<MotionSensor>())
{
    ui->setupUi(this);
    setupUI();
    connectSignals();
    
    // Initialize with some default devices
    auto light = DeviceFactory::createDevice("light");
    auto thermostat = DeviceFactory::createDevice("thermostat");
    auto doorLock = DeviceFactory::createDevice("doorlock");
    auto camera = DeviceFactory::createDevice("camera");
    
    allDevices["Living Room Light"] = light;
    allDevices["Main Thermostat"] = thermostat;
    allDevices["Front Door"] = doorLock;
    allDevices["Security Camera"] = camera;
    
    // Register devices with central controller
    HomeController& controller = HomeController::getInstance();
    controller.registerDevice("Living Room Light", light);
    controller.registerDevice("Main Thermostat", thermostat);
    controller.registerDevice("Front Door", doorLock);
    controller.registerDevice("Security Camera", camera);
    
    // Setup motion sensor with observable light
    auto obsLight = std::make_shared<ObservableLEDLight>();
    sensor->addObserver(obsLight.get());
    allDevices["Motion Light"] = obsLight;
    controller.registerDevice("Motion Light", obsLight);
    
    updateDeviceList();
    updateSystemStatus();
    
    logMessage("Smart Home Automation System initialized");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    setWindowTitle("Smart Home Automation System");
    setMinimumSize(1000, 700);
    
    // Create central widget and main layout
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Create tab widget
    tabWidget = new QTabWidget(centralWidget);
    
    // Setup all tabs
    setupDeviceTab();
    setupGroupTab();
    setupAutomationTab();
    setupStatusTab();
    
    // Main layout
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(tabWidget);
    
    // Style the application
    setStyleSheet(R"(
        QMainWindow {
            background-color: #f0f0f0;
        }
        QTabWidget::pane {
            border: 1px solid #c0c0c0;
            background-color: white;
        }
        QTabWidget::tab-bar {
            alignment: center;
        }
        QTabBar::tab {
            background-color: #e0e0e0;
            padding: 8px 16px;
            margin-right: 2px;
            border-top-left-radius: 4px;
            border-top-right-radius: 4px;
        }
        QTabBar::tab:selected {
            background-color: white;
            border-bottom: 2px solid #0078d4;
        }
        QPushButton {
            background-color: #0078d4;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #106ebe;
        }
        QPushButton:pressed {
            background-color: #005a9e;
        }
        QPushButton:disabled {
            background-color: #cccccc;
            color: #666666;
        }
        QListWidget {
            border: 1px solid #d0d0d0;
            border-radius: 4px;
            background-color: white;
        }
        QListWidget::item {
            padding: 8px;
            border-bottom: 1px solid #e0e0e0;
        }
        QListWidget::item:selected {
            background-color: #e6f3ff;
            color: #0078d4;
        }
        QGroupBox {
            font-weight: bold;
            border: 2px solid #d0d0d0;
            border-radius: 8px;
            margin-top: 10px;
            padding-top: 10px;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            left: 10px;
            padding: 0 5px 0 5px;
        }
    )");
}

void MainWindow::setupDeviceTab()
{
    deviceTab = new QWidget();
    tabWidget->addTab(deviceTab, "Device Control");
    
    QHBoxLayout* deviceLayout = new QHBoxLayout(deviceTab);
    
    // Left side - Device list and controls
    QVBoxLayout* leftLayout = new QVBoxLayout();
    
    // Device list
    QLabel* deviceLabel = new QLabel("Smart Devices:");
    deviceLabel->setFont(QFont("Arial", 12, QFont::Bold));
    deviceList = new QListWidget();
    deviceList->setMinimumWidth(200);
    
    // Device control buttons
    QHBoxLayout* deviceBtnLayout = new QHBoxLayout();
    addDeviceBtn = new QPushButton("Add Device");
    removeDeviceBtn = new QPushButton("Remove Device");
    deviceBtnLayout->addWidget(addDeviceBtn);
    deviceBtnLayout->addWidget(removeDeviceBtn);
    
    // Basic device controls
    QHBoxLayout* basicControlLayout = new QHBoxLayout();
    turnOnBtn = new QPushButton("Turn On");
    turnOffBtn = new QPushButton("Turn Off");
    statusBtn = new QPushButton("Get Status");
    basicControlLayout->addWidget(turnOnBtn);
    basicControlLayout->addWidget(turnOffBtn);
    basicControlLayout->addWidget(statusBtn);
    
    leftLayout->addWidget(deviceLabel);
    leftLayout->addWidget(deviceList);
    leftLayout->addLayout(deviceBtnLayout);
    leftLayout->addLayout(basicControlLayout);
    
    // Right side - Device-specific controls
    deviceControlsGroup = new QGroupBox("Device Controls");
    deviceControlsLayout = new QVBoxLayout(deviceControlsGroup);
    
    setupDeviceSpecificControls();
    
    deviceLayout->addLayout(leftLayout, 1);
    deviceLayout->addWidget(deviceControlsGroup, 1);
    
    // Initially disable controls
    updateDeviceControls();
}

void MainWindow::setupDeviceSpecificControls()
{
    // Thermostat controls
    thermostatControls = new QWidget();
    QVBoxLayout* thermoLayout = new QVBoxLayout(thermostatControls);
    
    QLabel* tempLabel = new QLabel("Temperature:");
    tempSpinBox = new QSpinBox();
    tempSpinBox->setRange(10, 35);
    tempSpinBox->setValue(22);
    tempSpinBox->setSuffix("°C");
    setTempBtn = new QPushButton("Set Temperature");
    
    QLabel* modeLabel = new QLabel("Mode:");
    modeComboBox = new QComboBox();
    modeComboBox->addItems({"Heating", "Cooling", "Off"});
    switchModeBtn = new QPushButton("Switch Mode");
    
    thermoLayout->addWidget(tempLabel);
    thermoLayout->addWidget(tempSpinBox);
    thermoLayout->addWidget(setTempBtn);
    thermoLayout->addWidget(modeLabel);
    thermoLayout->addWidget(modeComboBox);
    thermoLayout->addWidget(switchModeBtn);
    
    // Door lock controls
    doorLockControls = new QWidget();
    QVBoxLayout* doorLayout = new QVBoxLayout(doorLockControls);
    
    lockBtn = new QPushButton("Lock Door");
    unlockBtn = new QPushButton("Unlock Door");
    doorLayout->addWidget(lockBtn);
    doorLayout->addWidget(unlockBtn);
    
    // Camera controls
    cameraControls = new QWidget();
    QVBoxLayout* cameraLayout = new QVBoxLayout(cameraControls);
    
    nightVisionBtn = new QPushButton("Toggle Night Vision");
    cameraLayout->addWidget(nightVisionBtn);
    
    // Light controls
    lightControls = new QWidget();
    QVBoxLayout* lightLayout = new QVBoxLayout(lightControls);
    
    QLabel* brightnessLabel = new QLabel("Brightness:");
    brightnessSpinBox = new QSpinBox();
    brightnessSpinBox->setRange(0, 100);
    brightnessSpinBox->setValue(50);
    brightnessSpinBox->setSuffix("%");
    dimBtn = new QPushButton("Set Brightness");
    
    lightLayout->addWidget(brightnessLabel);
    lightLayout->addWidget(brightnessSpinBox);
    lightLayout->addWidget(dimBtn);
    
    // Add all controls to main layout (initially hidden)
    deviceControlsLayout->addWidget(thermostatControls);
    deviceControlsLayout->addWidget(doorLockControls);
    deviceControlsLayout->addWidget(cameraControls);
    deviceControlsLayout->addWidget(lightControls);
    
    // Hide all initially
    thermostatControls->hide();
    doorLockControls->hide();
    cameraControls->hide();
    lightControls->hide();
}

void MainWindow::setupGroupTab()
{
    groupTab = new QWidget();
    tabWidget->addTab(groupTab, "Device Groups");
    
    QHBoxLayout* groupLayout = new QHBoxLayout(groupTab);
    
    // Left side - Group management
    QVBoxLayout* leftLayout = new QVBoxLayout();
    
    QLabel* groupLabel = new QLabel("Device Groups:");
    groupLabel->setFont(QFont("Arial", 12, QFont::Bold));
    groupList = new QListWidget();
    
    QHBoxLayout* groupBtnLayout = new QHBoxLayout();
    createGroupBtn = new QPushButton("Create Group");
    addToGroupBtn = new QPushButton("Add to Group");
    groupBtnLayout->addWidget(createGroupBtn);
    groupBtnLayout->addWidget(addToGroupBtn);
    
    QHBoxLayout* groupControlLayout = new QHBoxLayout();
    groupOnBtn = new QPushButton("Turn Group On");
    groupOffBtn = new QPushButton("Turn Group Off");
    groupControlLayout->addWidget(groupOnBtn);
    groupControlLayout->addWidget(groupOffBtn);
    
    leftLayout->addWidget(groupLabel);
    leftLayout->addWidget(groupList);
    leftLayout->addLayout(groupBtnLayout);
    leftLayout->addLayout(groupControlLayout);
    
    // Right side - Available devices
    QVBoxLayout* rightLayout = new QVBoxLayout();
    QLabel* availableLabel = new QLabel("Available Devices:");
    availableLabel->setFont(QFont("Arial", 12, QFont::Bold));
    availableDevicesList = new QListWidget();
    
    rightLayout->addWidget(availableLabel);
    rightLayout->addWidget(availableDevicesList);
    
    groupLayout->addLayout(leftLayout, 1);
    groupLayout->addLayout(rightLayout, 1);
}

void MainWindow::setupAutomationTab()
{
    automationTab = new QWidget();
    tabWidget->addTab(automationTab, "Automation");
    
    QVBoxLayout* automationLayout = new QVBoxLayout(automationTab);
    
    // Automation mode selection
    QGroupBox* modeGroup = new QGroupBox("Automation Mode");
    QVBoxLayout* modeLayout = new QVBoxLayout(modeGroup);
    
    QLabel* modeLabel = new QLabel("Select Automation Mode:");
    automationModeCombo = new QComboBox();
    automationModeCombo->addItems({"Comfort Mode", "Energy Saving Mode"});
    setModeBtn = new QPushButton("Set Mode");
    
    modeLayout->addWidget(modeLabel);
    modeLayout->addWidget(automationModeCombo);
    modeLayout->addWidget(setModeBtn);
    
    // Device selection for automation
    QGroupBox* deviceGroup = new QGroupBox("Apply Automation");
    QVBoxLayout* deviceLayout = new QVBoxLayout(deviceGroup);
    
    QLabel* deviceLabel = new QLabel("Select Device:");
    automationDevicesList = new QListWidget();
    applyAutomationBtn = new QPushButton("Apply Automation");
    
    deviceLayout->addWidget(deviceLabel);
    deviceLayout->addWidget(automationDevicesList);
    deviceLayout->addWidget(applyAutomationBtn);
    
    // Motion sensor simulation
    QGroupBox* motionGroup = new QGroupBox("Motion Sensor");
    QVBoxLayout* motionLayout = new QVBoxLayout(motionGroup);
    
    QLabel* motionLabel = new QLabel("Simulate motion detection:");
    triggerMotionBtn = new QPushButton("Trigger Motion");
    
    motionLayout->addWidget(motionLabel);
    motionLayout->addWidget(triggerMotionBtn);
    
    automationLayout->addWidget(modeGroup);
    automationLayout->addWidget(deviceGroup);
    automationLayout->addWidget(motionGroup);
    automationLayout->addStretch();
}

void MainWindow::setupStatusTab()
{
    statusTab = new QWidget();
    tabWidget->addTab(statusTab, "System Status");
    
    QVBoxLayout* statusLayout = new QVBoxLayout(statusTab);
    
    // System status
    QGroupBox* statusGroup = new QGroupBox("System Status");
    QVBoxLayout* statusGroupLayout = new QVBoxLayout(statusGroup);
    
    systemStatusLabel = new QLabel("System: Online");
    systemStatusLabel->setFont(QFont("Arial", 12, QFont::Bold));
    systemStatusLabel->setStyleSheet("color: green;");
    
    statusGroupLayout->addWidget(systemStatusLabel);
    
    // Command history
    QGroupBox* commandGroup = new QGroupBox("Command History");
    QVBoxLayout* commandLayout = new QVBoxLayout(commandGroup);
    
    QHBoxLayout* commandBtnLayout = new QHBoxLayout();
    undoBtn = new QPushButton("Undo Last Command");
    clearHistoryBtn = new QPushButton("Clear History");
    commandBtnLayout->addWidget(undoBtn);
    commandBtnLayout->addWidget(clearHistoryBtn);
    
    commandLayout->addLayout(commandBtnLayout);
    
    // System log
    QGroupBox* logGroup = new QGroupBox("System Log");
    QVBoxLayout* logLayout = new QVBoxLayout(logGroup);
    
    logTextEdit = new QTextEdit();
    logTextEdit->setReadOnly(true);
    logTextEdit->setMaximumHeight(200);
    
    clearLogBtn = new QPushButton("Clear Log");
    
    logLayout->addWidget(logTextEdit);
    logLayout->addWidget(clearLogBtn);
    
    statusLayout->addWidget(statusGroup);
    statusLayout->addWidget(commandGroup);
    statusLayout->addWidget(logGroup);
    statusLayout->addStretch();
}

void MainWindow::connectSignals()
{
    // Device tab connections
    connect(addDeviceBtn, &QPushButton::clicked, this, &MainWindow::onAddDevice);
    connect(removeDeviceBtn, &QPushButton::clicked, this, &MainWindow::onRemoveDevice);
    connect(deviceList, &QListWidget::currentTextChanged, this, &MainWindow::onDeviceSelectionChanged);
    connect(turnOnBtn, &QPushButton::clicked, this, &MainWindow::onTurnOnDevice);
    connect(turnOffBtn, &QPushButton::clicked, this, &MainWindow::onTurnOffDevice);
    connect(statusBtn, &QPushButton::clicked, this, &MainWindow::onGetDeviceStatus);
    
    // Device-specific controls
    connect(setTempBtn, &QPushButton::clicked, this, &MainWindow::onSetThermostatTemp);
    connect(switchModeBtn, &QPushButton::clicked, this, &MainWindow::onSwitchThermostatMode);
    connect(lockBtn, &QPushButton::clicked, this, &MainWindow::onLockDoor);
    connect(unlockBtn, &QPushButton::clicked, this, &MainWindow::onUnlockDoor);
    connect(nightVisionBtn, &QPushButton::clicked, this, &MainWindow::onEnableNightVision);
    connect(dimBtn, &QPushButton::clicked, this, &MainWindow::onDimLight);
    
    // Group tab connections
    connect(createGroupBtn, &QPushButton::clicked, this, &MainWindow::onCreateGroup);
    connect(addToGroupBtn, &QPushButton::clicked, this, &MainWindow::onAddToGroup);
    connect(groupOnBtn, &QPushButton::clicked, this, &MainWindow::onControlGroup);
    connect(groupOffBtn, &QPushButton::clicked, this, &MainWindow::onControlGroup);
    connect(groupList, &QListWidget::currentTextChanged, this, [this](const QString& text) {
        currentGroup = text;
        updateDeviceList();
    });
    
    // Automation tab connections
    connect(setModeBtn, &QPushButton::clicked, this, &MainWindow::onSetAutomationMode);
    connect(applyAutomationBtn, &QPushButton::clicked, this, &MainWindow::onApplyAutomation);
    connect(triggerMotionBtn, &QPushButton::clicked, this, &MainWindow::onTriggerMotion);
    connect(automationDevicesList, &QListWidget::currentTextChanged, this, [this](const QString& text) {
        currentAutomationDevice = text;
    });
    
    // Status tab connections
    connect(undoBtn, &QPushButton::clicked, this, &MainWindow::onUndoCommand);
    connect(clearHistoryBtn, &QPushButton::clicked, this, &MainWindow::onClearHistory);
    connect(clearLogBtn, &QPushButton::clicked, this, [this]() {
        logTextEdit->clear();
    });
}

// Device Management Slots
void MainWindow::onAddDevice()
{
    QStringList deviceTypes = {"Light", "Thermostat", "Door Lock", "Security Camera"};
    bool ok;
    QString type = QInputDialog::getItem(this, "Add Device", "Select device type:", deviceTypes, 0, false, &ok);
    
    if (ok && !type.isEmpty()) {
        QString name = QInputDialog::getText(this, "Add Device", "Enter device name:", QLineEdit::Normal, "", &ok);
        
        if (ok && !name.isEmpty()) {
            std::string deviceType = type.toLower().toStdString();
            if (deviceType == "door lock") deviceType = "doorlock";
            if (deviceType == "security camera") deviceType = "camera";
            
            auto device = DeviceFactory::createDevice(deviceType);
            if (device) {
                allDevices[name.toStdString()] = device;
                HomeController::getInstance().registerDevice(name.toStdString(), device);
                updateDeviceList();
                logMessage(QString("Added device: %1 (%2)").arg(name, type));
            }
        }
    }
}

void MainWindow::onRemoveDevice()
{
    if (currentDevice.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a device to remove.");
        return;
    }
    
    int ret = QMessageBox::question(this, "Confirm", 
                                   QString("Are you sure you want to remove %1?").arg(currentDevice),
                                   QMessageBox::Yes | QMessageBox::No);
    
    if (ret == QMessageBox::Yes) {
        allDevices.erase(currentDevice.toStdString());
        updateDeviceList();
        logMessage(QString("Removed device: %1").arg(currentDevice));
        currentDevice.clear();
    }
}

void MainWindow::onDeviceSelectionChanged()
{
    QListWidgetItem* item = deviceList->currentItem();
    if (item) {
        currentDevice = item->text();
        updateDeviceControls();
    } else {
        currentDevice.clear();
        updateDeviceControls();
    }
}

void MainWindow::onTurnOnDevice()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        auto cmd = std::make_unique<TurnOnCommand>(it->second.get());
        cmdMgr->executeCommand(std::move(cmd));
        logMessage(QString("Turned on: %1").arg(currentDevice));
    }
}

void MainWindow::onTurnOffDevice()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        auto cmd = std::make_unique<TurnOffCommand>(it->second.get());
        cmdMgr->executeCommand(std::move(cmd));
        logMessage(QString("Turned off: %1").arg(currentDevice));
    }
}

void MainWindow::onGetDeviceStatus()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        std::string status = it->second->getStatus();
        logMessage(QString("%1 Status: %2").arg(currentDevice, QString::fromStdString(status)));
        QMessageBox::information(this, "Device Status", 
                                QString("%1:\n%2").arg(currentDevice, QString::fromStdString(status)));
    }
}

// Device-specific control slots
void MainWindow::onSetThermostatTemp()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        auto thermostat = std::dynamic_pointer_cast<Thermostat>(it->second);
        if (thermostat) {
            thermostat->setTemperature(tempSpinBox->value());
            logMessage(QString("Set %1 temperature to %2°C").arg(currentDevice).arg(tempSpinBox->value()));
        }
    }
}

void MainWindow::onSwitchThermostatMode()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        auto thermostat = std::dynamic_pointer_cast<Thermostat>(it->second);
        if (thermostat) {
            thermostat->switchMode(modeComboBox->currentText().toStdString());
            logMessage(QString("Switched %1 to %2 mode").arg(currentDevice, modeComboBox->currentText()));
        }
    }
}

void MainWindow::onLockDoor()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        auto doorLock = std::dynamic_pointer_cast<DoorLock>(it->second);
        if (doorLock) {
            doorLock->lock();
            logMessage(QString("Locked: %1").arg(currentDevice));
        }
    }
}

void MainWindow::onUnlockDoor()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        auto doorLock = std::dynamic_pointer_cast<DoorLock>(it->second);
        if (doorLock) {
            doorLock->unlock();
            logMessage(QString("Unlocked: %1").arg(currentDevice));
        }
    }
}

void MainWindow::onEnableNightVision()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        auto camera = std::dynamic_pointer_cast<SecurityCamera>(it->second);
        if (camera) {
            camera->enableNightVision();
            logMessage(QString("Toggled night vision for: %1").arg(currentDevice));
        }
    }
}

void MainWindow::onDimLight()
{
    if (currentDevice.isEmpty()) return;
    
    auto it = allDevices.find(currentDevice.toStdString());
    if (it != allDevices.end()) {
        auto light = std::dynamic_pointer_cast<LEDLight>(it->second);
        if (light) {
            light->dim(brightnessSpinBox->value());
            logMessage(QString("Set %1 brightness to %2%").arg(currentDevice).arg(brightnessSpinBox->value()));
        }
    }
}

// Group Management Slots
void MainWindow::onCreateGroup()
{
    bool ok;
    QString groupName = QInputDialog::getText(this, "Create Group", "Enter group name:", QLineEdit::Normal, "", &ok);
    
    if (ok && !groupName.isEmpty()) {
        auto group = std::make_shared<DeviceGroup>(groupName.toStdString());
        allGroups[groupName.toStdString()] = group;
        updateGroupList();
        logMessage(QString("Created group: %1").arg(groupName));
    }
}

void MainWindow::onAddToGroup()
{
    if (currentGroup.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a group first.");
        return;
    }
    
    QListWidgetItem* item = availableDevicesList->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Warning", "Please select a device to add.");
        return;
    }
    
    QString deviceName = item->text();
    auto groupIt = allGroups.find(currentGroup.toStdString());
    auto deviceIt = allDevices.find(deviceName.toStdString());
    
    if (groupIt != allGroups.end() && deviceIt != allDevices.end()) {
        groupIt->second->addDevice(deviceIt->second);
        logMessage(QString("Added %1 to group %2").arg(deviceName, currentGroup));
    }
}

void MainWindow::onControlGroup()
{
    if (currentGroup.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a group first.");
        return;
    }
    
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    auto groupIt = allGroups.find(currentGroup.toStdString());
    
    if (groupIt != allGroups.end()) {
        if (button == groupOnBtn) {
            groupIt->second->turnOn();
            logMessage(QString("Turned on group: %1").arg(currentGroup));
        } else if (button == groupOffBtn) {
            groupIt->second->turnOff();
            logMessage(QString("Turned off group: %1").arg(currentGroup));
        }
    }
}

// Automation Slots
void MainWindow::onTriggerMotion()
{
    sensor->detectMotion();
    logMessage("Motion detected! Observable lights activated.");
}

void MainWindow::onSetAutomationMode()
{
    QString mode = automationModeCombo->currentText();
    
    if (mode == "Comfort Mode") {
        automation->setMode(std::make_unique<ComfortMode>());
    } else if (mode == "Energy Saving Mode") {
        automation->setMode(std::make_unique<EnergySavingMode>());
    }
    
    logMessage(QString("Set automation mode to: %1").arg(mode));
}

void MainWindow::onApplyAutomation()
{
    if (currentAutomationDevice.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a device for automation.");
        return;
    }
    
    auto it = allDevices.find(currentAutomationDevice.toStdString());
    if (it != allDevices.end()) {
        automation->applyMode(it->second.get());
        logMessage(QString("Applied automation to: %1").arg(currentAutomationDevice));
    }
}

// Command Management Slots
void MainWindow::onUndoCommand()
{
    cmdMgr->undoLast();
    logMessage("Undid last command");
}

void MainWindow::onClearHistory()
{
    // Note: CommandManager doesn't have a clear method, so we create a new one
    cmdMgr = std::make_unique<CommandManager>();
    logMessage("Cleared command history");
}

// UI Update Methods
void MainWindow::updateDeviceList()
{
    deviceList->clear();
    availableDevicesList->clear();
    automationDevicesList->clear();
    
    for (const auto& pair : allDevices) {
        QString deviceName = QString::fromStdString(pair.first);
        deviceList->addItem(deviceName);
        availableDevicesList->addItem(deviceName);
        automationDevicesList->addItem(deviceName);
    }
}

void MainWindow::updateGroupList()
{
    groupList->clear();
    
    for (const auto& pair : allGroups) {
        QString groupName = QString::fromStdString(pair.first);
        groupList->addItem(groupName);
    }
}

void MainWindow::updateDeviceControls()
{
    // Hide all device-specific controls first
    thermostatControls->hide();
    doorLockControls->hide();
    cameraControls->hide();
    lightControls->hide();
    
    bool hasDevice = !currentDevice.isEmpty();
    turnOnBtn->setEnabled(hasDevice);
    turnOffBtn->setEnabled(hasDevice);
    statusBtn->setEnabled(hasDevice);
    
    if (hasDevice) {
        auto it = allDevices.find(currentDevice.toStdString());
        if (it != allDevices.end()) {
            // Show appropriate controls based on device type
            if (std::dynamic_pointer_cast<Thermostat>(it->second)) {
                thermostatControls->show();
            } else if (std::dynamic_pointer_cast<DoorLock>(it->second)) {
                doorLockControls->show();
            } else if (std::dynamic_pointer_cast<SecurityCamera>(it->second)) {
                cameraControls->show();
            } else if (std::dynamic_pointer_cast<LEDLight>(it->second)) {
                lightControls->show();
            }
        }
    }
}

void MainWindow::updateSystemStatus()
{
    int deviceCount = allDevices.size();
    int groupCount = allGroups.size();
    
    QString statusText = QString("System: Online | Devices: %1 | Groups: %2")
                        .arg(deviceCount).arg(groupCount);
    
    systemStatusLabel->setText(statusText);
}

