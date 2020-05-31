#ifndef REGISTERCOMPONENT_H
#define REGISTERCOMPONENT_H

#include <QNetworkAccessManager>
#include <QObject>
#include <Structs/UserStruct.h>
class RegisterComponent : public QObject
{
    Q_OBJECT

public:
    explicit RegisterComponent(QObject *parent = nullptr);

    void registerUser(UserStruct user);

signals:

private slots:
    void _finished(QNetworkReply *);

private:
    QNetworkAccessManager manager;
};

#endif // REGISTERCOMPONENT_H
