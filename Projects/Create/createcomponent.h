#ifndef CREATECOMPONENT_H
#define CREATECOMPONENT_H

#include <QNetworkAccessManager>
#include <QObject>

#include <Structs/ProjectStruct.h>

class CreateComponent : public QObject
{
    Q_OBJECT
public:
    explicit CreateComponent(QObject *parent = nullptr);

    void createProject(ProjectStruct project);

signals:
private:
    QNetworkAccessManager manager;
};

#endif // CREATECOMPONENT_H
