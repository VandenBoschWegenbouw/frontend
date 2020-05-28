#include "projectmodel.h"


#include "projectlist.h"
ProjectModel::ProjectModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int ProjectModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant ProjectModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const ProjectStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            return QVariant(item.id);
        case NameRole:
            return QVariant(item.name);
        case DescriptionRole:
            return QVariant(item.description);
        case FinishedRole:
            return QVariant(item.finished);
        case StartDateRole:
            return QVariant(item.start_date);
        case FinishDateRole:
            return QVariant(item.finish_Date);
        case CompanyRole:
            throw 20;
//            QVariant packet;
//            packet.setValue(item.company);
//            return packet;

    }

    return QVariant();
}

bool ProjectModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    ProjectStruct item = mList->items().at(index.row());
    switch (role) {
        case IdRole:
            item.id = value.toInt();
        break;
        case NameRole:
            item.name = value.toString();
        break;
        case DescriptionRole:
            item.description = value.toString();
        break;
        case FinishedRole:
            item.finished = value.toBool();
        break;
        case StartDateRole:
            item.start_date = value.toDate();
        break;
        case FinishDateRole:
            item.finish_Date = value.toDate();
        break;
        case CompanyRole:
            throw 20;
            //item.company = qvariant_cast<CompanyStruct>(value);
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ProjectModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable;
}

QHash<int, QByteArray> ProjectModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IdRole] = "id";
    names[NameRole] = "name";
    names[DescriptionRole] = "description";
    names[FinishedRole] = "finished";
    names[StartDateRole] = "startDate";
    names[FinishDateRole] = "finishDate";
    names[CompanyRole] = "company";
    return names;
}

ProjectList *ProjectModel::list() const
{
    return mList;
}

void ProjectModel::setList(ProjectList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &ProjectList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(mList, &ProjectList::postItemAppended, this, [=]() {
            endInsertRows();
        });


        connect(mList, &ProjectList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &ProjectList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
