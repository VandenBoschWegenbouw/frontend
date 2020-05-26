#ifndef COMPANYMODEL_H
#define COMPANYMODEL_H

#include <QAbstractListModel>

class CompanyList;

class CompanyModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(CompanyList *list READ list WRITE setList)

public:
    explicit CompanyModel(QObject *parent = nullptr);

    enum {
        IdRole,
        NameRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    CompanyList *list() const;
    void setList(CompanyList *list);

private:
    CompanyList *mList;
};

#endif // COMPANYMODEL_H
