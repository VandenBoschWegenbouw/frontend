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
};

#endif // USEDPARTSSTRUCT_H
