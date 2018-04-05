#ifndef Login_H
#define Login_H

#include <QWidget>
#include "user.h"

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
    Login(user&);
    bool getLogStat();
    void setLogStat(bool);
    void setUserPass(user&);
    void requestLogincheck(QString,QString);
/*private slots:


    //void enableloginButton();
*/
private:
    //QLabel *loginUserLabel;
    //QLabel *passWordLabel;
    //QLineEdit *userLineEdit;
    //QLineEdit *passLineEdit;
    //QLabel *statusLabel;
    bool login_status = false;
    QString userInput;
    QString passInput;

    //QPushButton *loginButton;
    //QPushButton *quitButton;
    //QDialogButtonBox *buttonBox;
};


#endif
