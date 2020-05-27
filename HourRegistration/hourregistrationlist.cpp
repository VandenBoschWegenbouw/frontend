#include "hourregistrationlist.h"

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
