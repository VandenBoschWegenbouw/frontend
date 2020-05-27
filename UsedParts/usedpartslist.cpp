#include "usedpartslist.h"

UsedPartsList::UsedPartsList(QObject *parent) : QObject(parent)
{

}

QVector<UsedPartsStruct> UsedPartsList::items() const
{
    return mItems;
}
bool UsedPartsList::setItemAt(int index, const UsedPartsStruct &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const UsedPartsStruct &oldItem = mItems.at(index);

    if (item.id == oldItem.id && item.date == oldItem.date && item.amount == oldItem.amount && item.specification == oldItem.specification)
        return false;

    mItems[index] = item;
    return true;
}

void UsedPartsList::appendItem(UsedPartsStruct item)
{
    emit preItemAppended();

    mItems.append(item);

    emit postItemAppended();
}
