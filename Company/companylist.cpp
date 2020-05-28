#include "companylist.h"

#include <QDebug>

CompanyList::CompanyList(QObject *parent) : QObject(parent)
{

}

QVector<CompanyStruct> CompanyList::items() const
{
    return mItems;
}

bool CompanyList::setItemAt(int index, const CompanyStruct &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const CompanyStruct &oldItem = mItems.at(index);
    if (item.id == oldItem.id && item.name == oldItem.name)
        return false;

    mItems[index] = item;
    return true;
}

void CompanyList::appendItem()
{
    emit preItemAppended();

    CompanyStruct company;
    company.id = -1;
    company.name = "This is a test company!";
    mItems.append(company);

    emit postItemAppended();
}

void CompanyList::appendItem(CompanyStruct item)
{
    emit preItemAppended();

    mItems.append(item);

    emit postItemAppended();
}

void CompanyList::clearList()
{
    int size = mItems.size();
    for (int i =0; i < size; i++) {
        emit preItemRemoved(0);

        mItems.removeLast();

        emit postItemRemoved();
    }
}




