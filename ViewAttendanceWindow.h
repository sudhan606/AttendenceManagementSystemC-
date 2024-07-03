#ifndef VIEWATTENDANCEWINDOW_H
#define VIEWATTENDANCEWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "Student.h"
#include "Attendance.h"
#include <QDebug>

class ViewAttendanceWindow : public QWidget {
    Q_OBJECT
public:
    explicit ViewAttendanceWindow(QWidget *parent = nullptr);

private slots:
    void onViewButtonClicked();

private:
    QLineEdit *rollNumberEdit;
    QPushButton *viewButton;

    bool readStudentDetails(const QString &rollNumber, Student &student, Attendance &attendance);
};

#endif // VIEWATTENDANCEWINDOW_H
