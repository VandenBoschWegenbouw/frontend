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
    QDate finish_date;
    CompanyStruct company;

    ProjectStruct(int id, QString name, QString description, bool finished, QDate start_date, QDate finish_date, CompanyStruct company) {
        this->id = id;
        this->name = name;
        this->description = description;
        this->finished = finished;
        this->start_date = start_date;
        this->finish_date = finish_date;
        this->company = company;
    }

    ProjectStruct(QString name, QString description, QDate start_date, CompanyStruct company) {
        this->name = name;
        this->description = description;
        this->start_date = start_date;
        this->company = company;
    }

    ProjectStruct() {

    }
};

#endif // PROJECTSTRUCT_H
