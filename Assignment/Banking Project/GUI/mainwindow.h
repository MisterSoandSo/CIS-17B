#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>


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

private:

    void createMenu();
    void createHGBAccountBalance();
    void createHGBAccountSelector();
    void createHGBAccountActions();

    QMenuBar *menuBar;
    QGroupBox *HGBAccountBalance;
    QGroupBox *HGBAccountSelector;
    QGroupBox *HGBAccountActions;

    QString strUsername = "Guest";
    QString strUser_Acc = "0000";
    QString strUser_BAL = "0.00";

    QString strWelcome = QString("Welcome,  %1 !").arg(strUsername);
    QString str_AccNum = QString("Account Number: 4469-2584-8901-%1 ").arg(strUser_Acc);
    QString str_AccBal = QString("Account Balance: $ %1 ").arg(strUser_BAL);

    QLabel *labels[];
    QPushButton *btnAccountSelector[2];
    QPushButton *btnAccountAction[4];

    QMenu *fileMenu;
    QAction *logIN;
    QMenu *aboutMenu;
    QAction *exitAction;
};

#endif
