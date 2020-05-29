#ifndef DELETECOMPONENT_H
#define DELETECOMPONENT_H

#include <QObject>

#include <HourRegistration/hourregistrationlist.h>
#include <Structs/HourRegistrationStruct.h>

#include <QNetworkAccessManager>
class DeleteComponent : public QObject
{
    Q_OBJECT
public:
    explicit DeleteComponent(QObject *parent = nullptr);

    void deleteHours(HourRegistrationStruct hr, HourRegistrationList *hList, int index);

signals:

private slots:
    void _finished(QNetworkReply *);

private:
    HourRegistrationList *mList;
    int mIndex;

    QNetworkAccessManager manager;

};

#endif // DELETECOMPONENT_H
