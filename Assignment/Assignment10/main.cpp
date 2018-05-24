#include <QCoreApplication>
#include <QtCore>
#include <QThread>
#include <QDebug>
#include "controller.h"
#include "factorialworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

       Controller myController1;
       Controller myController2;
       Controller myController3;

       emit myController1.operateString("Thread 1"); //emit to make myController start to work
       emit myController1.operateInt(9);


       emit myController2.operateString("Thread 2"); //emit to make myController start to work
       emit myController2.operateInt(9);

       emit myController3.operateString("Thread 3"); //emit to make myController start to work
       emit myController3.operateInt(9);



    return a.exec();
}
