#include "usedpartsmodel.h"

#include <UsedParts/usedpartslist.h>

UsedPartsModel::UsedPartsModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int UsedPartsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant UsedPartsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const UsedPartsStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            return QVariant(item.id);
        case AmountRole:
            return QVariant(item.amount);
        case SpecificationRole:
            return QVariant(item.specification);
        case DateRole:
            return QVariant(item.date);
        case PartTypeRole:
            return QVariant(item.partType.type);
        case AmountTypeRole:
            return QVariant(item.amountType.type);
        case ProjectRole:
            return QVariant(item.project.name);
        case UserRole:
            return QVariant(item.user.username);
        case CompanyRole:
            return QVariant(item.project.company.name);
    }

    return QVariant();
}

bool UsedPartsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    UsedPartsStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            item.id = value.toInt();
        break;
        case AmountRole:
            item.amount = value.toInt();
        break;
        case SpecificationRole:
            item.specification = value.toString();
        break;
        case DateRole:
            item.date = value.toDate();
        break;
        case PartTypeRole:
            item.partType.type = value.toString();
        break;
        case AmountTypeRole:
            item.amountType.type = value.toString();
        break;
        case ProjectRole:
            item.project.name = value.toString();
        break;
        case UserRole:
            item.user.username = value.toString();
        break;
        case CompanyRole:
            item.project.company.name = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags UsedPartsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable;
}

QHash<int, QByteArray> UsedPartsModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IdRole] = "id";
    names[AmountRole] = "amount";
    names[SpecificationRole] = "specification";
    names[DateRole] = "date";
    names[PartTypeRole] = "partType";
    names[AmountTypeRole] = "amountType";
    names[ProjectRole] = "project";
    names[UserRole] = "user";
    names[CompanyRole] = "company";

    return names;
}

UsedPartsList *UsedPartsModel::list() const
{
    return mList;
}

void UsedPartsModel::setList(UsedPartsList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &UsedPartsList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mList, &UsedPartsList::postItemAppended, this, [=]() {
            endInsertRows();
        });
    }

    endResetModel();
}
