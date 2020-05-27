#ifndef PARTTYPEHANDLER_H
#define PARTTYPEHANDLER_H

#include <QObject>

#include <PartType/parttypecomponent.h>
#include <PartType/parttypelist.h>

class PartTypeHandler : public QObject
{
    Q_OBJECT
public:
    explicit PartTypeHandler(QObject *parent = nullptr);

public slots:
    void fetchPartTypes(PartTypeList *ptList);

signals:

private:
    PartTypeComponent mComponent;

};

#endif // PARTTYPEHANDLER_H
