#include "slot_class.h"
#include <QFuture>
#include <QThread>
#include <functional>
#include <QRandomGenerator>

/*
Initial constructor to the slot object
*/
slot_class::slot_class()
{
    slot_value = 0;
}

/*
Returns the int private data type 'slot_value' to requester
*/
int slot_class::ret_slot()
{
    return slot_value;
}

/*
Returns the Qchar private data type from const Vector to requester
This is for mappong out the slot machine from 0-6
*/
QChar slot_class::ret_char()
{
    return VSlot[slot_value];
}

/*
Generates a random number with the QRandomGenerator
Stores value on object for retrieval
*/
void slot_class::slot_gen()
{
    qDebug() << "Starting RNG from Thread:" << QThread::currentThread();
    slot_value = (QRandomGenerator::global()->generate())%7;
    qDebug() <<"debug msg slot_class::slot_gen: "<< slot_value;

}


