#include "AddStudentWindow.h"
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

AddStudentWindow::AddStudentWindow(QWidget *parent)
    : QWidget(parent),
    headLabel1(new QLabel("A D D  S T U D E N T", this)),
    label1(new QLabel("NAME", this)),
    label2(new QLabel("ROLL NO", this)),
    label3(new QLabel("ADDRESS", this)),
    label4(new QLabel("UNIQUE PIN CODE", this)),
    nameEdit(new QLineEdit(this)),
    rollNumberEdit(new QLineEdit(this)),
    addressEdit(new QLineEdit(this)),
    uniquePinCodeEdit(new QLineEdit(this)),
    saveButton(new QPushButton("Save", this)) {
    this->setStyleSheet("background-color:#051A50; color:#FFFFFF;");
    QString labelstyle="font-size: 9px; font-weight:600;color:#FFFFFF; background-color:transparent;";
    QString inputstyle="background-color:#030E2C; border-radius:0px;padding: 5px;font-size: 12px; color: #FFFFF;";
   // QVBoxLayout *layout = new QVBoxLayout(this);
    // nameEdit->setPlaceholderText("Enter Student Name");
    // rollNumberEdit->setPlaceholderText("Enter Student Roll Number");
    // addressEdit->setPlaceholderText("Enter Student Address");
    // uniquePinCodeEdit->setPlaceholderText("Enter Unique Pin Code");
    // layout->addWidget(nameEdit);
    // layout->addWidget(rollNumberEdit);
    // layout->addWidget(addressEdit);
    // layout->addWidget(uniquePinCodeEdit);
    // layout->addWidget(saveButton);
    headLabel1->setGeometry(125,21,150,21);
    headLabel1->setStyleSheet("font-size: 12px; font-weight:600;color:#FFFFFF; background-color:transparent;");
    label1->setGeometry(59,60,183,11);
    label2->setGeometry(59,110,183,11);
    label3->setGeometry(59,160,183,11);
    label4->setGeometry(59,210,183,11);
    label1->setStyleSheet(labelstyle);
    label2->setStyleSheet(labelstyle);
    label3->setStyleSheet(labelstyle);
    label4->setStyleSheet(labelstyle);
    saveButton->setGeometry(208,270,111,34);
    nameEdit->setGeometry(59,76,190,25);
    rollNumberEdit->setGeometry(59,126,190,25);
    addressEdit->setGeometry(59,176,190,25);
    uniquePinCodeEdit->setGeometry(59,226,190,25);
    nameEdit->setStyleSheet(inputstyle);
    rollNumberEdit->setStyleSheet(inputstyle);
    addressEdit->setStyleSheet(inputstyle);
    uniquePinCodeEdit->setStyleSheet(inputstyle);
    saveButton->setStyleSheet(loginbtn);
    connect(saveButton, &QPushButton::clicked, this, &AddStudentWindow::onSaveButtonClicked);

   // setLayout(layout);
    setFixedSize(400, 320);
    setWindowTitle("Add Student");
}

void AddStudentWindow::onSaveButtonClicked() {
    QString name = nameEdit->text().trimmed();
    QString rollNumber = rollNumberEdit->text().trimmed();
    QString address = addressEdit->text().trimmed();
    QString uniquePinCode = uniquePinCodeEdit->text().trimmed();

    if (name.isEmpty() || rollNumber.isEmpty() || address.isEmpty() || uniquePinCode.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required.");
        return;
    }

    if (isStudentExists(rollNumber, uniquePinCode)) {
        QMessageBox::warning(this, "Duplicate Entry", "Student with the same Roll Number or Unique Pin Code already exists.");
        return;
    }

    Student student;
    student.name = name;
    student.rollNumber = rollNumber;
    student.address = address;
    student.uniquePinCode = uniquePinCode;

    saveStudent(student);

    QMessageBox::information(this, "Success", "Student information saved successfully.");
    this->close();
}

bool AddStudentWindow::isStudentExists(const QString &rollNumber, const QString &uniquePinCode) {
    QFile file("students.dat");
    if (!file.open(QIODevice::ReadOnly)) {
        return false; // Assuming file does not exist means no duplicates
    }

    QDataStream in(&file);
    while (!in.atEnd()) {
        Student tempStudent;
        tempStudent.load(in);
        if (tempStudent.rollNumber == rollNumber || tempStudent.uniquePinCode == uniquePinCode) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void AddStudentWindow::saveStudent(const Student &student) {
    QFile file("students.dat");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::warning(this, "File Error", "Unable to open file for writing.");
        return;
    }

    QDataStream out(&file);
    student.save(out);
    file.close();
}
