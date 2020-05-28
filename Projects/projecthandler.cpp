#include "projecthandler.h"

#include <QDebug>

ProjectHandler::ProjectHandler(QObject *parent) : QObject(parent)
{

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

void ProjectHandler::exportProject(int id)
{
    mExportComponent.exportProjects(id);
}
