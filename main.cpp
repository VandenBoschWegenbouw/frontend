#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>

//#include "Login/loginhandler.h"
//#include "HourRegistration/hourregistrationhandler.h"
//#include "Company/companymodel.h"
//#include "Company/companylist.h"

#include <Login/loginhandler.h>

#include <HourRegistration/hourregistrationmodel.h>
#include <HourRegistration/hourregistrationlist.h>
#include <HourRegistration/hourregistrationhandler.h>

#include <Company/companymodel.h>
#include <Company/companylist.h>
#include <Company/companyhandler.h>

#include <Projects/projectlist.h>
#include <Projects/projectmodel.h>
#include <Projects/projecthandler.h>

#include <UsedParts/usedpartslist.h>
#include <UsedParts/usedpartsmodel.h>
#include <UsedParts/usedpartshandler.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<CompanyModel>("vdBosch", 1,0, "CompanyModel");
    qmlRegisterUncreatableType<CompanyList>("vdBosch", 1,0, "CompanyList",
        QStringLiteral("CompanyList should not be created in QML"));

    qmlRegisterType<ProjectModel>("vdBosch", 1,0, "ProjectModel");
    qmlRegisterUncreatableType<ProjectList>("vdBosch",1,0,"ProjectList",
        QStringLiteral("ProjectList should not be created in QML"));

    qmlRegisterType<HourRegistrationModel>("vdBosch",1,0,"HourRegistrationModel");
    qmlRegisterUncreatableType<HourRegistrationList>("vdBosch",1,0,"HourRegistrationList",
        QStringLiteral("HourRegistrationList should not be created in QML"));

    qmlRegisterType<UsedPartsModel>("vdBosch",1,0, "UsedPartsModel");
    qmlRegisterUncreatableType<UsedPartsList>("vdBosch",1,0,"UsedPartsList",
        QStringLiteral("UsedPartsList should not be created in QML"));

    CompanyList companyList;
    ProjectList projectList;
    HourRegistrationList hourRegistrationList;
    UsedPartsList usedPartsList;

    LoginHandler lHandler;
    HourRegistrationHandler hHandler;
    CompanyHandler cHandler;
    ProjectHandler pHandler;
    UsedPartsHandler uPHandler;

    engine.rootContext()->setContextProperty("applicationPath", QGuiApplication::applicationDirPath());
    engine.rootContext()->setContextProperty("loginHandler", &lHandler);
    engine.rootContext()->setContextProperty("hourRegistrationHandler", &hHandler);
    engine.rootContext()->setContextProperty("companyHandler", &cHandler);
    engine.rootContext()->setContextProperty("projectHandler", &pHandler);
    engine.rootContext()->setContextProperty("usedPartsHandler", &uPHandler);

    engine.rootContext()->setContextProperty("companyList", &companyList);
    engine.rootContext()->setContextProperty("projectList", &projectList);
    engine.rootContext()->setContextProperty("hourRegistrationList", &hourRegistrationList);
    engine.rootContext()->setContextProperty("usedPartsList", &usedPartsList);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
