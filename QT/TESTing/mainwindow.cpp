#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QInputDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent1)
    : QMainWindow(parent1)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Sad Newir");
    //QDialog *parent = new QDialog(this);
    QGroupBox *box = new QGroupBox(this);
    QPushButton *button = new QPushButton(this);
    QPushButton *toggleButton = new QPushButton("toggle button",this);
    toggleButton -> setCheckable(true);

    QRadioButton *op1 = new QRadioButton(box);
    QRadioButton *op2 = new QRadioButton(box);

    QVBoxLayout *optionsLayout = new QVBoxLayout();
    optionsLayout -> addWidget(op1);
    optionsLayout -> addWidget(op2);
    box -> setLayout(optionsLayout);

    QLabel *label = new QLabel("",this);

    QVBoxLayout *boxLayout = new QVBoxLayout();
    boxLayout -> addWidget(box);
    boxLayout -> addWidget(button);
    boxLayout -> addWidget(label);
    boxLayout -> addWidget(toggleButton);

    QWidget *centralLayout = new QWidget(this);
    centralLayout -> setLayout(boxLayout);
    setCentralWidget(centralLayout);

    box -> setTitle("Options");
    button -> setText("Button");
    op1 ->setText("OP1");
    op2 ->setText("OP2");

    connect(toggleButton, &QPushButton::toggled,this,[toggleButton](bool check){
        if(check){
            toggleButton -> setText("ON");
        }
        else{
            toggleButton -> setText("OFF");
        }
    });

    connect(button, &QPushButton::clicked,this,[=](){

        label -> setAlignment(Qt::AlignCenter);
        label -> setText("button clicked");
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle("Dialog with Widgets");
        dialog->setAttribute(Qt::WA_AlwaysStackOnTop);

        QLabel *label = new QLabel("Hello from Dialog!", dialog);
        QPushButton *button = new QPushButton("OK", dialog);

        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(label);
        layout->addWidget(button);

        dialog->setLayout(layout);

        connect(button, &QPushButton::clicked, dialog, &QDialog::accept);
        dialog-> exec(); // Modal dialog
        //dialog-> raise();

        bool ok;
        int value = QInputDialog::getInt(this, "Input Integer Dialog", "Enter your age:", 18, 0, 100, 1, &ok);

        QString fileName = QFileDialog::getOpenFileName(this,
                                                        "Open File", // Title of the dialog
                                                        QDir::homePath(), // Start in the home directory
                                                        "Text Files (*.txt *.cpp);;All Files (*)" // File filters
                                                        );


    });
    //delete parent; called @ exiting the program
    //parent -> show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
