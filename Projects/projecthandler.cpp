#include "projecthandler.h"

#include <QDebug>

ProjectHandler::ProjectHandler(QObject *parent) : QObject(parent)
{

}

void ProjectHandler::fetchProjects(CompanyList *companyList, ProjectList *projectList, int indexSelectedCompany)
{
    CompanyStruct company;

    qDebug() << indexSelectedCompany;

    if (indexSelectedCompany >= 0 && companyList->items().size() > indexSelectedCompany) {
        company = companyList->items().at(indexSelectedCompany);
    }

    mComponent.fetchProjectsByCompany(projectList,company.id);
}
