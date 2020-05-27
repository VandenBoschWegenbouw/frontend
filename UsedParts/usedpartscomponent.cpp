#include "usedpartscomponent.h"

#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

UsedPartsComponent::UsedPartsComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &UsedPartsComponent::_finished);
}

void UsedPartsComponent::fetchUsedParts(UsedPartsList *list)
{
    mList = list;

    const QString url = "http://localhost:9000/partsused/"+QDate::currentDate().toString("yyyy-MM-dd");

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void UsedPartsComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {

        QJsonDocument doc = QJsonDocument::fromJson(arr);

        QJsonArray jsonArr = doc.array();

        mList->items().clear();

        qDebug() << arr;

        foreach (const QJsonValue &value, jsonArr) {
            QJsonObject obj = value.toObject();
            QJsonObject jsonPartType = obj["partType"].toObject();
            QJsonObject jsonAmountType = obj["amountType"].toObject();
            QJsonObject jsonProject = obj["project"].toObject();
            QJsonObject jsonCompany = obj["project"].toObject()["company"].toObject();
            QJsonObject jsonUser = obj["user"].toObject();

            PartTypeStruct partType = {jsonPartType["idPartType"].toInt(), jsonPartType["type"].toString()};
            AmountTypeStruct amountType = {jsonAmountType["idAmountType"].toInt(), jsonAmountType["type"].toString()};
            CompanyStruct company = {jsonCompany["idCompany"].toInt(), jsonCompany["name"].toString()};
            ProjectStruct project = {jsonProject["idProject"].toInt(), jsonProject["name"].toString(), jsonProject["description"].toString(), jsonProject["isFinished"].toBool(), jsonProject["startDate"].toVariant().toDate(), jsonProject["finishDate"].toVariant().toDate(), company};
            UserStruct user = {jsonUser["idUser"].toInt(), jsonUser["username"].toString(), jsonUser["password"].toString(), jsonUser["isAdmin"].toBool()};

            qDebug() << mList->items().size();

            UsedPartsStruct usedParts = {obj["idPartsUsed"].toInt(), obj["amount"].toInt(), obj["specification"].toString(), obj["dateUsed"].toVariant().toDate(), partType, amountType, project, user};

            mList->appendItem(usedParts);

            qDebug() << mList->items().size();
        }
    }
}

