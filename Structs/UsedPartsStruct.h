#ifndef USEDPARTSSTRUCT_H
#define USEDPARTSSTRUCT_H

#include <QString>
#include <QDate>

#include <Structs/PartTypeStruct.h>
#include <Structs/AmountTypeStruct.h>
#include <Structs/ProjectStruct.h>
#include <Structs/UserStruct.h>

struct UsedPartsStruct {
    int id;
    int amount;
    QString specification;
    QDate date;
    PartTypeStruct partType;
    AmountTypeStruct amountType;
    ProjectStruct project;
    UserStruct user;

    UsedPartsStruct() {

    }

    UsedPartsStruct(int id, int amount, QString specification, QDate date, PartTypeStruct partType, AmountTypeStruct amountType, ProjectStruct project, UserStruct user) {
        this->id = id;
        this->amount = amount;
        this->specification = specification;
        this->date = date;
        this->partType = partType;
        this->amountType = amountType;
        this->project = project;
        this->user = user;
    }

    UsedPartsStruct(int amount, QString specification, QDate date, PartTypeStruct partType, AmountTypeStruct amountType, ProjectStruct project, UserStruct user) {
        this->amount = amount;
        this->specification = specification;
        this->date = date;
        this->partType = partType;
        this->amountType = amountType;
        this->project = project;
        this->user = user;
    }
};

#endif // USEDPARTSSTRUCT_H
