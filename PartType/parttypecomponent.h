#ifndef PARTTYPECOMPONENT_H
#define PARTTYPECOMPONENT_H

#include <QObject>

#include <PartType/parttypelist.h>
#include <QNetworkAccessManager>

class PartTypeComponent : public QObject
{
    Q_OBJECT
public:
    explicit PartTypeComponent(QObject *parent = nullptr);

    void fetchPartTypes(PartTypeList *ptList);

private slots:
    void _finished(QNetworkReply *);

signals:

private:
    PartTypeList *mList;
    QNetworkAccessManager manager;


};

#endif // PARTTYPECOMPONENT_H
