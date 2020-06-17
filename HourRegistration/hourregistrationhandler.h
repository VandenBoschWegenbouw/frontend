#ifndef HOURREGISTRATIONHANDLER_H
#define HOURREGISTRATIONHANDLER_H

#include <QObject>
#include <Company/companylist.h>
#include <Projects/projectlist.h>
#include <HourRegistration/hourregistrationcomponent.h>
#include <HourRegistration/Delete/deletecomponent.h>

#include <HourRegistration/hourregistrationlist.h>


class HourRegistrationHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int workedHours READ workedHours WRITE setWorkedHours NOTIFY workedHoursChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)

public:
    explicit HourRegistrationHandler(QObject *parent = nullptr);

    int workedHours() const;
    QString description() const;

    void setWorkedHours(const int& workedHours);
    void setDescription(const QString& description);

public slots:
    //To give the overview of all hour registrations
    void fetchHours(HourRegistrationList *list);
    void fetchHours(HourRegistrationList *list, QString date);

    void addHours(ProjectList *pList, int selectedPIndex, HourRegistrationList *hList, QString date);

    void deleteHours(int index, HourRegistrationList *hList);

    void workedHard();

signals:
    void workedHoursChanged(const int& workedHours);
    void descriptionChanged(const QString& description);
    void workedTooHard();
    void missingInfo();

private:
    int mWorkedHours;
    QString mDescription;

    CompanyList *mList;

    HourRegistrationComponent mComponent;
    DeleteComponent mDeleteComponent;
};

#endif // HOURREGISTRATIONHANDLER_H
