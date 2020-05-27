#include "hourregistrationmodel.h"

#include <HourRegistration/hourregistrationlist.h>

HourRegistrationModel::HourRegistrationModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int HourRegistrationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant HourRegistrationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const HourRegistrationStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            return QVariant(item.id);
        case UserRole:
            throw 20;
        case ProjectRole:
        return QVariant(item.project.name);
        case HoursRole:
            return QVariant(item.hours);
        case DateRole:
            return QVariant(item.date);
        case DescriptionRole:
            return QVariant(item.description);
        case CompanyRole:
            return QVariant(item.project.company.name);
    }

    return QVariant();
}

bool HourRegistrationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    HourRegistrationStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            item.id = value.toInt();
        break;
        case UserRole:
            throw 20;
        case ProjectRole:
            item.project.name = value.toString();
        case HoursRole:
            item.hours = value.toInt();
        break;
        case DateRole:
            item.date = value.toDate();
        break;
        case DescriptionRole:
            item.description = value.toString();
        break;
        case CompanyRole:
            item.project.company.name = value.toString();
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags HourRegistrationModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable;
}

QHash<int, QByteArray> HourRegistrationModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IdRole] = "id";
    names[UserRole] = "user";
    names[ProjectRole] = "project";
    names[HoursRole] = "uren";
    names[DateRole] = "date";
    names[DescriptionRole] = "description";
    names[CompanyRole] = "company";

    return names;
}

HourRegistrationList *HourRegistrationModel::list() const
{
    return mList;
}

void HourRegistrationModel::setList(HourRegistrationList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &HourRegistrationList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mList, &HourRegistrationList::postItemAppended, this, [=]() {
            endInsertRows();
        });
    }

    endResetModel();
}
