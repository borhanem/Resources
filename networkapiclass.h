#ifndef NETWORKAPICLASS_H
#define NETWORKAPICLASS_H

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include "userclass.h"

class networkApiClass : private userClass,public QThread
{
    int exitCommand;
    QString exitString;
    QString urlApi;
    QString command;

public:
    networkApiClass(QString argUsername,QString argPassword,QString argCommand);
    ~networkApiClass();
    void urlMaker();
    void httpRequest();
private:
    void run();

};

#endif // NETWORKAPICLASS_H
