#include "loginhandler.h"
#include <QDebug>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include <QFileDialog>

LoginHandler::LoginHandler(QObject *parent) : QObject(parent)
{
    connect(&component, &LoginComponent::correctLogin, this, &LoginHandler::correctLoginReceived);
    connect(&component, &LoginComponent::correctAdminLogin, this, &LoginHandler::correctAdminLoginReceived);
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

void LoginHandler::correctAdminLoginReceived()
{
    emit correctAdminLogin();
}

void LoginHandler::incorrectLoginReceived()
{
    emit incorrectLogin();
}
