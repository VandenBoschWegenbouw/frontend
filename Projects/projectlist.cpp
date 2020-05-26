#include "projectlist.h"

ProjectList::ProjectList(QObject *parent) : QObject(parent)
{
}
QVector<ProjectStruct> ProjectList::items() const
{
    return mItems;
}

bool ProjectList::setItemAt(int index, const ProjectStruct &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const ProjectStruct &oldItem = mItems.at(index);
    if (item.id == oldItem.id && item.name == oldItem.name && item.finished == oldItem.finished && item.start_date == oldItem.start_date
            && item.finish_Date == oldItem.finish_Date && item.description == oldItem.description)
        return false;

    mItems[index] = item;
    return true;
}

void ProjectList::appendItem()
{
    emit preItemAppended();

    ProjectStruct project;
    project.id = -1;
    project.name = "This is a test project";
    project.company = {};
    project.finished = false;
    project.description = "This is a test description";
    project.start_date = QDate::currentDate();

    mItems.append(project);

    emit postItemAppended();
}

void ProjectList::appendItem(ProjectStruct item)
{
    emit preItemAppended();

    mItems.append(item);

    emit postItemAppended();
}