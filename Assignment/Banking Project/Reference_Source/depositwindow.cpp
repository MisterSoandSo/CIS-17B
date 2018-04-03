#include "depositwindow.h"
#include <QtWidgets>

DepositWindow::DepositWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createActions(),0,0);

    setLayout(grid);

    setMinimumSize(350,200);

    setWindowTitle(tr("Deposit Window"));
}

QGroupBox*DepositWindow::createActions()
{
    QGroupBox *groupBox = new QGroupBox(tr("Deposit"));
    QPushButton *savingButton = new QPushButton(tr("Saving Account"));
    QPushButton *checkingButton = new QPushButton(tr("Checking Account"));

    QObject::connect(savingButton, SIGNAL (clicked()),this, SLOT (Saving_Deposit()));
    QObject::connect(checkingButton, SIGNAL (clicked()),this, SLOT (Checking_Deposit()));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(savingButton);
    vbox->addWidget(checkingButton);
    groupBox->setLayout(vbox);

    return groupBox;
}

void DepositWindow::Saving_Deposit()
{
    Sav_Dep_Amount *sDeInput = new Sav_Dep_Amount();
    sDeInput->show();
}

void DepositWindow::Checking_Deposit()
{
    Che_Dep_Amount *cDeInput = new Che_Dep_Amount();
    cDeInput->show();
}
