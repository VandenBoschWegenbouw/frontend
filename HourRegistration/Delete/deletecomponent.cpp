#include "deletecomponent.h"

#include <QNetworkReply>
#include <QTextCodec>

DeleteComponent::DeleteComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &DeleteComponent::_finished);
}

void DeleteComponent::deleteHours(HourRegistrationStruct hr, HourRegistrationList *hList, int index)
{
    mList = hList;

    mIndex = index;

    QNetworkRequest request(QUrl("http://51.75.133.79:9000/hourregistration/" + QString::number(hr.id)));
    request.setRawHeader("Content-Type", "application/json");

    manager.deleteResource(request);
}

void DeleteComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {
        bool result = QVariant(QTextCodec::codecForMib(106)->toUnicode(arr)).toBool();
        if (result) {
            mList->removeAtIndex(mIndex);
        }
    }
}
