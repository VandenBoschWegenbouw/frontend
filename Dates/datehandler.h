#ifndef DATEHANDLER_H
#define DATEHANDLER_H

#include <QObject>

#include <QDate>

class DateHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)

public:
    explicit DateHandler(QObject *parent = nullptr);

    QString date() const;
    void setDate(const QString& date);

public slots:
    void increaseDate();
    void decreaseDate();

signals:
    void dateChanged(const QString& date);

private:
    QDate mDate = QDate::currentDate();
};

#endif // DATEHANDLER_H
