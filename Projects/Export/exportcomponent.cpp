#include "exportcomponent.h"

#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QString>
#include <QStandardPaths>

#include <Structs/CompanyStruct.h>
#include <Structs/UserStruct.h>
#include <Structs/ProjectStruct.h>
#include <Structs/HourRegistrationStruct.h>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

ExportComponent::ExportComponent(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &ExportComponent::_finished);
}

void ExportComponent::exportProjects(int id)
{
    const QString url = "http://51.75.133.79:9000/projects/" + QString::number(id) + "/hourregistration";

    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    manager.get(request);
}

void ExportComponent::_finished(QNetworkReply *reply)
{
    QByteArray arr = reply->readAll();

    QVector<HourRegistrationStruct> hrs;

    if (arr.size() > 0) {

        QJsonDocument doc = QJsonDocument::fromJson(arr);

        QJsonArray jsonArr = doc.array();

        if (jsonArr.size() == 0 && !doc.object().isEmpty()) {
            QJsonObject obj = doc.object();
            QJsonObject jsonUser = obj["user"].toObject();
            QJsonObject jsonCompany = obj["project"].toObject()["company"].toObject();
            QJsonObject jsonProject = obj["project"].toObject();

            CompanyStruct company = {jsonCompany["idCompany"].toInt(), jsonCompany["name"].toString()};
            ProjectStruct project = {jsonProject["idProject"].toInt(), jsonProject["name"].toString(), jsonProject["description"].toString(), jsonProject["finished"].toBool(),jsonProject["startDate"].toVariant().toDate(), jsonProject["finishDate"].toVariant().toDate(), company};
            UserStruct user = {jsonUser["idUser"].toInt(), jsonUser["username"].toString(), jsonUser["password"].toString(), jsonUser["isAdmin"].toBool()};

            hrs.append({obj["idHourRegistration"].toInt(),user,project, obj["hours"].toInt(),obj["date"].toVariant().toDate(),obj["description"].toString()});
        } else {
            foreach(const QJsonValue &value, jsonArr) {
                QJsonObject obj = value.toObject();
                QJsonObject jsonUser = obj["user"].toObject();
                QJsonObject jsonCompany = obj["project"].toObject()["company"].toObject();
                QJsonObject jsonProject = obj["project"].toObject();

                CompanyStruct company = {jsonCompany["idCompany"].toInt(), jsonCompany["name"].toString()};
                ProjectStruct project = {jsonProject["idProject"].toInt(), jsonProject["name"].toString(), jsonProject["description"].toString(), jsonProject["finished"].toBool(),jsonProject["startDate"].toVariant().toDate(), jsonProject["finishDate"].toVariant().toDate(), company};
                UserStruct user = {jsonUser["idUser"].toInt(), jsonUser["username"].toString(), jsonUser["password"].toString(), jsonUser["isAdmin"].toBool()};

                hrs.append({obj["idHourRegistration"].toInt(),user,project, obj["hours"].toInt(),obj["date"].toVariant().toDate(),obj["description"].toString()});
            }
        }

        QXlsx::Document excelFile;

        excelFile.write("A1", "Project");
        excelFile.write("B1", hrs.first().project.name);
        excelFile.write("C1", "Klant");
        excelFile.write("D1", hrs.first().project.company.name);

        excelFile.write("A2", "Datum");
        excelFile.write("B2", "Gewerkte uren");
        excelFile.write("C2", "Medewerker");
        excelFile.write("D2", "Beschrijving");



        for (int i = 0; i < hrs.size(); i++) {
            excelFile.write("A" + QString::number(i+3), hrs.at(i).date);
            excelFile.write("B" + QString::number(i+3), hrs.at(i).hours);
            excelFile.write("C" + QString::number(i+3), hrs.at(i).user.username);
            excelFile.write("D" + QString::number(i+3), hrs.at(i).description);
        }

        QString path = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation) + "/" +  hrs.first().project.name + ".xlsx";

        qDebug() << path;


        excelFile.saveAs(path);

    }
}
