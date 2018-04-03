#include "historywindow.h"
#include <QtWidgets>

HistoryWindow::HistoryWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    QLabel *label = new QLabel(tr("Transaction History: "));

    grid->addWidget(label,0,0);

    setLayout(grid);

    setMinimumSize(350,200);

    setWindowTitle(tr("History Window"));
}
