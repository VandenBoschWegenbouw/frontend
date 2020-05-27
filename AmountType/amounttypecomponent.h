#ifndef AMOUNTTYPECOMPONENT_H
#define AMOUNTTYPECOMPONENT_H

#include <QObject>

#include <AmountType/amounttypelist.h>
#include <QNetworkAccessManager>

class AmountTypeComponent : public QObject
{
    Q_OBJECT
public:
    explicit AmountTypeComponent(QObject *parent = nullptr);

    void fetchAmountTypes(AmountTypeList *atList);

private slots:
    void _finished(QNetworkReply *);

signals:

private:
    AmountTypeList *mList;
    QNetworkAccessManager manager;

};

#endif // AMOUNTTYPECOMPONENT_H
