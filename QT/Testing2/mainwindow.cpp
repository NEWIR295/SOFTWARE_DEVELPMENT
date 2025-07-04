#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Central Widget
    centralLabel = new QLabel("Hello from Central Widget!", this);
    setCentralWidget(centralLabel);

    // Menu Bar
    QMenu *fileMenu = menuBar()->addMenu("File");
    QAction *exitAction = fileMenu->addAction("Exit");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    // Tool Bar
    QToolBar *toolbar = addToolBar("Main Toolbar");
    QAction *dummyAction = toolbar->addAction("Dummy Action");
    toolbar -> addSeparator();
    toolbar -> addWidget(new QLineEdit(tr("Find ..")));
    connect(dummyAction, &QAction::triggered, this, [=](){
        statusBar()->showMessage("Dummy Action Clicked");
    });

    // Status Bar
    statusBar()->showMessage("Ready");

    // Dock Widget
    dockWidget = new QDockWidget("Dock Panel", this);
    QTextEdit *dockTextEdit = new QTextEdit(dockWidget);
    dockTextEdit->setText("I'm a Dock Widget!");
    dockWidget->setWidget(dockTextEdit);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    // Window title & size
    setWindowTitle("QMainWindow Full Example");
    resize(600, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}
