#include "withdrawwindow.h"
#include <QtWidgets>

WithdrawWindow::WithdrawWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createActions(),0,0);

    setLayout(grid);

    setMinimumSize(350,200);

    setWindowTitle(tr("Withdraw Window"));
}

QGroupBox *WithdrawWindow::createActions()
{
    QGroupBox *groupBox = new QGroupBox(tr("Withdraw"));
    QPushButton *savingButton = new QPushButton(tr("Saving Account"));
    QPushButton *checkingButton = new QPushButton(tr("Checking Account"));

    QObject::connect(savingButton, SIGNAL (clicked()),this, SLOT (Saving_Withdraw()));
    QObject::connect(checkingButton, SIGNAL (clicked()),this, SLOT (Checking_Withdraw()));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(savingButton);
    vbox->addWidget(checkingButton);
    groupBox->setLayout(vbox);

    return groupBox;
}

void WithdrawWindow::Saving_Withdraw()
{
    Sav_Wit_Amount *sWitInput = new Sav_Wit_Amount();
    sWitInput->show();
}

void WithdrawWindow::Checking_Withdraw()
{
    Che_Wit_Amount *cWitInput = new Che_Wit_Amount();
    cWitInput->show();
}
