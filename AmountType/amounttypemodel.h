#ifndef AMOUNTTYPEMODEL_H
#define AMOUNTTYPEMODEL_H

#include <QAbstractListModel>

class AmountTypeList;

class AmountTypeModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(AmountTypeList *list READ list WRITE setList)

public:
    explicit AmountTypeModel(QObject *parent = nullptr);

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

    AmountTypeList *list() const;
    void setList(AmountTypeList *list);

private:
    AmountTypeList *mList;
};

#endif // AMOUNTTYPEMODEL_H
