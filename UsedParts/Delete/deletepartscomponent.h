#ifndef DELETEPARTSCOMPONENT_H
#define DELETEPARTSCOMPONENT_H

#include <QNetworkReply>
#include <QObject>

#include <Structs/UsedPartsStruct.h>

#include <UsedParts/usedpartslist.h>

class DeletePartsComponent : public QObject
{
    Q_OBJECT
public:
    explicit DeletePartsComponent(QObject *parent = nullptr);

    void deleteParts(UsedPartsStruct up, UsedPartsList *upList, int index);

signals:

private slots:
    void _finished(QNetworkReply *);

private:
    UsedPartsList *mList;
    int mIndex;

    QNetworkAccessManager manager;

};


#endif // DELETEPARTSCOMPONENT_H
