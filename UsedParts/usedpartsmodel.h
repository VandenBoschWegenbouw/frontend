#ifndef USEDPARTSMODEL_H
#define USEDPARTSMODEL_H

#include <QAbstractListModel>

class UsedPartsList;

class UsedPartsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(UsedPartsList *list READ list WRITE setList)

public:
    explicit UsedPartsModel(QObject *parent = nullptr);

    enum {
        IdRole,
        AmountRole,
        SpecificationRole,
        DateRole,
        PartTypeRole,
        AmountTypeRole,
        ProjectRole,
        UserRole,
        CompanyRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual  QHash<int, QByteArray> roleNames() const override;

    UsedPartsList *list() const;
    void setList(UsedPartsList *list);

private:
    UsedPartsList *mList;
};

#endif // USEDPARTSMODEL_H
