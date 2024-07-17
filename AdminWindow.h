#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "ViewAttendanceWindow.h"
#include "AddStudentWindow.h"
#include"ChangePasswordWindow.h"
#include "style.h"

class AdminWindow : public QWidget {
    Q_OBJECT

public:
    AdminWindow(const QString &username="", QWidget *parent = nullptr);


private slots:
    void openViewAttendanceWindow();
    void openAddStudentWindow();
    void openChangePasswordWindow();
    void logout();
    // Add other slots for handling different admin functions as required

private:
    QPushButton *addStudentButton;
    QPushButton *viewAttendanceDetailButton;
    QPushButton *changeLoginPasswordButton;
    QPushButton *logoutButton;
    QString m_username;  // Member variable to store username
    QLabel *headingLabel,*label1,*label2,*imageLabel,*imageLabel1,*imageLabel2,*imageLabel3,*imageLabel4,*imageLabel5,*imageLabel6;
};

#endif // ADMINWINDOW_H
