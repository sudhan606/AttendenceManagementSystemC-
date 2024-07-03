#include "ViewAttendanceWindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#define attn 100;
ViewAttendanceWindow::ViewAttendanceWindow(QWidget *parent)
    : QWidget(parent),
    rollNumberEdit(new QLineEdit(this)),
    viewButton(new QPushButton("View", this)) {

    QVBoxLayout *layout = new QVBoxLayout(this);
    rollNumberEdit->setPlaceholderText("Enter Student Roll Number");
    layout->addWidget(rollNumberEdit);
    layout->addWidget(viewButton);

    connect(viewButton, &QPushButton::clicked, this, &ViewAttendanceWindow::onViewButtonClicked);

    setLayout(layout);
    resize(300, 200);
    setWindowTitle("View Attendance Detail");
}

void ViewAttendanceWindow::onViewButtonClicked() {
    QString rollNumber = rollNumberEdit->text().trimmed();  // Trimmed to remove any extra spaces

    if (rollNumber.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a roll number.");
        return;
    }

    Student student;
    Attendance attendance;
    QString dates;
    if (readStudentDetails(rollNumber, student, attendance)) {
        // Display student details
        QString details = QString("Name: %1\nRoll Number: %2\nAddress: %3")
                              .arg(student.name)
                              .arg(student.rollNumber)
                              .arg(student.address);
       // QMessageBox::information(this, "Student Details", details);
        QFile file1("attendance.dat");
        if (!file1.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this, "File Error", "Unable to open file for reading.");
        }
        else{
            QDataStream in1(&file1);
            while (!in1.atEnd()) {
                Attendance tattendance;
                QString date;
                tattendance.load(in1);
                if (tattendance.rollNumber == rollNumber) {
                    date= QString("%1/%2/%3\t%4:%5:%6\n")
                            .arg(QString::number(tattendance.year))
                            .arg(QString::number(tattendance.mon))
                            .arg(QString::number(tattendance.day))
                               .arg(QString::number(tattendance.hrs))
                               .arg(QString::number(tattendance.min))
                               .arg(QString::number(tattendance.sec));
                    dates+=date;
                    //qDebug()<<date;
                }
                /*dates=QString("%1\n%2")
                            .arg(dates)
                            .arg(date);*/
            }
            qDebug()<<dates;

        }
        if(dates.isEmpty())
             QMessageBox::information(this, "Student Details", details+"\n\n Attendence Details:\n\nDates\t\tTimes\n\n   NO RECORDS FOUND");
        else
        QMessageBox::information(this, "Student Details", details+"\n\n Attendence Details:\n\nDates\t\tTimes\n\n"+dates);
    } else {
        QMessageBox::warning(this, "Not Found", "Student details not found.");
    }
}

bool ViewAttendanceWindow::readStudentDetails(const QString &rollNumber, Student &student, Attendance &attendance) {
    QFile file("students.dat");
    // QFile file1("attendance.dat");
    /*if (!file1.open(QIODevice::ReadOnly)){
         QMessageBox::warning(this, "File Error", "Unable to open file for reading.");
         return false;
     }*/
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "File Error", "Unable to open file for reading.");
        return false;
    }

    QDataStream in(&file);
    while (!in.atEnd()) {
        Student tempStudent;
        tempStudent.load(in);
        if (tempStudent.rollNumber == rollNumber) {
            student = tempStudent;
            file.close();
            return true;
        }
    }

    file.close();
    /*int i=0;
    QDataStream in1(&file1);
    while (!in1.atEnd()) {
        Attendance tattendance[100];
        tattendance[i].load(in1);
        if (tempStudent.rollNumber == rollNumber) {
            student = tempStudent;
            file.close();
            return true;
        }
    }

    file.close();*/
    return false;
}
