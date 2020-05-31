#include "registerhandler.h"

RegisterHandler::RegisterHandler(QObject *parent) : QObject(parent)
{

}

QString RegisterHandler::username() const
{
    return mUsername;
}

QString RegisterHandler::password() const
{
    return mPassword;
}

bool RegisterHandler::admin() const
{
    return mAdmin;
}

void RegisterHandler::setUsername(const QString &username)
{
    if (mUsername == username)
        return;

    mUsername = username;
    emit usernameChanged(mUsername);
}

void RegisterHandler::setPassword(const QString &password)
{
    if (mPassword == password)
        return;

    mPassword = password;
    emit passwordChanged(mPassword);
}

void RegisterHandler::setAdmin(const bool &admin)
{
    if (mAdmin == admin)
        return;

    mAdmin = admin;
    emit adminChanged(mAdmin);
}

void RegisterHandler::registerUser()
{
    UserStruct user = {mUsername, mPassword, mAdmin};

    mComponent.registerUser(user);
}
