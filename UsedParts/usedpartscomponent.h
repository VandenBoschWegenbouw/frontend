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

private slots:
    void _finished(QNetworkReply *);

signals:

private:
    UsedPartsList *mList;
    QNetworkAccessManager manager;

};

#endif // USEDPARTSCOMPONENT_H
