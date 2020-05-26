#ifndef USERSTRUCT_H
#define USERSTRUCT_H

#include <QString>

struct UserStruct {
    int id;
    QString username;
    QString password;
    bool admin;
};

extern UserStruct user;

#endif // USERSTRUCT_H
