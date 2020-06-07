#include "companycomponent.h"

#include <QDebug>

#include <QNetworkAccessManager>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>


CompanyComponent::CompanyComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &CompanyComponent::_finished);
}

void CompanyComponent::fetchCompanies(CompanyList *lst)
{
    mList = lst;

    QNetworkRequest request(QUrl("http://51.75.133.79:9000/company/"));
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void CompanyComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {
        QJsonDocument doc = QJsonDocument::fromJson(arr);

        QJsonArray jsonArr = doc.array();

        mList->clearList();

        foreach (const QJsonValue &value, jsonArr) {
            QJsonObject obj = value.toObject();
            mList->appendItem({obj["idCompany"].toInt(), obj["name"].toString()});
        }
    }
}
