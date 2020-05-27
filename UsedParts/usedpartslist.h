#ifndef USEDPARTSLIST_H
#define USEDPARTSLIST_H

#include <QObject>

#include <Structs/UsedPartsStruct.h>

class UsedPartsList : public QObject
{
    Q_OBJECT
public:
    explicit UsedPartsList(QObject *parent = nullptr);

    QVector<UsedPartsStruct> items() const;

    bool setItemAt(int index, const UsedPartsStruct &item);

signals:
    void preItemAppended();
    void postItemAppended();

public slots:
    void appendItem(UsedPartsStruct item);

private:
    QVector<UsedPartsStruct> mItems;

};

#endif // USEDPARTSLIST_H
