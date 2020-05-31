#ifndef COMPANYHANDLER_H
#define COMPANYHANDLER_H

#include <QObject>

#include <Company/Create/createcompanycomponent.h>

#include "companylist.h"
#include "companycomponent.h"

class CompanyHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit CompanyHandler(QObject *parent = nullptr);

    QString name() const;

    void setName(const QString& name);


public slots:
    void fetchCompanies(CompanyList *lst);

    void createCompany();

signals:
    void nameChanged(const QString& name);

private:
    QString mName;

    CompanyComponent mComponent;
    CreateCompanyComponent mCreateComponent;
};

#endif // COMPANYHANDLER_H
