#ifndef SERVERCOMMUNICATOR_H
#define SERVERCOMMUNICATOR_H

#include <QByteArray>
#include <QString>
#include <QNetworkAccessManager>

enum Endpoints {
    AmountType,
    Company,
    HourRegistration,
    PartsUsed,
    PartType,
    Project,
    User
};

class ServerCommunicator
{
public:
    ServerCommunicator();
    QByteArray Create(Endpoints endpoint, QByteArray body);
    QByteArray Read(Endpoints endpoint, int id);
    QByteArray ReadAll(Endpoints endpoint);
    QByteArray Update(Endpoints endpoint, int id, QByteArray body);
    QByteArray Delete(Endpoints endpoint, int id);
    QByteArray Post(Endpoints endpoint, QString parameters, QByteArray body);

private:
    QNetworkAccessManager manager;
    QString getEnumString(Endpoints endpoint);
    QString url = "http://localhost:9000/";
};

#endif // SERVERCOMMUNICATOR_H
