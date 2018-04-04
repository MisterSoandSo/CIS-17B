#include <QtWidgets>

#include "login.h"


Login::Login(QWidget *parent)
    : QWidget(parent)
{
    loginUserLabel = new QLabel(tr("&Username:"));
    userLineEdit = new QLineEdit;
    loginUserLabel->setBuddy(userLineEdit);

    passWordLabel = new QLabel(tr("P&assword:"));
    passLineEdit = new QLineEdit;
    passWordLabel->setBuddy(passLineEdit);

    statusLabel = new QLabel(tr("Testing Mode: Username ~ 'user1' "
                                "Password ~ 'pass1'."));
    statusLabel->setWordWrap(true);

    loginButton = new QPushButton(tr("Login to Account"));
    loginButton->setDefault(true);
    loginButton->setEnabled(false);

    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(loginButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    //login_status = false;

    connect(loginButton, SIGNAL(clicked()), this, SLOT(requestLogincheck()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    connect(userLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableloginButton()));
    connect(passLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableloginButton()));



    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(loginUserLabel, 0, 0);
    mainLayout->addWidget(userLineEdit, 0, 1);
    mainLayout->addWidget(passWordLabel, 1, 0);
    mainLayout->addWidget(passLineEdit, 1, 1);
    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Banking GUI Login Client"));
    passLineEdit->setFocus();
    setMinimumSize(460, 150);
}
bool Login::getLogStat()
{
    return login_status;
}
void Login::setLogStat(bool b_check)
{
    login_status = b_check;
}
void Login::requestLogincheck()
{
    bool valid_user((userLineEdit->text().toStdString()=="user1") && (passLineEdit->text().toStdString() == "pass1"));
    if(valid_user)
    {
        setLogStat(true);

        this->close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid login! Please check for correct cedentials");
        msgBox.exec();
        setLogStat(false);

    }

}
void Login::enableloginButton()
{
    bool enable(!userLineEdit->text().isEmpty() && !passLineEdit->text().isEmpty());
    loginButton->setEnabled(enable);
}
