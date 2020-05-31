#ifndef COMPANYSTRUCT_H
#define COMPANYSTRUCT_H

#include <QString>

struct CompanyStruct {
    int id;
    QString name;

    CompanyStruct(int id, QString name) {
        this->id = id;
        this->name = name;
    }
    CompanyStruct(QString name) {
        this->name = name;
    }

    CompanyStruct() {

    }
};

#endif // COMPANYSTRUCT_H
