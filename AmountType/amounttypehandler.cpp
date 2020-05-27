#include "amounttypehandler.h"

AmountTypeHandler::AmountTypeHandler(QObject *parent) : QObject(parent)
{

}

void AmountTypeHandler::fetchAmountTypes(AmountTypeList *atList)
{
    mComponent.fetchAmountTypes(atList);
}
