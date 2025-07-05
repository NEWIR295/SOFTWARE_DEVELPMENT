/*
Author: Mohamed Newir
Date: 4/06/2025
File: mainwindow.h
Description:
            -> This file contains the declaration of the MainWindow class,
                which provides a Qt6 GUI interface for the Smart Home Automation System.
            -> It replaces the console interface with a modern graphical user interface.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QTextCursor>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QTextEdit>
#include <QSpinBox>
#include <QGroupBox>
#include <QTabWidget>
#include <QProgressBar>
#include <QTimer>
#include <QMessageBox>
#include <QInputDialog>
#include <QSplitter>
#include <memory>
#include <map>

// Include your smart home system headers
#include "../Include/lightState.hpp"
#include "../Include/centralControl.hpp"
#include "../Include/deviceGroup.hpp"
#include "../Include/command.hpp"
#include "../Include/motionSensor.hpp"
#include "../Include/observer.hpp"
#include "../Include/lightObserver.hpp"
#include "../Include/automatedMode.hpp"
#include "../Include/deviceFactory.hpp"
#include "../Include/thermostat.hpp"
#include "../Include/doorLock.hpp"
#include "../Include/securityCamera.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Device Management
    void onAddDevice();
    void onRemoveDevice();
    void onDeviceSelectionChanged();
    void onTurnOnDevice();
    void onTurnOffDevice();
    void onGetDeviceStatus();
    
    // Device-specific controls
    void onSetThermostatTemp();
    void onSwitchThermostatMode();
    void onLockDoor();
    void onUnlockDoor();
    void onEnableNightVision();
    void onDimLight();
    
    // Group Management
    void onCreateGroup();
    void onAddToGroup();
    void onControlGroup();
    
    // Automation & Motion
    void onTriggerMotion();
    void onSetAutomationMode();
    void onApplyAutomation();
    
    // Command Management
    void onUndoCommand();
    void onClearHistory();
    
    // UI Updates
    void updateDeviceList();
    void updateGroupList();
    void updateDeviceControls();
    void updateSystemStatus();

private:
    void setupUI();
    void setupDeviceTab();
    void setupGroupTab();
    void setupAutomationTab();
    void setupStatusTab();
    void connectSignals();
    void logMessage(const QString& message);
    
    // Core system components
    std::unique_ptr<CommandManager> cmdMgr;
    std::unique_ptr<AutomationContext> automation;
    std::unique_ptr<MotionSensor> sensor;
    std::map<std::string, std::shared_ptr<SmartDevice>> allDevices;
    std::map<std::string, std::shared_ptr<DeviceGroup>> allGroups;
    
    // UI Components
    QTabWidget *tabWidget;
    
    // Device Tab
    QWidget *deviceTab;
    QListWidget *deviceList;
    QPushButton *addDeviceBtn;
    QPushButton *removeDeviceBtn;
    QPushButton *turnOnBtn;
    QPushButton *turnOffBtn;
    QPushButton *statusBtn;
    QGroupBox *deviceControlsGroup;
    QVBoxLayout *deviceControlsLayout;
    
    // Device-specific controls
    QWidget *thermostatControls;
    QSpinBox *tempSpinBox;
    QComboBox *modeComboBox;
    QPushButton *setTempBtn;
    QPushButton *switchModeBtn;
    
    QWidget *doorLockControls;
    QPushButton *lockBtn;
    QPushButton *unlockBtn;
    
    QWidget *cameraControls;
    QPushButton *nightVisionBtn;
    
    QWidget *lightControls;
    QSpinBox *brightnessSpinBox;
    QPushButton *dimBtn;
    
    // Group Tab
    QWidget *groupTab;
    QListWidget *groupList;
    QPushButton *createGroupBtn;
    QPushButton *addToGroupBtn;
    QPushButton *groupOnBtn;
    QPushButton *groupOffBtn;
    QListWidget *availableDevicesList;
    
    // Automation Tab
    QWidget *automationTab;
    QComboBox *automationModeCombo;
    QPushButton *setModeBtn;
    QPushButton *applyAutomationBtn;
    QPushButton *triggerMotionBtn;
    QListWidget *automationDevicesList;
    
    // Status Tab
    QWidget *statusTab;
    QTextEdit *logTextEdit;
    QPushButton *undoBtn;
    QPushButton *clearHistoryBtn;
    QPushButton *clearLogBtn;
    QLabel *systemStatusLabel;
    
    // Current selections
    QString currentDevice;
    QString currentGroup;
    QString currentAutomationDevice;

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
