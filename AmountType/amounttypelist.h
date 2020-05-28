#ifndef AMOUNTTYPELIST_H
#define AMOUNTTYPELIST_H

#include <QObject>

#include <Structs/AmountTypeStruct.h>

class AmountTypeList : public QObject
{
    Q_OBJECT
public:
    explicit AmountTypeList(QObject *parent = nullptr);

    QVector<AmountTypeStruct> items() const;

    bool setItemAt(int index, const AmountTypeStruct &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(AmountTypeStruct item);

    void clearList();

private:
    QVector<AmountTypeStruct> mItems;

};

#endif // AMOUNTTYPELIST_H
