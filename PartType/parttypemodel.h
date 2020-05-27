#ifndef PARTTYPEMODEL_H
#define PARTTYPEMODEL_H

#include <QAbstractListModel>

class PartTypeList;

class PartTypeModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(PartTypeList *list READ list WRITE setList)

public:
    explicit PartTypeModel(QObject *parent = nullptr);

    enum {
        IdRole,
        TypeRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual  QHash<int, QByteArray> roleNames() const override;

    PartTypeList *list() const;
    void setList(PartTypeList *list);

private:
    PartTypeList *mList;
};

#endif // PARTTYPEMODEL_H
