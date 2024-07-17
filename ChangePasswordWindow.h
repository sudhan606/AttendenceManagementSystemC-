#ifndef CHANGEPASSWORDWINDOW_H
#define CHANGEPASSWORDWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDataStream>
#include "Password.h"
#include"style.h"
#include<QLabel>

class ChangePasswordWindow : public QWidget {
    Q_OBJECT

public:
    ChangePasswordWindow(QWidget *parent = nullptr);

private slots:
    void onChangePasswordButtonClicked();

private:
    QLineEdit *usernameEdit;
    QLineEdit *currentPasswordEdit;
    QLineEdit *newPasswordEdit;
    QLineEdit *confirmPasswordEdit;
    QPushButton *changePasswordButton;
    QLabel *headLabel1;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *imageLabel, *imageLabel1;
    bool authenticateUser(const QString &username, const QString &password);
    void saveNewPassword(const QString &newPassword);
    void run();
};

#endif // CHANGEPASSWORDWINDOW_H
