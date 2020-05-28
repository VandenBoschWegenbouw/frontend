#include "parttypelist.h"

PartTypeList::PartTypeList(QObject *parent) : QObject(parent)
{

}

QVector<PartTypeStruct> PartTypeList::items() const
{
    return mItems;
}

bool PartTypeList::setItemAt(int index, const PartTypeStruct &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const PartTypeStruct &oldItem = mItems.at(index);

    if (item.id == oldItem.id && item.type == oldItem.type)
        return false;

    mItems[index] = item;
    return true;
}

void PartTypeList::appendItem(PartTypeStruct item)
{
    emit preItemAppended();

    mItems.append(item);

    emit postItemAppended();
}

void PartTypeList::clearList()
{
    for (int i =0; i < mItems.size();i++) {
        emit preItemRemoved(i);

        mItems.removeAt(i);

        emit postItemRemoved();
    }
}
