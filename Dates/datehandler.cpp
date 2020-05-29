#include "datehandler.h"

#include <QDebug>

DateHandler::DateHandler(QObject *parent) : QObject(parent)
{

}

QString DateHandler::date() const
{
    return mDate.toString("dd-MM-yyyy");
}

void DateHandler::setDate(const QString &date)
{
    QDate qDate = QDate::fromString(date);

    if (qDate == mDate)
        return;

    mDate = qDate;
    emit dateChanged(mDate.toString("dd-MM-yyyy"));
}

void DateHandler::increaseDate()
{
    QDateTime dayAfter(mDate.addDays(1));

    if (!(QDateTime::currentDateTime().toTime_t() < dayAfter.toTime_t())) {
        mDate = mDate.addDays(1);
    }

    emit dateChanged(mDate.toString("dd-MM-yyyy"));
}

void DateHandler::decreaseDate()
{
    mDate = mDate.addDays(-1);

    emit dateChanged(mDate.toString("dd-MM-yyyy"));
}
