#ifndef ADDSTUDENTWINDOW_H
#define ADDSTUDENTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include "Student.h"
#include<QLabel>
#include "style.h"
extern QString winstyle;
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
     QLabel *headLabel1;
    QLabel *label1;
     QLabel *label2;
     QLabel *label3;
      QLabel *label4;
     QLabel *imageLabel,*imageLabel1;
    bool isStudentExists(const QString &rollNumber, const QString &uniquePinCode);
    void saveStudent(const Student &student);
};

#endif // ADDSTUDENTWINDOW_H
