#ifndef COMPANYHANDLER_H
#define COMPANYHANDLER_H

#include <QObject>

#include "companylist.h"
#include "companycomponent.h"

class CompanyHandler : public QObject
{
    Q_OBJECT
public:
    explicit CompanyHandler(QObject *parent = nullptr);


public slots:
    void fetchCompanies(CompanyList *lst);

signals:

private:
    CompanyComponent mComponent;
};

#endif // COMPANYHANDLER_H
