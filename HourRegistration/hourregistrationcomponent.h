#ifndef HOURREGISTRATIONCOMPONENT_H
#define HOURREGISTRATIONCOMPONENT_H

#include <QObject>

class HourRegistrationComponent : public QObject
{
    Q_OBJECT
public:
    explicit HourRegistrationComponent(QObject *parent = nullptr);

    void fetchCustomers();

signals:

};

#endif // HOURREGISTRATIONCOMPONENT_H
