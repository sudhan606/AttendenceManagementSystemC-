#include "PinCodeWindow.h"
#include <QFile>
#include <QDataStream>

PinCodeWindow::PinCodeWindow(QWidget *parent)
    : QWidget(parent),
    pinCodeEdit(new QLineEdit(this)),
    submitButton(new QPushButton("Submit", this)) {

    QVBoxLayout *layout = new QVBoxLayout(this);
    pinCodeEdit->setPlaceholderText("Enter Pin Code");
    pinCodeEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(pinCodeEdit);
    layout->addWidget(submitButton);

    setLayout(layout);
    resize(300, 200);
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
