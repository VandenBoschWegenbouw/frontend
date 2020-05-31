#include "createcomponent.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>

CreateComponent::CreateComponent(QObject *parent) : QObject(parent)
{

}
void CreateComponent::createProject(ProjectStruct project)
{
    QJsonObject obj;
    QJsonObject company;


    company["idCompany"] = project.company.id;
    company["name"] = project.company.name;

    obj["name"] = project.name;
    obj["description"] = project.description;
    obj["startDate"] = project.start_date.toString("yyyy-MM-dd") + "T00:00:00";
    obj["isFinished"] = false;
    obj["company"] = company;

    QJsonDocument doc(obj);

    QNetworkRequest request(QUrl("http://localhost:9000/projects/"));
    request.setRawHeader("Content-Type", "application/json");

    manager.post(request, doc.toJson());
}
