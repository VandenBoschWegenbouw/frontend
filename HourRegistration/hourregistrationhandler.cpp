#include "hourregistrationhandler.h"
#include "Login/logincomponent.h"
#include <QDebug>

HourRegistrationHandler::HourRegistrationHandler(QObject *parent) : QObject(parent)
{
    connect(&mComponent, &HourRegistrationComponent::workedTooHard, this, &HourRegistrationHandler::workedHard);
}

int HourRegistrationHandler::workedHours() const
{
    return mWorkedHours;
}

QString HourRegistrationHandler::description() const
{
    return mDescription;
}

void HourRegistrationHandler::setWorkedHours(const int &workedHours)
{
    if (workedHours == mWorkedHours)
        return;

    mWorkedHours = workedHours;
    emit workedHoursChanged(mWorkedHours);
}

void HourRegistrationHandler::setDescription(const QString &description)
{
    if (description == mDescription)
        return;

    mDescription = description;
    emit descriptionChanged(mDescription);
}

void HourRegistrationHandler::fetchHours(HourRegistrationList *hList) {
    mComponent.fetchHours(hList, QDate::currentDate());
}

void HourRegistrationHandler::fetchHours(HourRegistrationList *list, QString date)
{

    QDate qDate = QDate::fromString(date, "dd-MM-yyyy");
    mComponent.fetchHours(list, qDate);
}

void HourRegistrationHandler::addHours(ProjectList *pList, int selectedPIndex, HourRegistrationList *hList, QString date)
{
    ProjectStruct project = pList->items().at(selectedPIndex);
    UserStruct user = LoginComponent::user;

    HourRegistrationStruct hr;

    QDate qDate = QDate::fromString(date, "dd-MM-yyyy");

    hr.user = user;
    hr.project = project;
    hr.hours = mWorkedHours;
    hr.date = qDate;
    hr.description = mDescription;

    mComponent.addHours(hr, hList);
}

void HourRegistrationHandler::deleteHours(int index, HourRegistrationList *hList)
{
    HourRegistrationStruct hr = hList->items().at(index);

    mDeleteComponent.deleteHours(hr, hList, index);
}

void HourRegistrationHandler::workedHard()
{
    emit workedTooHard();
}

