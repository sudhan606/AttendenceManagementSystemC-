#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "AdminWindow.h"
#include "Password.h"
#include<QDebug>
#include"style.h"

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);

private slots:
    void onLoginButtonClicked();

private:
    QLabel *heading;
    QLabel *label1,*label2,*imageLabel;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    AdminWindow *adminWindow;
    bool authenticateUser(QString &username, QString &password);
};

#endif // LOGINWINDOW_H
