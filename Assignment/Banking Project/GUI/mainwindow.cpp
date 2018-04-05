#include <QtWidgets>
#include <QEventLoop>
#include <Qt>
#include "mainwindow.h"
#include "user.h"

//#include "account.h"
//#include "checking.h"
//#include "saving.h"

MainWindow::MainWindow(user &data)
{
    updatestrUsername("Guest");
    updateAccNUM_BAL("0000", "0.00");

    createMenu(data);
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

void MainWindow::createMenu(user &data)
{
    main_user_data.setUser(data.getUser());
    main_user_data.setPwd(data.getPwd());

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
void MainWindow::checklog(bool local_cbool)
{
    if(local_cbool)
        {
             updatestrUsername(main_user_data.getUser());
             updateAccNUM_BAL("xxxx", "x.xx");
             labels[0]->setText(strWelcome);
             labels[2]->setText(str_AccNum);
             labels[4]->setText(str_AccBal);

             logIN->setVisible(false);
             logOFF->setVisible(true);
        }
        else
        {
            handleLogoff();
        }
}
void MainWindow::handleLogin()
{
    Login *client = new Login(main_user_data);

    QDialog dialog(this);
    QFormLayout form(&dialog);

    form.addRow(new QLabel("Input login credentials"));

    QList<QLineEdit *> fields;
    QString inputlabels[]={"Username:","Password:"};

    for(int i = 0; i < 2; ++i) {
        QLineEdit *lineEdit = new QLineEdit(&dialog);
        QString label = QString("%1").arg(inputlabels[i]);
        form.addRow(label, lineEdit);

        fields << lineEdit;
    }

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted)
    {
        client->requestLogincheck(fields[0]->text(),fields[1]->text());
        checklog(client->getLogStat());
        callLogin(true);
    }
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

}
void MainWindow::handleWithdraw()
{

}
void MainWindow::handleTransfer()
{

}
void MainWindow::handleHistory()
{

}
