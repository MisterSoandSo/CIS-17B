#ifndef FACTORIALWORKER_H
#define FACTORIALWORKER_H

#include <QObject>
#include <QDebug>

class FactorialWorker: public QObject
{
    Q_OBJECT
public slots:
    void doWorkString(const QString &);
    void doWork(const int &);
signals:
    void resultReadyString(const QString &result);
    void resultReady(const int &result);
};

#endif // FACTORIALWORKER_H






