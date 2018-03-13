#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
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


    QLabel *labels[];



    QPushButton *btnAccountSelector[2];
    QPushButton *btnAccountAction[4];



    QMenu *fileMenu;
    QMenu *aboutMenu;
    QAction *exitAction;
};
//! [0]

#endif
