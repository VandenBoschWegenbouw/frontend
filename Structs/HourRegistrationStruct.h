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
};

#endif // HOURREGISTRATIONSTRUCT_H
