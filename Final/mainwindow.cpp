#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFutureWatcher>
using namespace QtConcurrent;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setup_Slot();
    ui->setupUi(this);

    connect(ui->btnInsert, SIGNAL(clicked()), this, SLOT(slot_insertCoin()));
    connect(ui->btnPull,   SIGNAL(clicked()), this, SLOT(slot_Pull()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/// Main Support Functions
/*
Initialize coins amount
*/
void MainWindow::setup_Slot()
{
    coinamt = 50;
    betamt  = 0;
}

/*
Check all 3 returned slot values for win condition
*/
void MainWindow::check_win(int x,int y, int z)
{
    QMessageBox msgBox;
    int slot_multipler = 0;
    if(x==0 && y==0 && z==0)    slot_multipler = 7;       //x7
    if(x==y && x==z)            slot_multipler = x;       //x1-x6
    if(x==1 && y==2 && z==3)    slot_multipler = 8;       //ABC x8
    if(x==4 && y==5 && z==6)    slot_multipler = 9;       //DEF x9

    if(slot_multipler<=0)
    {
        ui->lineoutput->setText("You lost this round: x" + QString::number(slot_multipler)
                                +" multipler. Better luck next time! You won 0 coins!");
    }
    else
    {
        ui->lineoutput->setText("You won this round: x" + QString::number(slot_multipler)
                                +" multipler");
        int temp = betamt * slot_multipler;
        msgBox.setText("Times x"+QString::number(slot_multipler)+"! You won "+QString::number(temp)+" coins!");
        msgBox.exec();
        coinamt += temp;
    }
}

/*
Update the coin and bet labels
*/
void MainWindow::updatedisplay()
{
    QString amt ="Coins: " + QString::number(coinamt);
    QString bet ="Betting:" + QString::number(betamt);

    ui->lblCoin->setText(amt);
    ui->lblBet->setText(bet);
}


///Slot Functions
/*
Allows user to increase bets to a max of 3 coins
*/
void MainWindow::slot_insertCoin()
{
    if((coinamt == 0) && (betamt == 0)) //out of money and no bet
    {
        ui->lineoutput->setText("Stop gambling and get a Job. Your out of money!");
        return;
    }
    if((coinamt > 0) && (betamt < 3))   //have money and bet
    {
        ui->lineoutput->setText("");
        coinamt--;
        betamt++;
        qDebug()<<"Inserting coin!";
        updatedisplay();
        return;
    }
    if(((coinamt == 0) && (betamt <= 3)))   //no money but a betting pool
    {
        ui->lineoutput->setText("Just Pull the lever. Your out of money!");
        return;
    }
    if(((coinamt >= 0) && (betamt == 3)))   //at betting limit
    {
        ui->lineoutput->setText("Just Pull the lever. Max Bet: 3 coins!");
        return;
    }


}

/*
Creates 3 inidividual threads to generate 3 slot values.
Checks if  there is a win condition and awards accordingly.
*/
void MainWindow::slot_Pull()
{
    qDebug()<<"Pull new bet!";
    //generate 3 random number that uses concurent threads

    QFutureWatcher<void> watcher1;
    QFuture<void> t1 = QtConcurrent::run([=](){slot1.slot_gen();});

    QFutureWatcher<void> watcher2;
    QFuture<void> t2 = QtConcurrent::run([=](){slot2.slot_gen();});

    QFutureWatcher<void> watcher3;
    QFuture<void> t3 = QtConcurrent::run([=](){slot3.slot_gen();});

    QEventLoop loop1;
    connect(&watcher1,SIGNAL(finished()),this, SLOT(slot_update_dis1()));
    connect(&watcher1,SIGNAL(finished()),&loop1, SLOT(quit()),  Qt::QueuedConnection);
    watcher1.setFuture(t1);
    loop1.exec();

    QEventLoop loop2;
    connect(&watcher2,SIGNAL(finished()),this, SLOT(slot_update_dis2()));
    connect(&watcher2,SIGNAL(finished()),&loop2, SLOT(quit()),  Qt::QueuedConnection);
    watcher2.setFuture(t2);
    loop2.exec();

    QEventLoop loop3;
    connect(&watcher3,SIGNAL(finished()),this, SLOT(slot_update_dis3()));
    connect(&watcher3,SIGNAL(finished()),&loop3, SLOT(quit()),  Qt::QueuedConnection);
    watcher3.setFuture(t3);
    loop3.exec();

    //check win condition
    check_win(slot1.ret_slot(),slot2.ret_slot(),slot3.ret_slot());

    betamt = 0; //reset bet
    updatedisplay();
}

/*
slot_update_dis updates each individual slot
*/
void MainWindow::slot_update_dis1()
{
    ui->lblSlot1->setText(slot1.ret_char());
    qDebug()<<"Main Debug Slot 1:" << slot1.ret_char();
}

void MainWindow::slot_update_dis2()
{
    ui->lblSlot2->setText(slot2.ret_char());
    qDebug()<<"Main Debug Slot 2:" << slot2.ret_char();
}

void MainWindow::slot_update_dis3()
{
    ui->lblSlot3->setText(slot3.ret_char());
    qDebug()<<"Main Debug Slot 3:" << slot3.ret_char();
}
