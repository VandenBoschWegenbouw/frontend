#include "amounttypelist.h"

AmountTypeList::AmountTypeList(QObject *parent) : QObject(parent)
{

}

QVector<AmountTypeStruct> AmountTypeList::items() const
{
    return mItems;
}

bool AmountTypeList::setItemAt(int index, const AmountTypeStruct &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const AmountTypeStruct &oldItem = mItems.at(index);

    if (item.id == oldItem.id && item.type == oldItem.type)
        return false;

    mItems[index] = item;
    return true;
}

void AmountTypeList::appendItem(AmountTypeStruct item)
{
    emit preItemAppended();

    mItems.append(item);

    emit postItemAppended();
}

void AmountTypeList::clearList()
{
    for (int i =0; i < mItems.size();i++) {
        emit preItemRemoved(i);

        mItems.removeAt(i);

        emit postItemRemoved();
    }
}
