#include "ChangePasswordWindow.h"
#include <QVBoxLayout>
extern QString winstyle;
ChangePasswordWindow::ChangePasswordWindow(QWidget *parent)
    : QWidget(parent),
    usernameEdit(new QLineEdit(this)),
    currentPasswordEdit(new QLineEdit(this)),
    newPasswordEdit(new QLineEdit(this)),
    confirmPasswordEdit(new QLineEdit(this)),
    headLabel1(new QLabel("C H A N G E  P A S S W O R D", this)),
    label1(new QLabel("USERNAME", this)),
    label2(new QLabel("CURRENT PASSWORD", this)),
    label3(new QLabel("NEW PASSWORD", this)),
    label4(new QLabel("CONFIRM PASSWORD", this)),
    imageLabel(new QLabel(this)),
    imageLabel1(new QLabel(this)),
    changePasswordButton(new QPushButton("Change Password", this)) {
    // this->setObjectName("mainWindow");
    this->setStyleSheet(winstyle);
    run();//All layout are here.....defined at last of this file
    // QVBoxLayout *layout = new QVBoxLayout(this);
    // usernameEdit->setPlaceholderText("Enter Username");
    // currentPasswordEdit->setPlaceholderText("Enter Current Password");
    currentPasswordEdit->setEchoMode(QLineEdit::Password);
    // newPasswordEdit->setPlaceholderText("Enter New Password");
    newPasswordEdit->setEchoMode(QLineEdit::Password);
   // confirmPasswordEdit->setPlaceholderText("Confirm New Password");
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    QPixmap pixmap1("C:/Users/HP/Documents/att/pic2.png");  // Load the c logo
    int newWidthHeigt = 50; // Desired width
    //int newHeight = 40; // Desired height
    //QPixmap scaledPixmap = pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);  // Scale the pixmap
    imageLabel1->setPixmap(pixmap1);  // Set the scaled pixmap on the label
    imageLabel1->setGeometry(20, 10,  newWidthHeigt,  newWidthHeigt); // Position and size the label
    // layout->addWidget(usernameEdit);
    // layout->addWidget(currentPasswordEdit);
    // layout->addWidget(newPasswordEdit);
    // layout->addWidget(confirmPasswordEdit);
    // layout->addWidget(changePasswordButton);

    connect(changePasswordButton, &QPushButton::clicked, this, &ChangePasswordWindow::onChangePasswordButtonClicked);

    //setLayout(layout);
    setWindowTitle("Change Password");
    setFixedSize(400,320);
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
void ChangePasswordWindow::run(){
    headLabel1->setGeometry(75,20,250,25);
    headLabel1->setStyleSheet("font-size: 18px; font-weight:600;color:#FFFFFF; background-color:transparent;");
    label1->setGeometry(85,60,183,11);
    label2->setGeometry(85,110,183,11);
    label3->setGeometry(85,160,183,11);
    label4->setGeometry(85,210,183,11);
    label1->setStyleSheet(labelstyle);
    label2->setStyleSheet(labelstyle);
    label3->setStyleSheet(labelstyle);
    label4->setStyleSheet(labelstyle);
    changePasswordButton->setGeometry(164,270,115,34);
    usernameEdit->setGeometry(85,76,190,25);
    currentPasswordEdit->setGeometry(85,126,190,25);
    newPasswordEdit->setGeometry(85,176,190,25);
    confirmPasswordEdit->setGeometry(85,226,190,25);
    usernameEdit->setStyleSheet(inputstyle);
    currentPasswordEdit->setStyleSheet(inputstyle);
   newPasswordEdit->setStyleSheet(inputstyle);
    confirmPasswordEdit->setStyleSheet(inputstyle);
    changePasswordButton->setStyleSheet(loginbtn);
    QPixmap pixmap("C:/Users/HP/Documents/att/pic4.png");
    //int newWidthHeigt = 50; // Desired width
    imageLabel->setPixmap(pixmap);  // Set the scaled pixmap on the label
    imageLabel->setGeometry(255, -60, 298, 344); // Position and size the label
    imageLabel->setStyleSheet("background-color:transparent;");
}
