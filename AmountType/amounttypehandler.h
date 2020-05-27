#ifndef AMOUNTTYPEHANDLER_H
#define AMOUNTTYPEHANDLER_H

#include <QObject>

#include <AmountType/amounttypecomponent.h>
#include <AmountType/amounttypelist.h>

class AmountTypeHandler : public QObject
{
    Q_OBJECT
public:
    explicit AmountTypeHandler(QObject *parent = nullptr);

public slots:
    void fetchAmountTypes(AmountTypeList *atList);

signals:

private:
    AmountTypeComponent mComponent;
};

#endif // AMOUNTTYPEHANDLER_H
