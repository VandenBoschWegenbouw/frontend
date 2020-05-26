#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <QObject>
#include <Login/logincomponent.h>

class LoginHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)


public:
    explicit LoginHandler(QObject *parent = nullptr);

    QString username() const;
    QString password() const;

    void setUsername(const QString username);
    void setPassword(const QString password);

public slots:
    void login();
    void correctLoginReceived();
    void incorrectLoginReceived();

signals:
    void usernameChanged(const QString& username);
    void passwordChanged(const QString& password);
    void correctLogin();
    void incorrectLogin();

private:
    QString mUsername;
    QString mPassword;

    LoginComponent component;

};

#endif // LOGINHANDLER_H
