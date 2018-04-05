#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "login.h"
#include "user.h"

//#include"depositwindow.h"
//#include "withdrawwindow.h"
//#include "transferwindow.h"
//#include "historywindow.h"

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
    MainWindow(user &d);
    void updatestrUsername(QString x);
    void updateAccNUM_BAL(QString y, QString z);
    void setupmainuser(user &d);
    void testmessage(QString);
    void callLogin(bool);
private:

    void createMenu(user &d);
    void createHGBAccountBalance();
    void createHGBAccountSelector();
    void createHGBAccountActions();

    QMenuBar *menuBar;
    QGroupBox *HGBAccountBalance;
    QGroupBox *HGBAccountSelector;
    QGroupBox *HGBAccountActions;

    QString strWelcome;
    QString str_AccNum;
    QString str_AccBal;

    QLabel *labels[5];
    QPushButton *btnAccountSelector[2];
    QPushButton *btnAccountAction[4];

    QMenu *fileMenu;
    QAction *logIN;
    QAction *logOFF;
    QMenu *aboutMenu;
    QAction *exitAction;

    user main_user_data;

    private slots:
        void checklog(bool);
        void handleLogin();
        void handleLogoff();
        void handleDeposit();
        void handleWithdraw();
        void handleTransfer();
        void handleHistory();
        void handleChecking();
        void handleSaving();

};

#endif
