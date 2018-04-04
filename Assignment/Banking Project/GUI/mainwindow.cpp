#include <QtWidgets>
#include <Qt>
#include "mainwindow.h"


//#include "account.h"
//#include "checking.h"
//#include "saving.h"

MainWindow::MainWindow()
{
    updatestrUsername("Guest");
    updateAccNUM_BAL("0000", "0.00");

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
    logOFF = fileMenu->addAction(tr("L&ogoff"));
    exitAction = fileMenu->addAction(tr("E&xit"));

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(aboutMenu);

    logIN->setVisible(true);
    logOFF->setVisible(false);

    connect(logIN, SIGNAL(triggered()),this, SLOT(handleLogin()));
    connect(logOFF, SIGNAL(triggered()),this, SLOT(handleLogoff()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}
void MainWindow::createHGBAccountBalance()
{
    HGBAccountBalance = new QGroupBox(tr("Account Information"));
    QGridLayout *layout = new QGridLayout;

    labels[0] = new QLabel(strWelcome);

    labels[1] = new QLabel("Account &Number: ");
    labels[2] = new QLabel(str_AccNum);
    labels[1]->setBuddy(labels[2]);

    labels[3] = new QLabel("Account &Balance: ");
    labels[4] = new QLabel(str_AccBal);
    labels[3]->setBuddy(labels[4]);

    QFont font = labels[0]->font();
    font.setPointSize(20);
    labels[0]->setFont(font);
    labels[0]->setAlignment(Qt::AlignRight);

    layout->addWidget(labels[0]);
    layout->addWidget(labels[1]);
    layout->addWidget(labels[2]);
    layout->addWidget(labels[3]);
    layout->addWidget(labels[4]);


    HGBAccountBalance->setLayout(layout);
}
void MainWindow::createHGBAccountSelector()
{
    HGBAccountSelector = new QGroupBox(tr("Select account Type"));

    QGridLayout *layout = new QGridLayout;

    btnAccountSelector[0] = new QPushButton(tr("Checkings"));
    btnAccountSelector[1] = new QPushButton(tr("Savings"));

    for(int i = 0;i<2;i++)
    {
        btnAccountSelector[i]->setDefault(true);
        btnAccountSelector[i]->setEnabled(false);

    }

    layout->addWidget(btnAccountSelector[0], 0, 0);
    layout->addWidget(btnAccountSelector[1], 0, 1);

    HGBAccountSelector->setLayout(layout);
    //QObject::connect(btnAccountSelector[0], SIGNAL (released()), this, SLOT (handleChecking(d)));
    //QObject::connect(btnAccountSelector[1], SIGNAL (released()), this, SLOT (handleSaving(d)));
}
void MainWindow::createHGBAccountActions()
{
    HGBAccountActions = new QGroupBox(tr("Transaction / History"));
    QGridLayout *layout = new QGridLayout;

    btnAccountAction[0] = new QPushButton(tr("Deposit"));
    btnAccountAction[1] = new QPushButton(tr("Transfer"));
    btnAccountAction[2] = new QPushButton(tr("Withdraw"));
    btnAccountAction[3] = new QPushButton(tr("History"));

    for(int i = 0;i<4;i++)
    {
        btnAccountAction[i]->setDefault(true);
        btnAccountAction[i]->setEnabled(false);

    }
    layout->addWidget(btnAccountAction[0], 0, 0);
    layout->addWidget(btnAccountAction[1], 1, 0);
    layout->addWidget(btnAccountAction[2], 0, 1);
    layout->addWidget(btnAccountAction[3], 1, 1);

    HGBAccountActions->setLayout(layout);

    QObject::connect(btnAccountAction[0], SIGNAL (released()), this, SLOT (handleDeposit()));
    QObject::connect(btnAccountAction[1], SIGNAL (released()), this, SLOT (handleTransfer()));
    QObject::connect(btnAccountAction[2], SIGNAL (released()), this, SLOT (handleWithdraw()));
    QObject::connect(btnAccountAction[3], SIGNAL (released()), this, SLOT (handleHistory()));
}

void MainWindow::updatestrUsername(QString x)
{
    strWelcome = QString("Welcome,  %1 !").arg(x);
}
void MainWindow::updateAccNUM_BAL(QString y, QString z)
{
    str_AccNum = QString("4469-2584-8901-%1 ").arg(y);
    str_AccBal = QString("$ %1 ").arg(z);
}

void MainWindow::testmessage(QString output)
{
    QMessageBox msgBox;
    msgBox.setText(output);
    msgBox.exec();
}

void MainWindow::callLogin(bool local_cbool)
{
    if(local_cbool)    //login true
    {
        for(int i = 0;i<2;i++)
        {
            btnAccountSelector[i]->setEnabled(local_cbool);
        }
        for(int i = 0;i<4;i++)
        {
            btnAccountAction[i]->setEnabled(local_cbool);
        }
    }
}
void MainWindow::handleLogin()
{
    Login *client = new Login();
    client->show();
    while(true)
    {
        if(client->getLogStat() == true)
        {
             callLogin(true);
             break;
        }
        else
        {
            callLogin(false);
        }
    }
    logIN->setVisible(false);
    logOFF->setVisible(true);
}
void MainWindow::handleLogoff()
{
    callLogin(false);
    logIN->setVisible(true);
    logOFF->setVisible(false);
}


void MainWindow::handleSaving()
{


}
void MainWindow::handleChecking()
{


}
void MainWindow::handleDeposit()
{
    //DepositWindow *dWindow = new DepositWindow();
    //dWindow->show();
}
void MainWindow::handleWithdraw()
{
    //WithdrawWindow *wWindow = new WithdrawWindow();
    //wWindow->show();
}
void MainWindow::handleTransfer()
{
    //TransferWindow *tWindow = new TransferWindow();
    //tWindow->show();
}
void MainWindow::handleHistory()
{
    //HistoryWindow *hWindow = new HistoryWindow();
    //hWindow->show();
}
