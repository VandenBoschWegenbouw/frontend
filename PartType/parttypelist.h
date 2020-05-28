#ifndef PARTTYPELIST_H
#define PARTTYPELIST_H

#include <QObject>

#include <Structs/PartTypeStruct.h>

class PartTypeList : public QObject
{
    Q_OBJECT
public:
    explicit PartTypeList(QObject *parent = nullptr);

    QVector<PartTypeStruct> items() const;

    bool setItemAt(int index, const PartTypeStruct &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(PartTypeStruct item);

    void clearList();


private:
    QVector<PartTypeStruct> mItems;
};

#endif // PARTTYPELIST_H
