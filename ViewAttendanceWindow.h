#ifndef VIEWATTENDANCEWINDOW_H
#define VIEWATTENDANCEWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "Student.h"
#include "Attendance.h"
#include <QDebug>
#include<QLabel>
#include<QComboBox>
#include"style.h"
class ViewAttendanceWindow : public QWidget {
    Q_OBJECT
public:
    explicit ViewAttendanceWindow(QWidget *parent = nullptr);

private slots:
    void onViewButtonClicked();

private:
    QLineEdit *rollNumberEdit,*yearEdit;
    QPushButton *viewButton;
    QLabel *headingLabel,*label1,*label2,*label3,*imageLabel,*imageLabel1;
    QComboBox *comboBox;
    bool readStudentDetails(const QString &rollNumber, Student &student, Attendance &attendance);
};

#endif // VIEWATTENDANCEWINDOW_H
