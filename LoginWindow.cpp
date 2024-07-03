#include "LoginWindow.h"
#include <QMessageBox>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent),
    usernameEdit(new QLineEdit(this)),
    passwordEdit(new QLineEdit(this)),
    loginButton(new QPushButton("Login", this)),
    adminWindow(nullptr) {

    QVBoxLayout *layout = new QVBoxLayout(this);
    usernameEdit->setPlaceholderText("Enter Username");
    passwordEdit->setPlaceholderText("Enter Password");
    passwordEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);

    setLayout(layout);
    resize(300, 200);
    setWindowTitle("Admin Login");
}

void LoginWindow::onLoginButtonClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (username == "p" && password == "p") {
        if (!adminWindow) {
            adminWindow = new AdminWindow(username);
        }
        adminWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
