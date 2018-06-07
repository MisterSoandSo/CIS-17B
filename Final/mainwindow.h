#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qvector>
#include <QDebug>
#include <QtConcurrent>
#include <QMessageBox>
#include "slot_class.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void check_win(int x, int y, int z);
    void setup_Slot();
    void updatedisplay();


public slots:
    void slot_insertCoin();
    void slot_Pull();
    void slot_update_dis1();
    void slot_update_dis2();
    void slot_update_dis3();

private:
    int coinamt, betamt;
    //create 3 individual slot objects
    slot_class slot1;
    slot_class slot2;
    slot_class slot3;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
