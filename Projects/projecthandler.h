#ifndef PROJECTHANDLER_H
#define PROJECTHANDLER_H

#include <QObject>

#include <Company/companylist.h>

#include <Projects/projectlist.h>
#include <Projects/projectcomponent.h>
#include <Projects/Export/exportcomponent.h>
#include <Projects/Create/createcomponent.h>

class ProjectHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)

public:
    explicit ProjectHandler(QObject *parent = nullptr);

    QString name() const;
    QString description() const;

    void setName(const QString& name);
    void setDescription(const QString& description);


public slots:
    void fetchProjectsByCompany(CompanyList *companyList, ProjectList *projectList, int indexSelectedCompany);

    void fetchProjects(ProjectList *list);

    void createProject(CompanyList *list, int index);

    void exportProject(int id);

signals:
    void nameChanged(const QString& name);
    void descriptionChanged(const QString& description);

private:
    QString mName;
    QString mDescription;


    ProjectComponent mComponent;
    ExportComponent mExportComponent;
    CreateComponent mCreateComponent;

};

#endif // PROJECTHANDLER_H
