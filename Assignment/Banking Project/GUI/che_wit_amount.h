#ifndef CHE_WIT_AMOUNT_H
#define CHE_WIT_AMOUNT_H

#include <QWidget>

class Che_Wit_Amount : public QWidget
{
    Q_OBJECT
public:
    explicit Che_Wit_Amount(QWidget *parent = nullptr);

signals:

private slots:
    void OkButton();
};

#endif // CHE_WIT_AMOUNT_H
