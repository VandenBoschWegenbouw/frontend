#include "usedpartshandler.h"

#include <Login/logincomponent.h>

UsedPartsHandler::UsedPartsHandler(QObject *parent) : QObject(parent)
{

}

int UsedPartsHandler::partAmount() const
{
    return mPartAmount;
}

QString UsedPartsHandler::specification() const
{
    return mSpecification;
}

void UsedPartsHandler::setPartAmount(const int &partAmount)
{
    if (mPartAmount == partAmount)
        return;

    mPartAmount = partAmount;
    emit partAmountChanged(mPartAmount);
}

void UsedPartsHandler::setSpecification(const QString &specification)
{
    if (mSpecification == specification)
        return;

    mSpecification = specification;
    emit specificationChanged(mSpecification);
}

void UsedPartsHandler::fetchUsedParts(UsedPartsList *upList)
{
    mComponent.fetchUsedParts(upList);
}

void UsedPartsHandler::fetchUsedParts(UsedPartsList *upList, QString date)
{
    QDate qDate = QDate::fromString(date, "dd-MM-yyyy");
    mComponent.fetchUsedParts(upList, qDate);
}

void UsedPartsHandler::addUsedParts(PartTypeList *ptList, int ptIndex, AmountTypeList *atList, int atIndex, ProjectList *pList, int pIndex, UsedPartsList *upList)
{
    PartTypeStruct partType = ptList->items().at(ptIndex);
    AmountTypeStruct amountType = atList->items().at(atIndex);
    ProjectStruct project = pList->items().at(pIndex);
    UserStruct user = LoginComponent::user;

    UsedPartsStruct up;

    up.partType = partType;
    up.amountType = amountType;
    up.project = project;
    up.user = user;
    up.amount = mPartAmount;
    up.specification = mSpecification;
    up.date = QDate::currentDate();

    mComponent.addUsedParts(up, upList);
}

void UsedPartsHandler::deleteParts(int index, UsedPartsList *upList)
{
    UsedPartsStruct usedParts = upList->items().at(index);

    mDeleteComponent.deleteParts(usedParts, upList, index);
}


