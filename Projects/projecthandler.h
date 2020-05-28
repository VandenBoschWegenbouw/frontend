#ifndef PROJECTHANDLER_H
#define PROJECTHANDLER_H

#include <QObject>

#include <Company/companylist.h>

#include <Projects/projectlist.h>
#include <Projects/projectcomponent.h>
#include <Projects/Export/exportcomponent.h>

class ProjectHandler : public QObject
{
    Q_OBJECT
public:
    explicit ProjectHandler(QObject *parent = nullptr);

public slots:
    void fetchProjectsByCompany(CompanyList *companyList, ProjectList *projectList, int indexSelectedCompany);

    void fetchProjects(ProjectList *list);

    void exportProject(int id);

signals:

private:
    ProjectComponent mComponent;
    ExportComponent mExportComponent;

};

#endif // PROJECTHANDLER_H
