#include "parttypehandler.h"

PartTypeHandler::PartTypeHandler(QObject *parent) : QObject(parent)
{

}

void PartTypeHandler::fetchPartTypes(PartTypeList *ptList)
{
    mComponent.fetchPartTypes(ptList);
}
