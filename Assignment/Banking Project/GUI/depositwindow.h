#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QWidget>
#include "sav_dep_amount.h"
#include "che_dep_amount.h"

class QGroupBox;


class DepositWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DepositWindow(QWidget *parent = nullptr);

signals:

private slots:
    void Saving_Deposit();
    void Checking_Deposit();

private:
    QGroupBox *createActions();
    QGroupBox *groupBox;

    Sav_Dep_Amount *sDeInput;
    Che_Dep_Amount *cDeInput;

};

#endif // DEPOSITWINDOW_H
