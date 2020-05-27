#ifndef HOURREGISTRATIONMODEL_H
#define HOURREGISTRATIONMODEL_H

#include <QAbstractListModel>

class HourRegistrationList;

class HourRegistrationModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(HourRegistrationList *list READ list WRITE setList)

public:
    explicit HourRegistrationModel(QObject *parent = nullptr);

    enum {
        IdRole,
        UserRole,
        ProjectRole,
        HoursRole,
        DateRole,
        DescriptionRole,
        CompanyRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    HourRegistrationList *list() const;
    void setList(HourRegistrationList *list);

private:
    HourRegistrationList *mList;
};

#endif // HOURREGISTRATIONMODEL_H
