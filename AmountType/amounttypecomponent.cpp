#include "amounttypecomponent.h"
#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

AmountTypeComponent::AmountTypeComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &AmountTypeComponent::_finished);
}

void AmountTypeComponent::fetchAmountTypes(AmountTypeList *atList)
{
    mList = atList;

    QString url = "http://localhost:9000/amounttypes/";

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void AmountTypeComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {
        QJsonDocument doc = QJsonDocument::fromJson(arr);

        QJsonArray jsonArr = doc.array();



        foreach (const QJsonValue &value, jsonArr) {
            QJsonObject obj = value.toObject();


            mList->appendItem({obj["idAmountType"].toInt(), obj["type"].toString()});
        }
    }
}
