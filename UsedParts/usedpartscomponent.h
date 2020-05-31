#ifndef USEDPARTSCOMPONENT_H
#define USEDPARTSCOMPONENT_H

#include <QObject>

#include <UsedParts/usedpartslist.h>
#include <QNetworkAccessManager>

class UsedPartsComponent : public QObject
{
    Q_OBJECT
public:
    explicit UsedPartsComponent(QObject *parent = nullptr);

    void fetchUsedParts(UsedPartsList *list);
    void fetchUsedParts(UsedPartsList *list, QDate date);

    void addUsedParts(UsedPartsStruct upStruct, UsedPartsList *upList);

private slots:
    void _finished(QNetworkReply *);

signals:

private:
    UsedPartsList *mList;
    QNetworkAccessManager manager;

};

#endif // USEDPARTSCOMPONENT_H
