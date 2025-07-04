#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QProgressBar>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAboutDialog();
    void showFileDialog();
    void showProgressDialog();

private:
    QPushButton *toggleButton;
    QLabel *outputLabel;
    QSlider *slider;
    QSpinBox *spinBox;
    QProgressBar *progressBar;
};

#endif // MAINWINDOW_H
