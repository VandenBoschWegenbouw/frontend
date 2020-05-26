#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include <QAbstractListModel>

#include <Projects/projectlist.h>

class ProjectList;

class ProjectModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ProjectList *list READ list WRITE setList)

public:
    explicit ProjectModel(QObject *parent = nullptr);

    enum {
        IdRole,
        NameRole,
        CompanyRole,
        StartDateRole,
        FinishDateRole,
        FinishedRole,
        DescriptionRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    ProjectList *list() const;
    void setList(ProjectList *list);

private:
    ProjectList *mList;

};

#endif // PROJECTMODEL_H
