#ifndef ADDSTUDENTWINDOW_H
#define ADDSTUDENTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include "Student.h"

class AddStudentWindow : public QWidget {
    Q_OBJECT

public:
    AddStudentWindow(QWidget *parent = nullptr);

private slots:
    void onSaveButtonClicked();

private:
    QLineEdit *nameEdit;
    QLineEdit *rollNumberEdit;
    QLineEdit *addressEdit;
    QLineEdit *uniquePinCodeEdit;
    QPushButton *saveButton;
    bool isStudentExists(const QString &rollNumber, const QString &uniquePinCode);
    void saveStudent(const Student &student);
};

#endif // ADDSTUDENTWINDOW_H
