#ifndef COMPANYCOMPONENT_H
#define COMPANYCOMPONENT_H

#include <QObject>
#include <QNetworkReply>

#include <Company/companylist.h>

class CompanyComponent : public QObject
{
    Q_OBJECT
public:
    explicit CompanyComponent(QObject *parent = nullptr);

    void fetchCompanies(CompanyList *lst);

private slots:
    void _finished(QNetworkReply *);

private:
    CompanyList *mList;
    QNetworkAccessManager manager;

};

#endif // COMPANYCOMPONENT_H
