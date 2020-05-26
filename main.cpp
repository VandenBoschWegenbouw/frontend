#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>

//#include "Login/loginhandler.h"
//#include "HourRegistration/hourregistrationhandler.h"
//#include "Company/companymodel.h"
//#include "Company/companylist.h"

#include <Login/loginhandler.h>
#include <HourRegistration/hourregistrationhandler.h>

#include <Company/companymodel.h>
#include <Company/companylist.h>
#include <Company/companyhandler.h>

#include <Projects/projectlist.h>
#include <Projects/projectmodel.h>
#include <Projects/projecthandler.h>

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

    CompanyList companyList;
    ProjectList projectList;
    LoginHandler lHandler;
    HourRegistrationHandler hHandler;
    CompanyHandler cHandler;
    ProjectHandler pHandler;

    engine.rootContext()->setContextProperty("applicationPath", QGuiApplication::applicationDirPath());
    engine.rootContext()->setContextProperty("loginHandler", &lHandler);
    engine.rootContext()->setContextProperty("hourRegistrationHandler", &hHandler);
    engine.rootContext()->setContextProperty("companyHandler", &cHandler);
    engine.rootContext()->setContextProperty("projectHandler", &pHandler);

    engine.rootContext()->setContextProperty("companyList", &companyList);
    engine.rootContext()->setContextProperty("projectList", &projectList);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
