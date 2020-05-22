#include "logincomponent.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <loginhandler.h>


QNetworkAccessManager manager;

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

    qDebug() << doc.toJson().toHex();

    QNetworkRequest request(QUrl("http://localhost:9000/users/login"));
    request.setRawHeader("Content-Type", "application/json");

    manager.post(request,doc.toJson());
}

void LoginComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    arr.size() > 0 ? emit correctLogin() : emit incorrectLogin();
}
