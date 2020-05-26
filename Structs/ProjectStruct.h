#ifndef PROJECTSTRUCT_H
#define PROJECTSTRUCT_H

#include <QString>
#include <QDate>
#include <Structs/CompanyStruct.h>

struct ProjectStruct {
    int id;
    QString name;
    QString description;
    bool finished;
    QDate start_date;
    QDate finish_Date;
    CompanyStruct company;
};

#endif // PROJECTSTRUCT_H
