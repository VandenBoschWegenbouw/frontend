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

#include <PartType/parttypelist.h>
#include <PartType/parttypemodel.h>
#include <PartType/parttypehandler.h>

#include <AmountType/amounttypelist.h>
#include <AmountType/amounttypemodel.h>
#include <AmountType/amounttypehandler.h>

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

    qmlRegisterType<PartTypeModel>("vdBosch",1,0, "PartTypeModel");
    qmlRegisterUncreatableType<PartTypeList>("vdBosch",1,0,"PartTypeList",
        QStringLiteral("PartTypeList should not be created in QML"));

    qmlRegisterType<AmountTypeModel>("vdBosch",1,0, "AmountTypeModel");
    qmlRegisterUncreatableType<AmountTypeList>("vdBosch",1,0,"AmountTypeList",
        QStringLiteral("AmountTypeList should not be created in QML"));

    CompanyList companyList;
    ProjectList projectList;
    HourRegistrationList hourRegistrationList;
    UsedPartsList usedPartsList;
    PartTypeList partTypeList;
    AmountTypeList amountTypeList;

    LoginHandler lHandler;
    HourRegistrationHandler hHandler;
    CompanyHandler cHandler;
    ProjectHandler pHandler;
    UsedPartsHandler uPHandler;
    PartTypeHandler ptHandler;
    AmountTypeHandler atHandler;

    engine.rootContext()->setContextProperty("applicationPath", QGuiApplication::applicationDirPath());
    engine.rootContext()->setContextProperty("loginHandler", &lHandler);
    engine.rootContext()->setContextProperty("hourRegistrationHandler", &hHandler);
    engine.rootContext()->setContextProperty("companyHandler", &cHandler);
    engine.rootContext()->setContextProperty("projectHandler", &pHandler);
    engine.rootContext()->setContextProperty("usedPartsHandler", &uPHandler);
    engine.rootContext()->setContextProperty("partTypeHandler", &ptHandler);
    engine.rootContext()->setContextProperty("amountTypeHandler", &atHandler);

    engine.rootContext()->setContextProperty("companyList", &companyList);
    engine.rootContext()->setContextProperty("projectList", &projectList);
    engine.rootContext()->setContextProperty("hourRegistrationList", &hourRegistrationList);
    engine.rootContext()->setContextProperty("usedPartsList", &usedPartsList);
    engine.rootContext()->setContextProperty("partTypeList", &partTypeList);
    engine.rootContext()->setContextProperty("amountTypeList", &amountTypeList);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
