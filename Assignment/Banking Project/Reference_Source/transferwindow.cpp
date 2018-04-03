#include "transferwindow.h"
#include <QtWidgets>

TransferWindow::TransferWindow(QWidget *parent) : QWidget(parent)
{
    createTransferAction();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(transferFrom);
    mainLayout->addWidget(transferTo);
    mainLayout->addWidget(amount);
    setLayout(mainLayout);

    setWindowTitle(tr("Transfer"));

    setMinimumSize(440,380);
}
void TransferWindow::createTransferAction()
{
    transferFrom = new QGroupBox(tr("Transfer From:"));
    QHBoxLayout *layout = new QHBoxLayout;

    button = new QPushButton(tr("Checking"));
    button1 = new QPushButton(tr("Saving"));

    layout->addWidget(button);
    layout->addWidget(button1);

    transferTo = new QGroupBox(tr("Transfer To: "));
    QHBoxLayout *layout1 = new QHBoxLayout;

    button2 = new QPushButton(tr("Checking"));
    button3 = new QPushButton(tr("Saving"));

    layout1->addWidget(button2);
    layout1->addWidget(button3);


    transferFrom->setLayout(layout);
    transferTo->setLayout(layout1);

    amount = new QGroupBox(tr("Amount: "));
    QHBoxLayout *layout2 = new QHBoxLayout;
    label1 = new QLabel(tr("Input: "));
    echoLineEdit = new QLineEdit;
    echoLineEdit->setPlaceholderText("Enter amount");
    echoLineEdit->setFocus();

    layout2->addWidget(label1);
    layout2->addWidget(echoLineEdit);

    amount->setLayout(layout2);
}
