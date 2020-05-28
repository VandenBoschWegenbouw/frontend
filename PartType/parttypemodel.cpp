#include "parttypemodel.h"

#include <PartType/parttypelist.h>

PartTypeModel::PartTypeModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}
int PartTypeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant PartTypeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const PartTypeStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            return QVariant(item.id);
        case TypeRole:
            return QVariant(item.type);
    }

    return QVariant();
}

bool PartTypeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    PartTypeStruct item = mList->items().at(index.row());
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

Qt::ItemFlags PartTypeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable;
}

QHash<int, QByteArray> PartTypeModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IdRole] = "id";
    names[TypeRole] = "type";

    return names;
}

PartTypeList *PartTypeModel::list() const
{
    return mList;
}

void PartTypeModel::setList(PartTypeList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &PartTypeList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mList, &PartTypeList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &PartTypeList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &PartTypeList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
