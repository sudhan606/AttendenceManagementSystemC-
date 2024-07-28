#include "ViewAttendanceWindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include <iomanip>
#define attn 100;
extern QString winstyle1;
ViewAttendanceWindow::ViewAttendanceWindow(QWidget *parent)
    : QWidget(parent),
    headingLabel(new QLabel("V I E W  A T T E N D A N C E", this)),
    label1(new QLabel("ENTER ROLL NUMBER", this)),
    label2(new QLabel("SELECT MONTH", this)),
    label3(new QLabel("ENTER YEAR", this)),
    rollNumberEdit(new QLineEdit(this)),
    yearEdit(new QLineEdit(this)),
    imageLabel(new QLabel(this)),
    imageLabel1(new QLabel(this)),
    comboBox(new QComboBox(this)),
    viewButton(new QPushButton("VIEW", this)) {
    QString month[13]={"Select Month","January","February","March","April","May","June","July","August","September","October","November","December"};
    this->setStyleSheet(winstyle1);
    headingLabel->setGeometry(85,20,250,25);
    headingLabel->setStyleSheet("font-size: 18px; font-weight:600;color:#FFFFFF; background-color:transparent;");
    label1->setGeometry(85,80,183,11);
    label2->setGeometry(85,180,183,11);
    label3->setGeometry(85,130,183,11);
    yearEdit->setGeometry(85,146,190,25);
    rollNumberEdit->setGeometry(85,96,190,25);
    label1->setStyleSheet(labelstyle);
    label2->setStyleSheet(labelstyle);
    label3->setStyleSheet(labelstyle);
    rollNumberEdit->setStyleSheet(inputstyle);
    yearEdit->setStyleSheet(inputstyle);
    viewButton->setGeometry(164,250,111,34);
    viewButton->setStyleSheet(loginbtn);
    viewButton->raise();
    comboBox->setGeometry(85,205,190,30);
    comboBox->setStyleSheet(inputstyle);
    for(int i=0;i<13;i++){
        comboBox->addItem(month[i]);
    }
    comboBox->setItemData(0, false, Qt::ItemIsEnabled); // Disable "Select month"
    qDebug()<<comboBox->currentIndex();
    QPixmap pixmap("C:/Users/HP/Documents/att/pic4.png");
    //int newWidthHeigt = 50; // Desired width
    imageLabel->setPixmap(pixmap);  // Set the scaled pixmap on the label
    imageLabel->setGeometry(255, -60, 298, 344); // Position and size the label
    imageLabel->setStyleSheet("background-color:transparent;");
    QPixmap pixmap1("C:/Users/HP/Documents/att/pic2.png");  // Load the c logo
    int newWidthHeigt = 50; // Desired width
    imageLabel1->setPixmap(pixmap1);  // Set the scaled pixmap on the label
    imageLabel1->setGeometry(30, 10,  newWidthHeigt,  newWidthHeigt); // Position and size the label
    connect(viewButton, &QPushButton::clicked, this, &ViewAttendanceWindow::onViewButtonClicked);
    setFixedSize(400, 320);
    setWindowTitle("View Attendance Detail");
}

void ViewAttendanceWindow::onViewButtonClicked() {
    QString rollNumber = rollNumberEdit->text().trimmed();
    bool ok;
    qDebug()<<(yearEdit->text().trimmed()).length();
    int year=(yearEdit->text().trimmed()).toInt(&ok);
    // Trimmed to remove any extra spaces
    qDebug()<<year<<ok;
    int month = comboBox->currentIndex();

    if (rollNumber.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a roll number.");
        return;
    }
    if (!ok||(yearEdit->text().trimmed()).length()!=4) {
        QMessageBox::warning(this, "Input Error", "Please Enter Proper Year");
        return;
    }
    if (month==0) {
        QMessageBox::warning(this, "Input Error", "Please Select Month.");
        return;
    }

    Student student;
    Attendance attendance;
    QString dates;
    if (readStudentDetails(rollNumber, student, attendance)) {
        // Display student details
        int count=0;
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
                    if(tattendance.year==year&&tattendance.mon==month)
                    {
                        count++;
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
                }
                /*dates=QString("%1\n%2")
                            .arg(dates)
                            .arg(date);*/
            }
            qDebug()<<dates;

        }
        if(dates.isEmpty())
             QMessageBox::information(this, "Student Details", details+"\n\n Attendence Details:\n\nDates\t\tTimes\n\n   NO RECORDS FOUND");
        else{
            dates=dates+"\n\tTotal Attendance="+QString::number(count);
             QMessageBox::information(this, "Student Details", details+"\n\n Attendence Details:\n\nDates\t\tTimes\n\n"+dates);
        }
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
