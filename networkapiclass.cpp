#include "networkapiclass.h"
#include "userclass.h"


networkApiClass::networkApiClass(QString argUsername, QString argPassword, QString argCommand)
{
    userName = argUsername;
    passWord = argPassword;
    command = argCommand;
}

networkApiClass::~networkApiClass()
{

}

void networkApiClass::urlMaker()
{
    int commandNumber = -1;
    QString commandArray[] = {"signup","login","logout"};
    for(int i = 0 ; i < command.size() ; ++i){
        if(commandArray[i] == command){
            commandNumber = i;
        }
    }
    if(commandNumber == -1){
        // close program implement later
    }
    if(command != ' '){
        QString API = "http://api.barafardayebehtar.ml:8080/" + command + '?';
        switch (commandNumber){
        case 0:
            if(firstName == ""){
                API += "username=" + userName + '&' + "password=" +passWord;
            }else{
                API += "username=" + userName + '&' + "password=" +passWord + '&' +"firstname=" + firstName + '&' + "lastname=" + lastName;
            }
            break;
        case 1:
            API += API += "username=" + userName + '&' + "password=" +passWord;
            break;
        case 2:
            API += API += "username=" + userName + '&' + "password=" +passWord;
            break;
        }

        urlApi = API;
    } else {
        qInfo() << "\nCommand Invalid\n";
    }
}

void networkApiClass::httpRequest()
{
    urlMaker();
    QUrl url(urlApi); // The API endpoint to request
//    QUrl url("http://api.barafardayebehtar.ml:8080/signup?username=asghar320&password=1234");
    QNetworkAccessManager manager;

    QNetworkReply *reply = manager.get(QNetworkRequest(url)); // Send GET request

    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            // If the request was successful, read the response
            QByteArray data = reply->readAll();
            qDebug() << "Response:" << data;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
            QJsonObject jsonObj = jsonDoc.object();

            double userId = jsonObj.value("userId").toDouble();
            QString title = jsonObj.value("title").toString();
            qDebug() << "User ID:" << userId << ", title: " << title << Qt::endl;
        } else {
            // If there was an error, display the error message
            qDebug() << "Error:" << reply->errorString();
        }

        // Cleanup the reply object and exit the application
        reply->deleteLater();
//        app.exit();
    });
    exec();
}

void networkApiClass::run()
{
    httpRequest();
}
