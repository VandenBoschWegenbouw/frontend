#include "projecthandler.h"

#include <QDebug>

ProjectHandler::ProjectHandler(QObject *parent) : QObject(parent)
{

}

void ProjectHandler::fetchProjects(CompanyList *companyList, ProjectList *projectList, int indexSelectedCompany)
{
    CompanyStruct company = companyList->items().at(indexSelectedCompany);

    qDebug() << company.name;

    mComponent.fetchProjectsByCompany(projectList,company.id);
}


