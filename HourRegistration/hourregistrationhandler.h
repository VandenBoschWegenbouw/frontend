#ifndef HOURREGISTRATIONHANDLER_H
#define HOURREGISTRATIONHANDLER_H

#include <QObject>

class HourRegistrationHandler : public QObject
{
    Q_OBJECT
public:
    explicit HourRegistrationHandler(QObject *parent = nullptr);

public slots:
    //To give the overview of all hour registrations
    void fetchHours();

    //To add new hour registrations
    void fetchProjects();
    void fetchCustomer();

signals:

};

#endif // HOURREGISTRATIONHANDLER_H
