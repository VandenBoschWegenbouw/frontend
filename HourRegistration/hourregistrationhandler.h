#ifndef HOURREGISTRATIONHANDLER_H
#define HOURREGISTRATIONHANDLER_H

#include <QObject>
#include <Company/companylist.h>


class HourRegistrationHandler : public QObject
{
    Q_OBJECT
public:
    explicit HourRegistrationHandler(QObject *parent = nullptr);

public slots:
    //To give the overview of all hour registrations
    void fetchHours();



signals:


private:
    CompanyList *mList;
};

#endif // HOURREGISTRATIONHANDLER_H
