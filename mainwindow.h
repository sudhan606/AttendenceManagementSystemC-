#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "PinCodeWindow.h"
#include "LoginWindow.h"
#include<QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openPinCodeWindow();
    void openLoginWindow();

private:
    QPushButton *attendanceEntryButton;
    QPushButton *adminLoginButton;
};

#endif // MAINWINDOW_H
