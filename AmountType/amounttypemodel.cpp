#include "amounttypemodel.h"

#include <AmountType/amounttypelist.h>

AmountTypeModel::AmountTypeModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int AmountTypeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant AmountTypeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const AmountTypeStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            return QVariant(item.id);
        case TypeRole:
            return QVariant(item.type);
    }

    return QVariant();
}

bool AmountTypeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    AmountTypeStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            item.id = value.toInt();
        break;
        case TypeRole:
            item.type = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags AmountTypeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable;
}

QHash<int, QByteArray> AmountTypeModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IdRole] = "id";
    names[TypeRole] = "type";

    return names;
}

AmountTypeList *AmountTypeModel::list() const
{
    return mList;
}

void AmountTypeModel::setList(AmountTypeList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &AmountTypeList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mList, &AmountTypeList::postItemAppended, this, [=]() {
            endInsertRows();
        });
    }

    endResetModel();
}


