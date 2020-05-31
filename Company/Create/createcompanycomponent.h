#ifndef CREATECOMPANYCOMPONENT_H
#define CREATECOMPANYCOMPONENT_H

#include <QNetworkAccessManager>
#include <QObject>

#include <Structs/CompanyStruct.h>

class CreateCompanyComponent : public QObject
{
    Q_OBJECT
public:
    explicit CreateCompanyComponent(QObject *parent = nullptr);

    void createCompany(CompanyStruct company);

signals:

private:
    QNetworkAccessManager manager;
};

#endif // CREATECOMPANYCOMPONENT_H
