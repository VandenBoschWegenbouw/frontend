#include "projectcomponent.h"

#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

ProjectComponent::ProjectComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &ProjectComponent::_finished);
}

void ProjectComponent::fetchProjectsByCompany(ProjectList *list, int idCompany)
{
    mList = list;

    const QString url = "http://51.75.133.79:9000/company/" + QString::number(idCompany) + "/projects";

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void ProjectComponent::fetchProjects(ProjectList *list)
{
    mList = list;

    const QString url = "http://51.75.133.79:9000/projects/";

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}



void ProjectComponent::_finished(QNetworkReply *reply)
{

    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {
        QJsonDocument doc = QJsonDocument::fromJson(arr);

        QJsonArray jsonArr = doc.array();

        mList->clearItems();

        foreach(const QJsonValue &value, jsonArr) {
            QJsonObject obj = value.toObject();
            QJsonObject comp = obj["company"].toObject();

            CompanyStruct company = {comp["idCompany"].toInt(), comp["name"].toString()};

            mList->appendItem({obj["idProject"].toInt(), obj["name"].toString(), obj["description"].toString(), obj["isFinished"].toBool(),obj["startDate"].toVariant().toDate(), obj["finishDate"].toVariant().toDate(), company});
        }
    }
}
