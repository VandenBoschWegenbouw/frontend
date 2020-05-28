#ifndef EXPORTCOMPONENT_H
#define EXPORTCOMPONENT_H

#include <QObject>

#include <QNetworkAccessManager>

class ExportComponent : public QObject
{
    Q_OBJECT
public:
    explicit ExportComponent(QObject *parent = nullptr);

    void exportProjects(int id);

public slots:
    void _finished(QNetworkReply *reply);

signals:

private:
    QNetworkAccessManager manager;

};

#endif // EXPORTCOMPONENT_H
