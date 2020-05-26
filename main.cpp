#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>

#include "Login/loginhandler.h"
#include "HourRegistration/hourregistrationhandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    LoginHandler lHandler;
    HourRegistrationHandler hHandler;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("applicationPath", QGuiApplication::applicationDirPath());
    engine.rootContext()->setContextProperty("loginHandler", &lHandler);
    engine.rootContext()->setContextProperty("hourRegistrationHandler", &hHandler);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
