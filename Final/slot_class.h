#ifndef SLOT_CLASS_H
#define SLOT_CLASS_H

#include <QChar>
#include <QVector>
#include <QObject>
#include <QtWidgets>
#include <QDebug>

class slot_class: public QThread
{
    Q_OBJECT
    public:
        slot_class();
        void slot_gen();
        int ret_slot();
        QChar ret_char();

    private:
        int slot_value;
        const QVector<QChar> VSlot = {'G','A','B','C','D','E','F'};

};

#endif // SLOT_CLASS_H
