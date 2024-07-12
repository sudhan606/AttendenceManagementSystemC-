#include "LoginWindow.h"
#include <QMessageBox>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent),
    heading(new QLabel("L O G I N",this)),
    label1(new QLabel("USERNAME",this)),
    label2(new QLabel("PASSWORD",this)),
    imageLabel(new QLabel(this)),
    usernameEdit(new QLineEdit(this)),
    passwordEdit(new QLineEdit(this)),
    loginButton(new QPushButton("Login", this)),
    adminWindow(nullptr) {
    this->setStyleSheet("background-color:#051A50; color:#FFFFFF;");
   // QVBoxLayout *layout = new QVBoxLayout(this);
    //usernameEdit->setPlaceholderText("Enter Username");
    // passwordEdit->setPlaceholderText("Enter Password");
    passwordEdit->setEchoMode(QLineEdit::Password);
   heading->setGeometry(130,21,175,25);
   heading->setStyleSheet("font-size: 18px; font-weight:600;color:#FFFFFF; background-color:transparent;");
   label1->setGeometry(85,100,183,11);
   label2->setGeometry(85,150,183,11);
   usernameEdit->setGeometry(85,116,190,25);
  passwordEdit->setGeometry(85,166,190,25);
   label1->setStyleSheet(labelstyle);
   label2->setStyleSheet(labelstyle);
   usernameEdit->setStyleSheet(inputstyle);
   passwordEdit->setStyleSheet(inputstyle);
  loginButton->setGeometry(164,200,111,34);
     loginButton->setStyleSheet(loginbtn);
  QPixmap pixmap("C:/Users/HP/Documents/att/pic4.png");
  //int newWidthHeigt = 50; // Desired width
  imageLabel->setPixmap(pixmap);  // Set the scaled pixmap on the label
  imageLabel->setGeometry(255, -60, 298, 344); // Position and size the label
  imageLabel->setStyleSheet("background-color:transparent;");
    // layout->addWidget(usernameEdit);
    // layout->addWidget(passwordEdit);
    // layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);

    //setLayout(layout);
    setFixedSize(400, 320);
    setWindowTitle("Admin Login");
}

void LoginWindow::onLoginButtonClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (authenticateUser(username,password)) {// authenticateUser(username,password)
        if (!adminWindow) {
            adminWindow = new AdminWindow(username);
        }
        adminWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
bool LoginWindow::authenticateUser(QString &username, QString &password){
    QFile file("password.dat");
    if (!file.open(QIODevice::ReadOnly)) {
        return false; // Assuming file does not exist means no duplicates
    }

    QDataStream in(&file);
    login tempLogin;
    tempLogin.load(in);
    qDebug()<<tempLogin.userName<<tempLogin.password;
        if(tempLogin.userName==username&&tempLogin.password==password)
    {
        file.close();
            return true;
    }
        file.close();
        return false;
}
