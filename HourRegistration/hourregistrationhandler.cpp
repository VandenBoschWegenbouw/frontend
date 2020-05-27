#include "hourregistrationhandler.h"
#include "Login/logincomponent.h"
#include <QDebug>

HourRegistrationHandler::HourRegistrationHandler(QObject *parent) : QObject(parent)
{

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
    mComponent.fetchHours(hList);
}

void HourRegistrationHandler::addHours(ProjectList *pList, int selectedPIndex, HourRegistrationList *hList)
{
    ProjectStruct project = pList->items().at(selectedPIndex);
    UserStruct user = LoginComponent::user;

    HourRegistrationStruct hr;

    hr.user = user;
    hr.project = project;
    hr.hours = mWorkedHours;
    hr.date = QDate::currentDate();
    hr.description = mDescription;

    mComponent.addHours(hr, hList);


}

