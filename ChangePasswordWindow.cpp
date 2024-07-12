#include "ChangePasswordWindow.h"
#include <QVBoxLayout>

ChangePasswordWindow::ChangePasswordWindow(QWidget *parent)
    : QWidget(parent),
    usernameEdit(new QLineEdit(this)),
    currentPasswordEdit(new QLineEdit(this)),
    newPasswordEdit(new QLineEdit(this)),
    confirmPasswordEdit(new QLineEdit(this)),
    changePasswordButton(new QPushButton("Change Password", this)) {

    QVBoxLayout *layout = new QVBoxLayout(this);
    usernameEdit->setPlaceholderText("Enter Username");
    currentPasswordEdit->setPlaceholderText("Enter Current Password");
    currentPasswordEdit->setEchoMode(QLineEdit::Password);
    newPasswordEdit->setPlaceholderText("Enter New Password");
    newPasswordEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordEdit->setPlaceholderText("Confirm New Password");
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(usernameEdit);
    layout->addWidget(currentPasswordEdit);
    layout->addWidget(newPasswordEdit);
    layout->addWidget(confirmPasswordEdit);
    layout->addWidget(changePasswordButton);

    connect(changePasswordButton, &QPushButton::clicked, this, &ChangePasswordWindow::onChangePasswordButtonClicked);

    setLayout(layout);
    setWindowTitle("Change Password");
}

void ChangePasswordWindow::onChangePasswordButtonClicked() {
    QString username = usernameEdit->text().trimmed();
    QString currentPassword = currentPasswordEdit->text().trimmed();
    QString newPassword = newPasswordEdit->text().trimmed();
    QString confirmPassword = confirmPasswordEdit->text().trimmed();

    if (username.isEmpty() || currentPassword.isEmpty() || newPassword.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required.");
        return;
    }
    if (!authenticateUser(username, currentPassword)) {
        QMessageBox::warning(this, "Authentication Failed", "Invalid username or password.");
        return;
    }
    if (newPassword != confirmPassword) {
        QMessageBox::warning(this, "Password Mismatch", "New password and confirm password do not match.");
        return;
    }



    saveNewPassword(newPassword);

    QMessageBox::information(this, "Success", "Password changed successfully.");
    this->close();
}

bool ChangePasswordWindow::authenticateUser(const QString &username, const QString &password) {
    // Implement your authentication logic here, e.g., check against a database or hardcoded values
    // For demonstration purposes, let's assume username "admin" and password "admin" are valid
    QFile file("password.dat");
    if (!file.open(QIODevice::ReadOnly)) {
        return false; // Assuming file does not exist means no duplicates
    }

    QDataStream in(&file);
    login tempLogin;
    tempLogin.load(in);
    if(tempLogin.userName==username&&tempLogin.password==password)
    {
        file.close();
        return true;
    }
    file.close();
    return false;

}

void ChangePasswordWindow::saveNewPassword(const QString &newPassword) {
    // Implement code to save the new password, e.g., update database or file
    // For demonstration purposes, let's assume we update the password directly here
    // Note: In a real application, you should securely hash and store passwords
    login loginPassword;
    loginPassword.password=newPassword;
    loginPassword.userName="p";
    QFile file("password.dat");
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "File Error", "Unable to open file for writing.");
        return;
    }

    QDataStream out(&file);
    loginPassword.save(out);
    file.close();
}
