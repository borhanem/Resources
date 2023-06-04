#ifndef USERCLASS_H
#define USERCLASS_H

//#include <QObject>
#include <QCoreApplication>
#include <QDebug>

class userClass
{
//    Q_OBJECT

public:
//    explicit userClass(QObject *parent = nullptr);
    userClass();
    QString firstName;
    QString lastName;
    QString userName;
    QString passWord;
    QString token;
    QString latestGroupNames;
    QString latestChannelNames;


};

#endif // USERCLASS_H
