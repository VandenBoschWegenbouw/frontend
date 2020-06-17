#include "deletepartscomponent.h"

#include <QTextCodec>

DeletePartsComponent::DeletePartsComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &DeletePartsComponent::_finished);
}

void DeletePartsComponent::deleteParts(UsedPartsStruct up, UsedPartsList *upList, int index)
{
    mList = upList;
    mIndex = index;

    qDebug() << up.id;
    QNetworkRequest request(QUrl("http://51.75.133.79:9000/partsused/" + QString::number(up.id)));
    request.setRawHeader("Content-Type", "application/json");

    manager.deleteResource(request);
}

void DeletePartsComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {
        bool result = QVariant(QTextCodec::codecForMib(106)->toUnicode(arr)).toBool();
        if (result) {
            mList->removeAtIndex(mIndex);
        }
    }
}
