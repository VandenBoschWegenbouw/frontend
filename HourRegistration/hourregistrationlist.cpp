#include "hourregistrationlist.h"

#include <QDebug>

HourRegistrationList::HourRegistrationList(QObject *parent) : QObject(parent)
{
}

QVector<HourRegistrationStruct> HourRegistrationList::items() const
{
    return mItems;
}

bool HourRegistrationList::setItemAt(int index, const HourRegistrationStruct &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const HourRegistrationStruct &oldItem = mItems.at(index);
    if (item.id == oldItem.id && item.hours == oldItem.hours && item.date == oldItem.date && item.description == oldItem.description)
        return false;

    mItems[index] = item;
    return true;
}

void HourRegistrationList::appendItem(HourRegistrationStruct item)
{
    emit preItemAppended();

    mItems.append(item);

    emit postItemAppended();
}

void HourRegistrationList::clearList()
{
    int size = mItems.size();
    for (int i =0; i < size; i++) {
        emit preItemRemoved(0);

        mItems.removeLast();

        emit postItemRemoved();
    }
}

void HourRegistrationList::removeAtIndex(int index)
{
    if (index >= 0 && index < mItems.size()) {
        emit preItemRemoved(index);

        mItems.removeAt(index);

        emit postItemRemoved();
    }
}
