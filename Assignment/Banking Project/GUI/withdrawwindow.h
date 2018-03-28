#ifndef WITHDRAWWINDOW_H
#define WITHDRAWWINDOW_H

#include <QWidget>
#include "che_wit_amount.h"
#include "sav_wit_amount.h"

class QGroupBox;

class WithdrawWindow : public QWidget
{
    Q_OBJECT
public:
    explicit WithdrawWindow(QWidget *parent = nullptr);

signals:

private slots:
    void Saving_Withdraw();
    void Checking_Withdraw();

private:
    QGroupBox *createActions();
    QGroupBox *groupBox;

    Sav_Wit_Amount *sWitInput;
    Che_Wit_Amount *cWitInput;

};

#endif // WITHDRAWWINDOW_H
