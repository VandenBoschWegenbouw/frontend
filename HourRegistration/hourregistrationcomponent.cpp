#include "hourregistrationcomponent.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

#include <Login/logincomponent.h>

HourRegistrationComponent::HourRegistrationComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &HourRegistrationComponent::_finished);
}

void HourRegistrationComponent::fetchHours(HourRegistrationList *list, QDate date)
{
    mList = list;

    fetchedDate = date;

    UserStruct user = LoginComponent::user;
    QString url = "http://localhost:9000/hourregistration/" + date.toString("yyyy-MM-dd") + "/user/" + QString::number(user.id);

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void HourRegistrationComponent::addHours(HourRegistrationStruct hr, HourRegistrationList *list)
{
    mList = list;

    QJsonObject obj;

    QJsonObject user;
    QJsonObject company;
    QJsonObject project;

    user["idUser"] = hr.user.id;
    user["username"] = hr.user.username;
    user["password"] = hr.user.password;
    user["isAdmin"] = hr.user.admin;

    company["idCompany"] = hr.project.company.id;
    company["name"] = hr.project.company.name;

    project["idProject"] = hr.project.id;
    project["description"] = hr.project.description;
    project["isFinished"] = hr.project.finished;
    project["startDate"] = hr.project.start_date.toString("yyyy-MM-dd") + "T00:00:00";
    if (!hr.project.finish_Date.isNull()) {
        project["finishDate"] = hr.project.finish_Date.toString("yyyy-MM-ddT00:00:00");
    }
    project["name"] = hr.project.name;
    project["company"] = company;


    obj["hours"] = hr.hours;
    obj["date"] = hr.date.toString("yyyy-MM-dd") + "T12:00:00";
    obj["description"] = hr.description;
    obj["user"] = user;
    obj["project"] = project;

    QJsonDocument doc(obj);

    QNetworkRequest request(QUrl("http://localhost:9000/hourregistration/"));
    request.setRawHeader("Content-Type", "application/json");

    manager.post(request, doc.toJson());
}

void HourRegistrationComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    if (arr.size() > 0) {
        QJsonDocument doc = QJsonDocument::fromJson(arr);

        QJsonArray jsonArr = doc.array();

        if (jsonArr.size() > 0) {
            mList->clearList();
        }

        if (jsonArr.size() == 0 && !doc.object().isEmpty()) {
            QJsonObject obj = doc.object();
            QJsonObject jsonUser = obj["user"].toObject();
            QJsonObject jsonCompany = obj["project"].toObject()["company"].toObject();
            QJsonObject jsonProject = obj["project"].toObject();

            CompanyStruct company = {jsonCompany["idCompany"].toInt(), jsonCompany["name"].toString()};
            ProjectStruct project = {jsonProject["idProject"].toInt(), jsonProject["name"].toString(), jsonProject["description"].toString(), jsonProject["isFinished"].toBool(),jsonProject["startDate"].toVariant().toDate(), jsonProject["finishDate"].toVariant().toDate(), company};
            UserStruct user = {jsonUser["idUser"].toInt(), jsonUser["username"].toString(), jsonUser["password"].toString(), jsonUser["isAdmin"].toBool()};

            if (obj["date"].toVariant().toDate() == fetchedDate) {
                mList->appendItem({obj["idHourRegistration"].toInt(),user,project, obj["hours"].toInt(),obj["date"].toVariant().toDate(),obj["description"].toString()});
            }
        } else {
            foreach(const QJsonValue &value, jsonArr) {
                QJsonObject obj = value.toObject();
                QJsonObject jsonUser = obj["user"].toObject();
                QJsonObject jsonCompany = obj["project"].toObject()["company"].toObject();
                QJsonObject jsonProject = obj["project"].toObject();

                CompanyStruct company = {jsonCompany["idCompany"].toInt(), jsonCompany["name"].toString()};
                ProjectStruct project = {jsonProject["idProject"].toInt(), jsonProject["name"].toString(), jsonProject["description"].toString(), jsonProject["isFinished"].toBool(),jsonProject["startDate"].toVariant().toDate(), jsonProject["finishDate"].toVariant().toDate(), company};
                UserStruct user = {jsonUser["idUser"].toInt(), jsonUser["username"].toString(), jsonUser["password"].toString(), jsonUser["isAdmin"].toBool()};

                if (obj["date"].toVariant().toDate() == fetchedDate) {
                    mList->appendItem({obj["idHourRegistration"].toInt(),user,project, obj["hours"].toInt(),obj["date"].toVariant().toDate(),obj["description"].toString()});
                }
            }
        }
    } else {
        emit workedTooHard();
    }
}


