#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "PinCodeWindow.h"
#include "LoginWindow.h"
#include<QLabel>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include"style.h"
#include "AddStudentWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openPinCodeWindow();
    void openLoginWindow();
    void updateDateTime();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QPushButton *attendanceEntryButton;
    QPushButton *adminLoginButton;
    QLabel *headingLabel;
    QLabel *headingLabel2;
    QLabel *imageLabel;
    QLabel *imageLabel1;
    QLabel *time;
    QTimer *timer;
};

#endif // MAINWINDOW_H
