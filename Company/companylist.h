#ifndef COMPANYLIST_H
#define COMPANYLIST_H

#include <QObject>
#include <QVector>
#include <Structs/CompanyStruct.h>


class CompanyList : public QObject
{
    Q_OBJECT
public:
    explicit CompanyList(QObject *parent = nullptr);

    QVector<CompanyStruct> items() const;

    bool setItemAt(int index, const CompanyStruct &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem();
    void appendItem(CompanyStruct item);

    void clearList();

private:
    QVector<CompanyStruct> mItems;

};

#endif // COMPANYLIST_H
