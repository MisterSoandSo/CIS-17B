#include <QtWidgets>
#include <Qt>
#include "mainwindow.h"
#include "login.h"

MainWindow::MainWindow()
{
    updatestrUsername("Guest");
    updatestrUser_Acc("0000");
    updatestrUser_BAL("0.00");

    createMenu();
    createHGBAccountBalance();
    createHGBAccountSelector();
    createHGBAccountActions();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout -> setMenuBar(menuBar);
    mainLayout -> addWidget(HGBAccountBalance);
    mainLayout -> addWidget(HGBAccountSelector);
    mainLayout -> addWidget(HGBAccountActions);

    setLayout(mainLayout);

    setWindowTitle(tr("Banking GUI"));
    setMinimumSize(520, 360);

}
MainWindow::MainWindow(database d)
{
    updatestrUsername(d.getUser());
    updatestrUser_Acc(QString::number(d.getAccCheck()));
    updatestrUser_BAL(QString::number(d.getchecking_bal()));
    createMenu();
    createHGBAccountBalance();
    createHGBAccountSelector();
    createHGBAccountActions();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout -> setMenuBar(menuBar);
    mainLayout -> addWidget(HGBAccountBalance);
    mainLayout -> addWidget(HGBAccountSelector);
    mainLayout -> addWidget(HGBAccountActions);

    setLayout(mainLayout);

    setWindowTitle(tr("Banking GUI"));
    setMinimumSize(520, 360);

}

void MainWindow::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);

    aboutMenu = new QMenu(tr("&About"), this);
    logIN = fileMenu->addAction(tr("L&ogin"));
    exitAction = fileMenu->addAction(tr("E&xit"));

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(aboutMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void MainWindow::createHGBAccountBalance()
{
    HGBAccountBalance = new QGroupBox(tr("Account Information"));
    QGridLayout *layout = new QGridLayout;

    labels[0] = new QLabel(strWelcome);
    labels[1] = new QLabel(str_AccNum);
    labels[2] = new QLabel(str_AccBal);

    QFont font = labels[0]->font();
    font.setPointSize(20);
    labels[0]->setFont(font);
    labels[0]->setAlignment(Qt::AlignRight);

    layout->addWidget(labels[0]);
    layout->addWidget(labels[1]);
    layout->addWidget(labels[2]);


    HGBAccountBalance->setLayout(layout);
}

void MainWindow::createHGBAccountSelector()
{
    HGBAccountSelector = new QGroupBox(tr("Select account Type"));

    QGridLayout *layout = new QGridLayout;

    btnAccountSelector[0] = new QPushButton(tr("Checkings"));
    btnAccountSelector[1] = new QPushButton(tr("Savings"));
    layout->addWidget(btnAccountSelector[0], 0, 0);
    layout->addWidget(btnAccountSelector[1], 0, 1);

    HGBAccountSelector->setLayout(layout);
}

void MainWindow::createHGBAccountActions()
{
    HGBAccountActions = new QGroupBox(tr("Transaction / History"));
    QGridLayout *layout = new QGridLayout;

    btnAccountAction[0] = new QPushButton(tr("Deposit"));
    btnAccountAction[1] = new QPushButton(tr("Transfer"));
    btnAccountAction[2] = new QPushButton(tr("Withdraw"));
    btnAccountAction[3] = new QPushButton(tr("History"));
    layout->addWidget(btnAccountAction[0], 0, 0);
    layout->addWidget(btnAccountAction[1], 1, 0);
    layout->addWidget(btnAccountAction[2], 0, 1);
    layout->addWidget(btnAccountAction[3], 1, 1);

    HGBAccountActions->setLayout(layout);
}

void MainWindow::updatestrUsername(QString x)
{
    strWelcome = QString("Welcome,  %1 !").arg(x);
}
void MainWindow::updatestrUser_Acc(QString y)
{
    str_AccNum = QString("Account Number: 4469-2584-8901-%1 ").arg(y);
}
void MainWindow::updatestrUser_BAL(QString z)
{
    str_AccBal = QString("Account Balance: $ %1 ").arg(z);
}

