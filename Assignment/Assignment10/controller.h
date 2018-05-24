#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include "factorialworker.h"

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
   public:
       Controller();
       ~Controller();
   public slots:
       void handleResultsString(const QString &result);
       void handleResultsInt(const int &result);

   signals:
       void operateString(const QString &);
       void operateInt(const int &);

};

#endif // CONTROLLER_H


