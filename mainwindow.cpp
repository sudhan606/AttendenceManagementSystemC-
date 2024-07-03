#include "MainWindow.h"
#include<QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    attendanceEntryButton(new QPushButton("Attendance Entry", this)),
    adminLoginButton(new QPushButton("Admin Login", this)),
    headingLabel(new QLabel("Student's Attendance Management System", this)) {
    headingLabel->setGeometry(50, 10, 400, 30); // Position and size
    headingLabel->setAlignment(Qt::AlignCenter); // Center text alignment
    attendanceEntryButton->setGeometry(50, 50, 200, 50);
   adminLoginButton->setGeometry(50, 150, 200, 50);
    connect(attendanceEntryButton, &QPushButton::clicked, this, &MainWindow::openPinCodeWindow);
    connect(adminLoginButton, &QPushButton::clicked, this, &MainWindow::openLoginWindow);
    // Set the size of the main window
    resize(500, 500); // Width: 800, Height: 600
    setWindowTitle("BCT CD Attendance System");
}

MainWindow::~MainWindow() {}

void MainWindow::openPinCodeWindow() {
    PinCodeWindow *pinCodeWindow = new PinCodeWindow();
    pinCodeWindow->show();
}

void MainWindow::openLoginWindow() {
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
}
