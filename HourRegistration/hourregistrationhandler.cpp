#include "hourregistrationhandler.h"
#include "Login/logincomponent.h"
#include <QDebug>

HourRegistrationHandler::HourRegistrationHandler(QObject *parent) : QObject(parent)
{

}


void HourRegistrationHandler::fetchHours() {

}

void HourRegistrationHandler::fetchProjects() {
    qDebug() << LoginComponent::user.id;
}

void HourRegistrationHandler::fetchCustomer() {

}
