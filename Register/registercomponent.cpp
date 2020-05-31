#include "registercomponent.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

RegisterComponent::RegisterComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &RegisterComponent::_finished);
}

void RegisterComponent::registerUser(UserStruct user)
{
    QJsonObject obj;

    obj["username"] = user.username;
    obj["password"] = QString(QCryptographicHash::hash(user.password.toUtf8(), QCryptographicHash::Sha256).toHex());
    obj["isAdmin"] = user.admin;

    QJsonDocument doc(obj);

    QNetworkRequest request(QUrl("http://localhost:9000/users/register"));
    request.setRawHeader("Content-Type", "application/json");



    manager.post(request, doc.toJson());
}

void RegisterComponent::_finished(QNetworkReply *)
{

}
