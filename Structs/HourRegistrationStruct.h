#ifndef HOURREGISTRATIONSTRUCT_H
#define HOURREGISTRATIONSTRUCT_H

#include <Structs/UserStruct.h>
#include <Structs/ProjectStruct.h>

struct HourRegistrationStruct {
    int id;
    UserStruct user;
    ProjectStruct project;
    int hours;
    QDate date;
    QString description;

    HourRegistrationStruct() {

    }

    HourRegistrationStruct(int id, UserStruct user, ProjectStruct project, int hours, QDate date, QString description) {
        this->id = id;
        this->user = user;
        this->project = project;
        this->hours = hours;
        this->date = date;
        this->description = description;
    }
    HourRegistrationStruct(UserStruct user, ProjectStruct project, int hours, QDate date, QString description) {
        this->user = user;
        this->project = project;
        this->hours = hours;
        this->date = date;
        this->description = description;
    }
};

#endif // HOURREGISTRATIONSTRUCT_H

