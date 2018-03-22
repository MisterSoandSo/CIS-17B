#ifndef SAVING_H
#define SAVING_H


class saving: public account
{
    private:
        float interest_rate = 0.01;
    public:
        saving(float int_rate,string number, double balance);
        virtual ~saving();
        void deposit(double);
        bool withdraw(double);
        bool transfer(double);
        void getNumber();
        string setNumber();
        void getBalance();
        void setBalance();
};

#endif // SAVING_H
