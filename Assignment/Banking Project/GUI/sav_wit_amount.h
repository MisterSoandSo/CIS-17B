#ifndef SAV_WIT_AMOUNT_H
#define SAV_WIT_AMOUNT_H

#include <QWidget>

class Sav_Wit_Amount : public QWidget
{
    Q_OBJECT
public:
    explicit Sav_Wit_Amount(QWidget *parent = nullptr);

signals:

private slots:
    void OkButton();
};

#endif // SAV_WIT_AMOUNT_H
