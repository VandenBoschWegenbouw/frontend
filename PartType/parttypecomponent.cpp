#include "parttypecomponent.h"

#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
PartTypeComponent::PartTypeComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &PartTypeComponent::_finished);
}

void PartTypeComponent::fetchPartTypes(PartTypeList *ptList)
{
    mList = ptList;

    QString url = "http://localhost:9000/parttypes/";

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void PartTypeComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {
        QJsonDocument doc = QJsonDocument::fromJson(arr);

        QJsonArray jsonArr = doc.array();

        foreach (const QJsonValue &value, jsonArr) {
            QJsonObject obj = value.toObject();

            mList->appendItem({obj["idPartType"].toInt(), obj["type"].toString()});
        }
    }
}
