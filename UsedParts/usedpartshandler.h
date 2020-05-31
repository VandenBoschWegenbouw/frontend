#ifndef USEDPARTSHANDLER_H
#define USEDPARTSHANDLER_H

#include <QObject>

#include <UsedParts/usedpartscomponent.h>
#include <UsedParts/usedpartslist.h>

#include <PartType/parttypelist.h>
#include <AmountType/amounttypelist.h>
#include <Projects/projectlist.h>


class UsedPartsHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int partAmount READ partAmount WRITE setPartAmount NOTIFY partAmountChanged)
    Q_PROPERTY(QString specification READ specification WRITE setSpecification NOTIFY specificationChanged)

public:
    explicit UsedPartsHandler(QObject *parent = nullptr);

    int partAmount() const;
    QString specification() const;

    void setPartAmount(const int& partAmount);
    void setSpecification(const QString& specification);


public slots:
    void fetchUsedParts(UsedPartsList *upList);
    void fetchUsedParts(UsedPartsList *upList, QString date);

    void addUsedParts(PartTypeList *ptList, int ptIndex, AmountTypeList *atList, int atIndex, ProjectList *pList, int pIndex, UsedPartsList *upList);

signals:
    void partAmountChanged(const int& partAmount);
    void specificationChanged(const QString& specification);

private:
    int mPartAmount;
    QString mSpecification;

    UsedPartsComponent mComponent;

};

#endif // USEDPARTSHANDLER_H
