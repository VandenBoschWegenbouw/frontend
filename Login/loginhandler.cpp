#include "loginhandler.h"
#include <QDebug>

LoginHandler::LoginHandler(QObject *parent) : QObject(parent)
{
    connect(&component, &LoginComponent::correctLogin, this, &LoginHandler::correctLoginReceived);
    connect(&component, &LoginComponent::incorrectLogin, this, &LoginHandler::incorrectLoginReceived);
}

QString LoginHandler::username() const
{
    return mUsername;
}

QString LoginHandler::password() const
{
    return mPassword;
}

void LoginHandler::setUsername(const QString username)
{
    if (username == mUsername) return;
    mUsername = username;
    emit usernameChanged(mUsername);
}

void LoginHandler::setPassword(const QString password)
{
    if (password == mPassword) return;
    mPassword = password;
    emit passwordChanged(mPassword);
}

void LoginHandler::login() {
    component.login({mUsername, mPassword});
}

void LoginHandler::correctLoginReceived()
{
    emit correctLogin();
}

void LoginHandler::incorrectLoginReceived()
{
    emit incorrectLogin();
}
