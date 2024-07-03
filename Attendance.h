#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <QString>
#include <QDateTime>
#include <QDataStream>

struct Attendance {
    QString rollNumber;
    int hrs,min,sec,year,mon,day;


    void save(QDataStream &out) const {
        out << rollNumber<<year<<mon<<day<<hrs<<min<<sec ;
    }

    void load(QDataStream &in) {
        in >> rollNumber>>year>>mon>>day>>hrs>>min>>sec ;
    }
};

#endif // ATTENDANCE_H
