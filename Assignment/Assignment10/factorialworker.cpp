#include "factorialworker.h"
#include <QMutex>

void FactorialWorker::doWorkString(const QString &parameter)
{
    QMutex mutex;
    mutex.lock();
    qDebug() << parameter;
    emit resultReadyString(parameter);
    mutex.unlock();
}
void FactorialWorker::doWork(const int &parameter)
{
    QMutex mutex;
    mutex.lock();

    int factorial =1;       ///calculate factorial
    for(int i = parameter; i >=1; --i)
        {
            qDebug() << factorial;
            factorial *= i;


        }
    emit resultReady(factorial);
    mutex.unlock();
}
