#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QWidget>
class QGroupBox;
class QLineEdit;
class QPushButton;
class QLabel;

class TransferWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TransferWindow(QWidget *parent = nullptr);

signals:

public slots:

private:
    QPushButton *button;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QGroupBox *transferFrom;
    QGroupBox *transferTo;
    QGroupBox *amount;
    QLineEdit *echoLineEdit;
    QLabel *label1;

    void createTransferAction();
};

#endif // TRANSFERWINDOW_H
