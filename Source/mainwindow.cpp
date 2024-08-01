#include "MainWindow.h"
#include<QLabel>
#include <QPixmap>
#include"style.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    attendanceEntryButton(new QPushButton("ENTRY", this)),
    adminLoginButton(new QPushButton("LOGIN", this)),
    headingLabel(new QLabel("A T T E N D E R", this)),
   headingLabel2(new QLabel("STUDENT ATTENDANCE MANAGEMENT\nSYSTEM", this)),
imageLabel(new QLabel(this)),
time(new QLabel(this)),
    timer(new QTimer(this)),
imageLabel1(new QLabel(this))
{
    //QString attbtn,loginbtn;
     this->setStyleSheet("QMainWindow {background-color:#051A50;} color:#FFFFFF;");

   headingLabel->setGeometry(50,138, 219, 39); // Position and size
     time->setGeometry(549,12,180,39);
   time->setStyleSheet("font-size:16; font-weight:600; background-color:transparent;");
    //headingLabel->setAlignment(Qt::AlignCenter); // Ce
   headingLabel->setStyleSheet("font-size: 25px; font-weight:600;color:#FFFFFF; background-color:transparent;");
   headingLabel2->setGeometry(50, 184, 270, 32);
   headingLabel2->setStyleSheet("font-size: 13px; font-weight: 200; color:#E6E2E2;background-color:transparent;");
   //ALL STYLE IS IN STYLE.cpp file*/
    attendanceEntryButton->setGeometry(50, 250, 97, 35);
     attendanceEntryButton->setStyleSheet(attbtn);
   adminLoginButton->setGeometry(161, 250, 97, 35);
     adminLoginButton->setStyleSheet(loginbtn);

   QPixmap pixmap("C:/Users/HP/Documents/att/pic2.png");  // Load the c logo
   int newWidthHeigt = 50; // Desired width
   //int newHeight = 40; // Desired height
   //QPixmap scaledPixmap = pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);  // Scale the pixmap
  imageLabel->setPixmap(pixmap);  // Set the scaled pixmap on the label
   imageLabel->setGeometry(55, 19,  newWidthHeigt,  newWidthHeigt); // Position and size the label

   //imageLabel->setStyleSheet("transform:scale(2);");
    connect(attendanceEntryButton, &QPushButton::clicked, this, &MainWindow::openPinCodeWindow);
    connect(adminLoginButton, &QPushButton::clicked, this, &MainWindow::openLoginWindow);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDateTime);
    timer->start(1000); // Update every second
    updateDateTime();
    // Set the size of the main window
    setFixedSize(700, 500); // Width: 800, Height: 600
    setWindowTitle("ATTENDER");
}

MainWindow::~MainWindow() {}

void MainWindow::paintEvent(QPaintEvent *event) {
    QMainWindow::paintEvent(event);

    QPainter painter(this);

    // Set the pen and brush for the painter
    QPen pen(QColor("#C79EF0"), 0.0000001); // Black pen with width 2
    painter.setPen(pen);
    QBrush brush(QColor("#C79EF0")); // Blue brush
    painter.setBrush(brush);

    // Draw a circle
    painter.drawEllipse(350, 50,636,636); // x, y, width, height
}

void MainWindow::openPinCodeWindow() {
    PinCodeWindow *pinCodeWindow = new PinCodeWindow();
    pinCodeWindow->show();
}

void MainWindow::openLoginWindow() {
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
}
void MainWindow::updateDateTime() {
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd\nh:mm:ss AP");
    time->setText(currentDateTime);
}
