#ifndef PROJECTHANDLER_H
#define PROJECTHANDLER_H

#include <QObject>

#include <Company/companylist.h>

#include <Projects/projectlist.h>
#include <Projects/projectcomponent.h>

class ProjectHandler : public QObject
{
    Q_OBJECT
public:
    explicit ProjectHandler(QObject *parent = nullptr);

public slots:
    void fetchProjects(CompanyList *companyList, ProjectList *projectList, int indexSelectedCompany);

signals:

private:
    ProjectComponent mComponent;

};

#endif // PROJECTHANDLER_H
