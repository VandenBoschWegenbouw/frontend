#ifndef PROJECTLIST_H
#define PROJECTLIST_H

#include <QObject>
#include <Structs/ProjectStruct.h>

class ProjectList : public QObject
{
    Q_OBJECT
public:
    explicit ProjectList(QObject *parent = nullptr);

    QVector<ProjectStruct> items() const;

    bool setItemAt(int index, const ProjectStruct &item);

signals:
    void preItemAppended();
    void postItemAppended();

public slots:
    void appendItem();
    void appendItem(ProjectStruct item);

private:
    QVector<ProjectStruct> mItems;

};

#endif // PROJECTLIST_H
