#include "PinCodeWindow.h"
#include <QFile>
#include <QDataStream>

PinCodeWindow::PinCodeWindow(QWidget *parent)
    : QWidget(parent),
    pinCodeEdit(new QLineEdit(this)),
    headingLabel(new QLabel("E N T R Y", this)),
    label1(new QLabel("ENTER YOUR PIN", this)),
    imageLabel(new QLabel(this)),
    imageLabel1(new QLabel(this)),
    submitButton(new QPushButton("Submit", this))
{
    extern QString winstyle;
    this->setStyleSheet(winstyle);
    // QVBoxLayout *layout = new QVBoxLayout(this);
    // pinCodeEdit->setPlaceholderText("Enter Pin Code");
    pinCodeEdit->setEchoMode(QLineEdit::Password);
    headingLabel->setGeometry(140,30,175,25);
    headingLabel->setStyleSheet("font-size: 18px; font-weight:600;color:#FFFFFF; background-color:transparent;");
    label1->setGeometry(85,110,183,11);
    label1->setStyleSheet(labelstyle);
    pinCodeEdit->setGeometry(85,126,190,25);
    pinCodeEdit->setStyleSheet(inputstyle);
    submitButton->setGeometry(164,200,111,34);
    submitButton->setStyleSheet(loginbtn);
    QPixmap pixmap("C:/Users/HP/Documents/att/pic4.png");
    //int newWidthHeigt = 50; // Desired width
    imageLabel->setPixmap(pixmap);  // Set the scaled pixmap on the label
    imageLabel->setGeometry(255, -60, 298, 344); // Position and size the label
    imageLabel->setStyleSheet("background-color:transparent;");
    QPixmap pixmap1("C:/Users/HP/Documents/att/pic2.png");  // Load the c logo
    int newWidthHeigt = 50; // Desired width
    imageLabel1->setPixmap(pixmap1);  // Set the scaled pixmap on the label
    imageLabel1->setGeometry(30, 10,  newWidthHeigt,  newWidthHeigt); // Position and size the label
    // layout->addWidget(pinCodeEdit);
    // layout->addWidget(submitButton);

  //  setLayout(layout);
     setFixedSize(400, 320);
    setWindowTitle("Attendance Entry");

    connect(submitButton, &QPushButton::clicked, this, &PinCodeWindow::onSubmitButtonClicked);
}

void PinCodeWindow::onSubmitButtonClicked() {
    QString pinCode = pinCodeEdit->text().trimmed();

    QString rollNumber, name;
    if (findStudentByPin(pinCode, rollNumber, name)) {
        saveAttendanceRecord(rollNumber);
        QDateTime currentDateTime = QDateTime::currentDateTime();

        QMessageBox::information(this, "Attendance Recorded","Student Name: "+name+ "\nYou are present Today on:\nTime: "+QString::number(currentDateTime.time().hour())+":"+QString::number(currentDateTime.time().minute())+":"+QString::number(currentDateTime.time().second()));
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Invalid pin code. Student not found.");
    }
}

bool PinCodeWindow::findStudentByPin(const QString &pinCode, QString &rollNumber, QString &name) {
    QFile file("students.dat");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "File Error", "Failed to open students.dat file for reading.");
        return false;
    }

    QDataStream in(&file);
    while (!in.atEnd()) {
        Student student;
        student.load(in);
        if (student.uniquePinCode == pinCode) {
            rollNumber = student.rollNumber;
            name = student.name;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void PinCodeWindow::saveAttendanceRecord(const QString &rollNumber) {
    QFile file("attendance.dat");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::warning(this, "File Error", "Failed to open attendance.dat file for writing.");
        return;
    }

    QDateTime currentDateTime = QDateTime::currentDateTime();
    AttendanceRecord record;
    record.rollNumber = rollNumber;
    record.year = currentDateTime.date().year();
    record.month = currentDateTime.date().month();
    record.day = currentDateTime.date().day();
    record.hour = currentDateTime.time().hour();
    record.minute = currentDateTime.time().minute();
    record.second = currentDateTime.time().second();
    qDebug() << record.rollNumber << record.year << record.month << record.day << record.hour << record.minute << record.second;
    QDataStream out(&file);
    out << record.rollNumber << record.year << record.month << record.day << record.hour << record.minute << record.second;

    file.close();
}
