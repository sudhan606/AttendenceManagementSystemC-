#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QFile>
#include <QDataStream>

struct Student {
    QString name;
    QString rollNumber;
    QString address;
    QString uniquePinCode;

    void save(QDataStream &out) const {
        out << name << rollNumber << address << uniquePinCode;
    }

    void load(QDataStream &in) {
        in >> name >> rollNumber >> address >> uniquePinCode;
    }

    // Static method to store and retrieve current student
    static Student &currentStudent() {
        static Student instance;
        return instance;
    }
};

#endif // STUDENT_H
