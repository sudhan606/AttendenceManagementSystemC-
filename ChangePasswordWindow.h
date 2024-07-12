#ifndef CHANGEPASSWORDWINDOW_H
#define CHANGEPASSWORDWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDataStream>
#include "Password.h"

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

    bool authenticateUser(const QString &username, const QString &password);
    void saveNewPassword(const QString &newPassword);
};

#endif // CHANGEPASSWORDWINDOW_H
