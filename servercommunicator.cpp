#include "servercommunicator.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QThread>

ServerCommunicator::ServerCommunicator()
{

}

QByteArray ServerCommunicator::Create(Endpoints endpoint, QByteArray body)
{
    QString strEndpoint = getEnumString(endpoint);
    QNetworkRequest request(QUrl(url + strEndpoint));
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply *reply = manager.post(request,body);

    while (!reply->isFinished()) {
        QThread::msleep(5);
    }

    return reply->readAll();
}

QByteArray ServerCommunicator::Read(Endpoints endpoint, int id)
{
    QString strEndpoint = getEnumString(endpoint);
    QNetworkRequest request(QUrl(url + strEndpoint + id));
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply *reply = manager.get(request);

    while (!reply->isFinished()) {
        QThread::msleep(5);
    }

    return reply->readAll();
}

QByteArray ServerCommunicator::ReadAll(Endpoints endpoint)
{
    QString strEndpoint = getEnumString(endpoint);
    QNetworkRequest request(QUrl(url + strEndpoint));
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply *reply = manager.get(request);

    while (!reply->isFinished()) {
        QThread::msleep(5);
    }

    return reply->readAll();
}

QByteArray ServerCommunicator::Update(Endpoints endpoint, int id, QByteArray body)
{
    QString strEndpoint = getEnumString(endpoint);
    QNetworkRequest request(QUrl(url + strEndpoint + id));
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply *reply = manager.put(request,body);

    while (!reply->isFinished()) {
        QThread::msleep(5);
    }

    return reply->readAll();
}

QByteArray ServerCommunicator::Delete(Endpoints endpoint, int id)
{
    QString strEndpoint = getEnumString(endpoint);
    QNetworkRequest request(QUrl(url + strEndpoint + id));
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply *reply = manager.deleteResource(request);

    while (!reply->isFinished()) {
        QThread::msleep(5);
    }

    return reply->readAll();
}

QByteArray ServerCommunicator::Post(Endpoints endpoint, QString urlParameters, QByteArray body)
{
    QString strEndpoint = getEnumString(endpoint);
    QNetworkRequest request(QUrl(url + strEndpoint + urlParameters));
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply *reply = manager.post(request,body);

    return reply->readAll();
}

QString ServerCommunicator::getEnumString(Endpoints endpoint)
{
    switch (endpoint) {
    case User:
        return "users/";
    case Company:
        return "companies/";
    case Project:
        return "projects/";
    case PartType:
        return "parttype/";
    case PartsUsed:
        return "partsused/";
    case AmountType:
        return "amounttype/";
    case HourRegistration:
        return "hourregistration/";
    }
}



