#ifndef SAV_DEP_AMOUNT_H
#define SAV_DEP_AMOUNT_H

#include <QWidget>

class Sav_Dep_Amount : public QWidget
{
    Q_OBJECT
public:
    explicit Sav_Dep_Amount(QWidget *parent = nullptr);

signals:

private slots:
    void OkButton();
};

#endif // SAV_DEP_AMOUNT_H
