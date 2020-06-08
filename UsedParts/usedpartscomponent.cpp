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

    const QString url = "http://51.75.133.79:9000/partsused/"+QDate::currentDate().toString("yyyy-MM-dd");

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void UsedPartsComponent::fetchUsedParts(UsedPartsList *list, QDate date)
{
    mList = list;

    const QString url = "http://51.75.133.79:9000/partsused/"+date.toString("yyyy-MM-dd");

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void UsedPartsComponent::addUsedParts(UsedPartsStruct up, UsedPartsList *upList)
{
    mList = upList;

    QJsonObject obj;

    QJsonObject user;
    QJsonObject company;
    QJsonObject project;
    QJsonObject amountType;
    QJsonObject partType;

    user["idUser"] = up.user.id;
    user["username"] = up.user.username;
    user["password"] = up.user.password;
    user["isAdmin"] = up.user.admin;

    company["idCompany"] = up.project.company.id;
    company["name"] = up.project.company.name;

    project["idProject"] = up.project.id;
    project["description"] = up.project.description;
    project["isFinished"] = up.project.finished;
    project["startDate"] = up.project.start_date.toString("yyyy-MM-dd") + "T00:00:00";
    if (!up.project.finish_date.isNull()) {
        project["finishDate"] = up.project.finish_date.toString("yyyy-MM-ddT00:00:00");
    }
    project["name"] = up.project.name;
    project["company"] = company;

    amountType["idAmountType"] = up.amountType.id;
    amountType["type"] = up.amountType.type;

    partType["idPartType"] = up.partType.id;
    partType["type"] = up.partType.type;

    obj["amount"] = up.amount;
    obj["specification"] = up.specification;
    obj["dateUsed"] = up.date.toString("yyyy-MM-dd") + "T00:00:00";
    obj["partType"] = partType;
    obj["amountType"] = amountType;
    obj["project"] = project;
    obj["user"] = user;

    QJsonDocument doc(obj);

    QNetworkRequest request(QUrl("http://51.75.133.79:9000/partsused/"));
    request.setRawHeader("Content-Type", "application/json");

    manager.post(request, doc.toJson());


}

void UsedPartsComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {

        QJsonDocument doc = QJsonDocument::fromJson(arr);

        QJsonArray jsonArr = doc.array();

        mList->clearList();

        if (jsonArr.size() == 0 && !doc.object().isEmpty()) {
            QJsonObject obj = doc.object();
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

            UsedPartsStruct usedParts = {obj["idPartsUsed"].toInt(), obj["amount"].toInt(), obj["specification"].toString(), obj["dateUsed"].toVariant().toDate(), partType, amountType, project, user};

            mList->appendItem(usedParts);
        } else {
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

                UsedPartsStruct usedParts = {obj["idPartsUsed"].toInt(), obj["amount"].toInt(), obj["specification"].toString(), obj["dateUsed"].toVariant().toDate(), partType, amountType, project, user};


                mList->appendItem(usedParts);
            }
        }


    }
}

