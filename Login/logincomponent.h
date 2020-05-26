#ifndef LOGINCOMPONENT_H
#define LOGINCOMPONENT_H

#include <QString>
#include <QObject>
#include <QNetworkReply>
#include <Structs/LoginStruct.h>
#include <Structs/UserStruct.h>

class LoginComponent: public QObject
{
    Q_OBJECT
public:
    explicit LoginComponent(QObject *parent = nullptr);

    void login(LoginStruct user);

    static UserStruct user;

signals:
    void correctLogin();
    void incorrectLogin();

private slots:
    void _finished(QNetworkReply *);

private:
    QNetworkAccessManager manager;

};

#endif // LOGINCOMPONENT_H
