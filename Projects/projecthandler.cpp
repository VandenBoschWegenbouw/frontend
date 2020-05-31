#include "projecthandler.h"

#include <QDebug>

ProjectHandler::ProjectHandler(QObject *parent) : QObject(parent)
{

}

QString ProjectHandler::name() const
{
    return mName;
}

QString ProjectHandler::description() const
{
    return mDescription;
}

void ProjectHandler::setName(const QString &name)
{
    if (mName == name)
        return;

    mName = name;
    emit nameChanged(mName);
}

void ProjectHandler::setDescription(const QString &description)
{
    if (mDescription == description)
        return;

    mDescription = description;
    emit descriptionChanged(mDescription);
}

void ProjectHandler::fetchProjectsByCompany(CompanyList *companyList, ProjectList *projectList, int indexSelectedCompany)
{
    CompanyStruct company;

    qDebug() << indexSelectedCompany;

    if (indexSelectedCompany >= 0 && companyList->items().size() > indexSelectedCompany) {
        company = companyList->items().at(indexSelectedCompany);
    }

    mComponent.fetchProjectsByCompany(projectList,company.id);
}

void ProjectHandler::fetchProjects(ProjectList *list)
{
    mComponent.fetchProjects(list);
}

void ProjectHandler::createProject(CompanyList *list, int index)
{
    CompanyStruct company = list->items().at(index);

    mCreateComponent.createProject({mName,mDescription, QDate::currentDate(), company});
}

void ProjectHandler::exportProject(int id)
{
    mExportComponent.exportProjects(id);
}
