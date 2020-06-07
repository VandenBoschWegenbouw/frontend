#include "createcompanycomponent.h"

#include <QJsonDocument>
#include <QJsonObject>

CreateCompanyComponent::CreateCompanyComponent(QObject *parent) : QObject(parent)
{

}

void CreateCompanyComponent::createCompany(CompanyStruct company)
{
    QJsonObject obj;

    obj["name"] = company.name;

    QJsonDocument doc(obj);

    QNetworkRequest request(QUrl("http://51.75.133.79:9000/company/"));
    request.setRawHeader("Content-Type", "application/json");



    manager.post(request, doc.toJson());
}
