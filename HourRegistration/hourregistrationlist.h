#ifndef HOURREGISTRATIONLIST_H
#define HOURREGISTRATIONLIST_H

#include <QObject>
#include <Structs/HourRegistrationStruct.h>

class HourRegistrationList : public QObject
{
    Q_OBJECT
public:
    explicit HourRegistrationList(QObject *parent = nullptr);

    QVector<HourRegistrationStruct> items() const;

    bool setItemAt(int index, const HourRegistrationStruct &item);

signals:
    void preItemAppended();
    void postItemAppended();

public slots:
    void appendItem(HourRegistrationStruct item);

private:
    QVector<HourRegistrationStruct> mItems;

};

#endif // HOURREGISTRATIONLIST_H
