#ifndef CHE_DEP_AMOUNT_H
#define CHE_DEP_AMOUNT_H

#include <QWidget>

class Che_Dep_Amount : public QWidget
{
    Q_OBJECT
public:
    explicit Che_Dep_Amount(QWidget *parent = nullptr);

signals:

private slots:
    void OkButton();
};

#endif // CHE_DEP_AMOUNT_H
