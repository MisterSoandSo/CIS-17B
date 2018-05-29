#include <QtWidgets>
#include <QtConcurrent>
#include <QFuture>
#include <functional>

using namespace QtConcurrent;

int fib(int n)
{
   if (n <= 1)
   {
    return n;
   }

   return fib(n-1) + fib(n-2);
}

bool isPrime(int number)
{
    for (int i=2; i*i<=number; i++)
    {
        if (number % i == 0) return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    const int master_N_value = 10;
    qDebug() << "N value:" <<master_N_value;

    QFuture<void> futureWatcher1 =QtConcurrent::run([master_N_value]()
    {
        qDebug() << "Starting Fibonacci 1...";
        int final_fib = fib(master_N_value);
        qDebug() << "Fibonacci 1... Done: "<< final_fib;
    });

    QFuture<void> futureWatcher2 =QtConcurrent::run([master_N_value]()
    {
         qDebug() << "Starting Harmonic Series 2...";
        double final_add = 0.0;
        double sum =0;
        for(int i=1;i<=master_N_value;i++)
        {
            sum = (1.0/i);
            final_add += sum;
            qDebug() << "Harmonic Series 2..."<<final_add;
        }
        qDebug() << "Harmonic Series 2... Done: " <<final_add;
    });

    QFuture<void> futureWatcher3 =QtConcurrent::run([master_N_value]()
    {
        qDebug() << "Starting Prime  3...";
       int prime,cntPrime =0;

           int i;
           if (master_N_value == 1)
           {
               qDebug() << "Prime 3... 2";
               prime = 2;  //if N is equal to 1
           }

           for (i = 3; ; i += 2)    //for every thing else ingore even numbers
           {
               if (isPrime(i))
               {
                   qDebug() << "Prime 3..."<<i;
                   cntPrime++;
                   if (cntPrime == (master_N_value - 1))    //because we took out the first case
                   {

                       prime = i;
                       break;
                   }
               }
           }



       qDebug() << "Prime 3... Done: " <<prime;
    });
    futureWatcher1.waitForFinished();
    futureWatcher2.waitForFinished();
    futureWatcher3.waitForFinished();

    QApplication::quit();
}
