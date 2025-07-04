
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QThread>
#include <QCoreApplication>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    toggleButton = new QPushButton("Show Message");
    outputLabel = new QLabel("Waiting...");
    layout->addWidget(toggleButton);
    layout->addWidget(outputLabel);

    connect(toggleButton, &QPushButton::clicked, this, [=]() {
        outputLabel->setText("Button Clicked!");
    });

    slider = new QSlider(Qt::Horizontal);
    spinBox = new QSpinBox;
    progressBar = new QProgressBar;

    slider->setRange(0, 100);
    spinBox->setRange(0, 100);
    progressBar->setRange(0, 100);

    layout->addWidget(slider);
    layout->addWidget(spinBox);
    layout->addWidget(progressBar);

    connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);
    connect(slider, &QSlider::valueChanged, progressBar, &QProgressBar::setValue);

    QPushButton *fileBtn = new QPushButton("Open File");
    layout->addWidget(fileBtn);
    connect(fileBtn, &QPushButton::clicked, this, &MainWindow::showFileDialog);

    QPushButton *progressBtn = new QPushButton("Show Progress Dialog");
    layout->addWidget(progressBtn);
    connect(progressBtn, &QPushButton::clicked, this, &MainWindow::showProgressDialog);

    setCentralWidget(central);

    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Open File", this, &MainWindow::showFileDialog);
    fileMenu->addSeparator();
    fileMenu->addAction("Exit", qApp, &QCoreApplication::quit);

    QMenu *helpMenu = menuBar()->addMenu("Help");
    helpMenu->addAction("About", this, &MainWindow::showAboutDialog);

    QToolBar *toolBar = addToolBar("Main Toolbar");
    toolBar->addAction("About", this, &MainWindow::showAboutDialog);

    statusBar()->showMessage("Ready");
}

MainWindow::~MainWindow() {}

void MainWindow::showAboutDialog() {
    QMessageBox::information(this, "About", "This app summarizes our full Qt Widgets journey!");
}

void MainWindow::showFileDialog() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath(), "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        outputLabel->setText("Selected: " + fileName);
        statusBar()->showMessage("File selected");
    }
}

void MainWindow::showProgressDialog() {
    QProgressDialog dialog("Processing...", "Cancel", 0, 100, this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setMinimumDuration(0);
    for (int i = 0; i <= 100; ++i) {
        QCoreApplication::processEvents();
        if (dialog.wasCanceled()) break;
        dialog.setValue(i);
        QThread::msleep(30);
    }
}
