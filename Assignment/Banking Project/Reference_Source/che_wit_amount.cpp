#include "che_wit_amount.h"
#include <QtWidgets>

Che_Wit_Amount::Che_Wit_Amount(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    QLabel *label = new QLabel(tr("Withdraw Amount Into Checking Account: "));
    QLineEdit *lineEdit = new QLineEdit();
    QPushButton *OkBtn = new QPushButton(tr("OK"));

    //connect OK button
    //QObject::connect(SIGNAL, (clicked()), this, SLOT (OkButton()));

    grid->addWidget(label,0,0);
    grid->addWidget(lineEdit,0,1);
    grid->addWidget(OkBtn,1,2);

    setLayout(grid);

    setMinimumSize(350,200);

    setWindowTitle(tr("Withdraw Input"));
}
void Che_Wit_Amount::OkButton()
{

}
