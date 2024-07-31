#ifndef PINCODEWINDOW_H
#define PINCODEWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDateTime>
#include <QMessageBox>
#include<QDebug>
#include<QLabel>
#include "Student.h"
#include"style.h"
#include"Attendance.h"

struct AttendanceRecord {
    QString rollNumber;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

class PinCodeWindow : public QWidget {
    Q_OBJECT
public:
    explicit PinCodeWindow(QWidget *parent = nullptr);

private slots:
    void onSubmitButtonClicked();

private:
    QLineEdit *pinCodeEdit;
    QPushButton *submitButton;
    QLabel *headingLabel,*label1,*imageLabel,*imageLabel1;

    bool findStudentByPin(const QString &pinCode, QString &rollNumber, QString &name);
    bool isattendanceexist(const QString &rollNumber);
    void saveAttendanceRecord(const QString &rollNumber,const QString &name);
};

#endif // PINCODEWINDOW_H
