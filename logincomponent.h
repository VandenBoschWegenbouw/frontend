#ifndef LOGINCOMPONENT_H
#define LOGINCOMPONENT_H

#include <QString>
#include <servercommunicator.h>

struct LoginStruct {
    QString username;
    QString password;
};

class LoginComponent: public QObject
{
    Q_OBJECT
public:
    explicit LoginComponent(QObject *parent = nullptr);

    void login(LoginStruct user);

signals:
    void correctLogin();
    void incorrectLogin();

private:
    ServerCommunicator communicator;

private slots:
    void _finished(QNetworkReply *);
};

#endif // LOGINCOMPONENT_H
