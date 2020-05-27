#ifndef USEDPARTSHANDLER_H
#define USEDPARTSHANDLER_H

#include <QObject>

#include <UsedParts/usedpartscomponent.h>
#include <UsedParts/usedpartslist.h>

class UsedPartsHandler : public QObject
{
    Q_OBJECT
public:
    explicit UsedPartsHandler(QObject *parent = nullptr);


public slots:
    void fetchUsedParts(UsedPartsList *upList);

signals:

private:
    UsedPartsComponent mComponent;

};

#endif // USEDPARTSHANDLER_H
