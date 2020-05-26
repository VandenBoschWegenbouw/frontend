#include "companymodel.h"

#include "companylist.h"

#include <qdebug.h>

CompanyModel::CompanyModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int CompanyModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant CompanyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const CompanyStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            return QVariant(item.id);
        case NameRole:
            return QVariant(item.name);
    }

    return QVariant();
}

bool CompanyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    CompanyStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            item.id = value.toInt();
        break;
        case NameRole:
            item.name = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags CompanyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable;
}

QHash<int, QByteArray> CompanyModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IdRole] = "id";
    names[NameRole] = "name";
    return names;
}

CompanyList *CompanyModel::list() const
{
    return mList;
}

void CompanyModel::setList(CompanyList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &CompanyList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mList, &CompanyList::postItemAppended, this, [=]() {
            endInsertRows();
        });
    }

    endResetModel();
}
