#include "companyhandler.h"

#include <QDebug>

CompanyHandler::CompanyHandler(QObject *parent) : QObject(parent)
{

}

void CompanyHandler::fetchCompanies(CompanyList *lst)
{
    mComponent.fetchCompanies(lst);
}
