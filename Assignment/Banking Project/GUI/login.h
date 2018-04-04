#ifndef Login_H
#define Login_H

#include <QWidget>


QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QAction;
QT_END_NAMESPACE

//! [0]
class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = 0);
    bool getLogStat();
    void setLogStat(bool);
private slots:

    void requestLogincheck();
    void enableloginButton();

private:
    QLabel *loginUserLabel;
    QLabel *passWordLabel;
    QLineEdit *userLineEdit;
    QLineEdit *passLineEdit;
    QLabel *statusLabel;
    bool login_status;

    QPushButton *loginButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
};


#endif
