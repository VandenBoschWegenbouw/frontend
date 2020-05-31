#ifndef REGISTERHANDLER_H
#define REGISTERHANDLER_H

#include <QObject>

#include <Register/registercomponent.h>

class RegisterHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(bool admin READ admin WRITE setAdmin NOTIFY adminChanged)

public:
    explicit RegisterHandler(QObject *parent = nullptr);

    QString username() const;
    QString password() const;
    bool admin() const;

    void setUsername(const QString& username);
    void setPassword(const QString& password);
    void setAdmin(const bool& admin);

public slots:
    void registerUser();

signals:
    void usernameChanged(const QString& username);
    void passwordChanged(const QString& password);
    void adminChanged(const bool& admin);

private:
    QString mUsername;
    QString mPassword;
    bool mAdmin;

    RegisterComponent mComponent;

};

#endif // REGISTERHANDLER_H
