#include "AdminWindow.h"
#include "MainWindow.h"
extern QString admbtn,admbtn1,removeback,winstyle;
AdminWindow::AdminWindow(const QString &username, QWidget *parent)
    : QWidget(parent),
    addStudentButton(new QPushButton("ADD STUDENT", this)),
    viewAttendanceDetailButton(new QPushButton("VIEW DETAILS", this)),
    changeLoginPasswordButton(new QPushButton("CHANGE PASSWORD", this)),
    headingLabel(new QLabel("A D M I N  W I N D O W", this)),
    label1(new QLabel("STUDENT", this)),
    label2(new QLabel("AUTH", this)),
    imageLabel(new QLabel(this)),
    imageLabel1(new QLabel(this)),
    imageLabel2(new QLabel(this)),
    imageLabel3(new QLabel(this)),
    imageLabel4(new QLabel(this)),
    imageLabel5(new QLabel(this)),
    imageLabel6(new QLabel(this)),
    logoutButton(new QPushButton("LOGOUT", this)),
    m_username(username)
    {  // Initialize member variable
    //this->setObjectName("mainWindow");
    this->setStyleSheet(winstyle);

    run();//All styles are here
    connect(addStudentButton, &QPushButton::clicked, this, &AdminWindow::openAddStudentWindow);
    connect(viewAttendanceDetailButton, &QPushButton::clicked, this, &AdminWindow::openViewAttendanceWindow);
    connect(changeLoginPasswordButton, &QPushButton::clicked, this, &AdminWindow::openChangePasswordWindow);
    connect(logoutButton, &QPushButton::clicked, this, &AdminWindow::logout);

    //setLayout(layout);
    setFixedSize(400, 320);
    setWindowTitle("Admin Functions");
}

void AdminWindow::openAddStudentWindow() {
    AddStudentWindow *addStudentWindow = new AddStudentWindow();
    addStudentWindow->show();
}

void AdminWindow::openViewAttendanceWindow() {
    ViewAttendanceWindow *viewAttendanceWindow = new ViewAttendanceWindow();
    viewAttendanceWindow->show();
}
void AdminWindow::openChangePasswordWindow(){
    ChangePasswordWindow *changePasswordWindow=new ChangePasswordWindow();
    changePasswordWindow->show();
}
void AdminWindow::logout() {
    QMessageBox::information(this, "Logout", "Logged Out Successfully");
    this->close();  // Close the AdminWindow
}
void AdminWindow::run(){
    headingLabel->setGeometry(162,17,70,20);
    headingLabel->setStyleSheet("font-size: 16px; font-weight:600;color:#FFFFFF; background-color:transparent;");
    addStudentButton->setGeometry(32,139,119,28);
    addStudentButton->setStyleSheet(admbtn);
    viewAttendanceDetailButton->setGeometry(32,178,119,28);
    viewAttendanceDetailButton->setStyleSheet(admbtn);
    changeLoginPasswordButton->setGeometry(239,139,119,28);
    changeLoginPasswordButton->setStyleSheet(admbtn1);
    logoutButton->setGeometry(239,178,119,28);
    logoutButton->setStyleSheet(admbtn1);
    changeLoginPasswordButton->raise();
    logoutButton->raise();
    QPixmap pixmap("C:/Users/HP/Documents/att/pic4.png");
    //int newWidthHeigt = 50; // Desired width
    imageLabel->setPixmap(pixmap);  // Set the scaled pixmap on the label
    imageLabel->setGeometry(255, -60, 298, 344); // Position and size the label
    imageLabel->setStyleSheet("background-color:transparent;");
    QPixmap pixmap1("C:/Users/HP/Documents/att/pic2.png");  // Load the c logo
    int newWidthHeigt = 50; // Desired width
    //int newHeight = 40; // Desired height
    //QPixmap scaledPixmap = pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);  // Scale the pixmap
    imageLabel1->setPixmap(pixmap1);  // Set the scaled pixmap on the label
    imageLabel1->setGeometry(20, 10,  newWidthHeigt,  newWidthHeigt); // Position and size the label
    QPixmap pixmap2("C:/Users/HP/Documents/att/pic5.png");//rectangle
    QPixmap pixmap3("C:/Users/HP/Documents/att/pic6.png");//studentlogo
    QPixmap pixmap4("C:/Users/HP/Documents/att/pic7.png");//lock logo
    QPixmap pixmap5("C:/Users/HP/Documents/att/pic8.png");//line
    imageLabel6->setPixmap(pixmap5);
    imageLabel6->setGeometry(191,77,3,182);
    imageLabel2->setPixmap(pixmap2);
    imageLabel2->setGeometry(24,96,133,145);
    imageLabel4->setPixmap(pixmap2);
    imageLabel4->setGeometry(232,96,133,145);
    imageLabel2->lower();//used as Z-index
    imageLabel4->lower();
    imageLabel3->setPixmap(pixmap3);
    imageLabel3->setStyleSheet(removeback);
    imageLabel5->setStyleSheet(removeback);
    imageLabel3->setGeometry(58,108,15,16);
    imageLabel5->setPixmap(pixmap4);
    imageLabel5->setGeometry(266,108,15,16);
    label1->setGeometry(78,109,45,12);
    label1->setStyleSheet("font-size: 10px; background-color:transparent;");
    label2->setStyleSheet("font-size: 10px;background-color:transparent;");
    label2->setGeometry(286,109,27,12);
    // QVBoxLayout *layout = new QVBoxLayout(this);
    // layout->addWidget(addStudentButton);
    // layout->addWidget(viewAttendanceDetailButton);
    // layout->addWidget(changeLoginPasswordButton);
    // layout->addWidget(logoutButton);
}
