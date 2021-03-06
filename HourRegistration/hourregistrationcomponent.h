#ifndef HOURREGISTRATIONCOMPONENT_H
#define HOURREGISTRATIONCOMPONENT_H

#include <QObject>
#include <Structs/HourRegistrationStruct.h>
#include <QNetworkAccessManager>

#include <HourRegistration/hourregistrationlist.h>

class HourRegistrationComponent : public QObject
{
    Q_OBJECT
public:
    explicit HourRegistrationComponent(QObject *parent = nullptr);

    void fetchHours(HourRegistrationList *list, QDate date);

    void addHours(HourRegistrationStruct hr, HourRegistrationList *list);

signals:
    void workedTooHard();

private slots:
    void _finished(QNetworkReply *);

private:
    QNetworkAccessManager manager;
    HourRegistrationList *mList;
    QDate fetchedDate;

};

#endif // HOURREGISTRATIONCOMPONENT_H
