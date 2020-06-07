#include "logincomponent.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <Login/loginhandler.h>
#include <Structs/UserStruct.h>


UserStruct LoginComponent::user;

LoginComponent::LoginComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &LoginComponent::_finished);

}

void LoginComponent::login(LoginStruct user)
{
    QJsonObject obj;

    obj["password"] = QString(QCryptographicHash::hash(user.password.toUtf8(), QCryptographicHash::Sha256).toHex());
    obj["username"] = user.username;

    QJsonDocument doc(obj);


    QNetworkRequest request(QUrl("http://51.75.133.79:9000/users/login"));
    request.setRawHeader("Content-Type", "application/json");

    manager.post(request,doc.toJson());
}

void LoginComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();


    if (arr.size() > 0) {

        QJsonDocument doc = QJsonDocument::fromJson(arr);
        QJsonObject obj = doc.object();

        LoginComponent::user = {obj["idUser"].toInt(), obj["username"].toString(), obj["password"].toString(), obj["isAdmin"].toBool()};

        if (user.admin) {
            emit correctAdminLogin();
        } else {
            emit correctLogin();
        }


    } else {
        //emit correctLogin();
        emit incorrectLogin();
    }

}
