#ifndef PASSWORD_H
#define PASSWORD_H
#include <QString>
#include <QFile>
#include <QDataStream>
struct login
{
    QString userName;
    QString password;
    void save(QDataStream &out) const {
        out << userName << password;
    }

    void load(QDataStream &in) {
        in >>userName >> password;
    }

};
#endif // PASSWORD_H
