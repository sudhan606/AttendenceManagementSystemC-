#include "AddStudentWindow.h"
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

AddStudentWindow::AddStudentWindow(QWidget *parent)
    : QWidget(parent),
    nameEdit(new QLineEdit(this)),
    rollNumberEdit(new QLineEdit(this)),
    addressEdit(new QLineEdit(this)),
    uniquePinCodeEdit(new QLineEdit(this)),
    saveButton(new QPushButton("Save", this)) {

    QVBoxLayout *layout = new QVBoxLayout(this);
    nameEdit->setPlaceholderText("Enter Student Name");
    rollNumberEdit->setPlaceholderText("Enter Student Roll Number");
    addressEdit->setPlaceholderText("Enter Student Address");
    uniquePinCodeEdit->setPlaceholderText("Enter Unique Pin Code");
    layout->addWidget(nameEdit);
    layout->addWidget(rollNumberEdit);
    layout->addWidget(addressEdit);
    layout->addWidget(uniquePinCodeEdit);
    layout->addWidget(saveButton);

    connect(saveButton, &QPushButton::clicked, this, &AddStudentWindow::onSaveButtonClicked);

    setLayout(layout);
    resize(300, 200);
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
