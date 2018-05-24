#include "controller.h"
#include <QDebug>

Controller::Controller()
{
    FactorialWorker *fworker = new FactorialWorker;
    fworker->moveToThread(&workerThread);

    connect(&workerThread, &QThread::finished, fworker, &QObject::deleteLater);

    connect(this, &Controller::operateString, fworker, &FactorialWorker::doWorkString);
    connect(this, &Controller::operateInt, fworker, &FactorialWorker::doWork);


    connect(fworker, &FactorialWorker::resultReadyString, this, &Controller::handleResultsString);
    connect(fworker, &FactorialWorker::resultReady, this, &Controller::handleResultsInt);


    workerThread.start();
}

void Controller::handleResultsString(const QString &result)
{
    qDebug() << "Printed from handleResultsString: " << result;
}

void Controller::handleResultsInt(const int &result)
{

    qDebug() << "Printed from handleResultsInt: " << result;

}



Controller::~Controller() {
    workerThread.quit();
    workerThread.wait();
}
