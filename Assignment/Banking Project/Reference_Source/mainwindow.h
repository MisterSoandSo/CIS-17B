#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <user.h>
#include"depositwindow.h"
#include "withdrawwindow.h"
#include "transferwindow.h"
#include "historywindow.h"

QT_BEGIN_NAMESPACE
class QAction;
class QGroupBox;
class QLabel;
class QMenu;
class QMenuBar;
class QPushButton;
QT_END_NAMESPACE


class MainWindow : public QDialog
{
    Q_OBJECT
public:
    MainWindow();
    MainWindow(user d);
    void updatestrUsername(QString x);
    void updatestrUser_Acc(QString y);
    void updatestrUser_BAL(QString z);


private:

    void createMenu();
    void createHGBAccountBalance();
    void createHGBAccountSelector(user d);
    void createHGBAccountActions();

    QMenuBar *menuBar;
    QGroupBox *HGBAccountBalance;
    QGroupBox *HGBAccountSelector;
    QGroupBox *HGBAccountActions;

    QString strWelcome;
    QString str_AccNum;
    QString str_AccBal;

    QLabel *labels[];
    QPushButton *btnAccountSelector[2];
    QPushButton *btnAccountAction[4];

    QMenu *fileMenu;
    QAction *logIN;
    QMenu *aboutMenu;
    QAction *exitAction;

    DepositWindow *dWindow;
    WithdrawWindow *wWindow;
    TransferWindow *tWindow;
    HistoryWindow *hWindow;

    private slots:
        void handleDeposit();
        void handleWithdraw();
        void handleTransfer();
        void handleHistory();
        void handleChecking(user);
        void handleSaving(user);
};

#endif
