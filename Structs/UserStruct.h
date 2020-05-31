#ifndef USERSTRUCT_H
#define USERSTRUCT_H

#include <QString>

struct UserStruct {
    int id;
    QString username;
    QString password;
    bool admin;

    UserStruct(int id, QString username, QString password, bool admin) {
        this->id = id;
        this->username = username;
        this->password = password;
        this->admin = admin;
    }
    UserStruct(QString username, QString password, bool admin) {
        this->username = username;
        this->password = password;
        this->admin = admin;
    }
    UserStruct(){}
};

extern UserStruct user;

#endif // USERSTRUCT_H
