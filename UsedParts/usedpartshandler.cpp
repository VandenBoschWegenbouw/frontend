#include "usedpartshandler.h"

UsedPartsHandler::UsedPartsHandler(QObject *parent) : QObject(parent)
{

}

void UsedPartsHandler::fetchUsedParts(UsedPartsList *upList)
{
    mComponent.fetchUsedParts(upList);
}
