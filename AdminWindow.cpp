#include "AdminWindow.h"
#include "MainWindow.h"

AdminWindow::AdminWindow(const QString &username, QWidget *parent)
    : QWidget(parent),
    addStudentButton(new QPushButton("Add Student", this)),
    viewAttendanceDetailButton(new QPushButton("View Attendance Detail", this)),
    changeLoginPasswordButton(new QPushButton("Change Login Password", this)),
    logoutButton(new QPushButton("Logout", this)),
    m_username(username) {  // Initialize member variable

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(addStudentButton);
    layout->addWidget(viewAttendanceDetailButton);
    layout->addWidget(changeLoginPasswordButton);
    layout->addWidget(logoutButton);

    connect(addStudentButton, &QPushButton::clicked, this, &AdminWindow::openAddStudentWindow);
    connect(viewAttendanceDetailButton, &QPushButton::clicked, this, &AdminWindow::openViewAttendanceWindow);
    connect(logoutButton, &QPushButton::clicked, this, &AdminWindow::logout);

    setLayout(layout);
    resize(300, 200);
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
void AdminWindow::logout() {
    QMessageBox::information(this, "Logout", "Logged Out Successfully");
    this->close();  // Close the AdminWindow
}
