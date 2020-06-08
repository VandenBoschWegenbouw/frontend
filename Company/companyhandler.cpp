#include "companyhandler.h"

#include <QDebug>

CompanyHandler::CompanyHandler(QObject *parent) : QObject(parent)
{

}

QString CompanyHandler::name() const
{
    return mName;
}

void CompanyHandler::setName(const QString &name)
{
    if (mName == name)
        return;

    mName = name;
    emit nameChanged(mName);
}

void CompanyHandler::fetchCompanies(CompanyList *lst)
{
    mComponent.fetchCompanies(lst);
}

void CompanyHandler::createCompany()
{
    mCreateComponent.createCompany({mName});
}
