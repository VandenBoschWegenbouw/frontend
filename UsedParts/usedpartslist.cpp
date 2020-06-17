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

void UsedPartsList::clearList()
{
    int size = mItems.size();
    for (int i =0; i < size; i++) {
        emit preItemRemoved(0);

        mItems.removeLast();

        emit postItemRemoved();
    }
}

void UsedPartsList::removeAtIndex(int index)
{
    if (index >= 0 && index < mItems.size()) {
        emit preItemRemoved(index);

        mItems.removeAt(index);

        emit postItemRemoved();
    }
}
