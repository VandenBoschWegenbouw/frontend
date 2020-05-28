#ifndef PROJECTCOMPONENT_H
#define PROJECTCOMPONENT_H

#include <QObject>

#include <Projects/projectlist.h>

#include <QNetworkAccessManager>

class ProjectComponent : public QObject
{
    Q_OBJECT
public:
    explicit ProjectComponent(QObject *parent = nullptr);

    void fetchProjectsByCompany(ProjectList *list, int idCompany);

    void fetchProjects(ProjectList *list);

signals:

private slots:
    void _finished(QNetworkReply *);

private:
    ProjectList *mList;
    QNetworkAccessManager manager;

};

#endif // PROJECTCOMPONENT_H
