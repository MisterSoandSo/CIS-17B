#include <QtWidgets>
#include <QtConcurrent>

#include <functional>

using namespace QtConcurrent;

int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    const int master_N_value = 100;
    int final_fib =0;
    float final_add = 0.0;
    int prime_num =0;

    // Prepare the vector.
    QVector<int> vector;
    for (int i = 0; i < master_N_value; ++i)
        vector.append(i);
    //Prepare fib table

    //
    //

    // Create a progress dialog.
    QProgressDialog dialog1;
    QProgressDialog dialog2;
    QProgressDialog dialog3;

    dialog1.setLabelText(QString("Progressing using %1 thread(s)...").arg(QThread::idealThreadCount()));
    dialog2.setLabelText(QString("Progressing using %1 thread(s)...").arg(QThread::idealThreadCount()));
    dialog3.setLabelText(QString("Progressing using %1 thread(s)...").arg(QThread::idealThreadCount()));

    // Create a QFutureWatcher and connect signals and slots.
    QFutureWatcher<void> futureWatcher1;
    QFutureWatcher<void> futureWatcher2;
    QFutureWatcher<void> futureWatcher3;


    QObject::connect(&futureWatcher1, &QFutureWatcher<void>::finished, &dialog1, &QProgressDialog::reset);
    QObject::connect(&futureWatcher2, &QFutureWatcher<void>::finished, &dialog2, &QProgressDialog::reset);
    QObject::connect(&futureWatcher3, &QFutureWatcher<void>::finished, &dialog3, &QProgressDialog::reset);

    QObject::connect(&dialog1, &QProgressDialog::canceled, &futureWatcher1, &QFutureWatcher<void>::cancel);
    QObject::connect(&dialog2, &QProgressDialog::canceled, &futureWatcher2, &QFutureWatcher<void>::cancel);
    QObject::connect(&dialog3, &QProgressDialog::canceled, &futureWatcher3, &QFutureWatcher<void>::cancel);

    QObject::connect(&futureWatcher1,  &QFutureWatcher<void>::progressRangeChanged, &dialog1, &QProgressDialog::setRange);
    QObject::connect(&futureWatcher2,  &QFutureWatcher<void>::progressRangeChanged, &dialog2, &QProgressDialog::setRange);
    QObject::connect(&futureWatcher3,  &QFutureWatcher<void>::progressRangeChanged, &dialog3, &QProgressDialog::setRange);

    QObject::connect(&futureWatcher1, &QFutureWatcher<void>::progressValueChanged,  &dialog1, &QProgressDialog::setValue);
    QObject::connect(&futureWatcher2, &QFutureWatcher<void>::progressValueChanged,  &dialog2, &QProgressDialog::setValue);
    QObject::connect(&futureWatcher3, &QFutureWatcher<void>::progressValueChanged,  &dialog3, &QProgressDialog::setValue);

    // Our function to compute
    std::function<void(int&)> fiba = [&final_fib](int &iteration)
    {
        const int work = 1000 * 1000 * 40;
        volatile int v = 0;
        for (int j = 0; j < work; ++j)
            ++v;
            final_fib = fib(master_N_value);
        qDebug() << "Fibonacci iteration("<<iteration<<"): "<< final_fib <<"in thread" << QThread::currentThreadId();
    };

    std::function<void(int&)> add_series = [&final_add](int &iteration)
    {
        const int work = 1000 * 1000 * 40;
        volatile int v = 0;
        for (int j = 0; j < work; ++j)
           ++v;
        float temp = final_add;
        float sum;

        if(master_N_value!=0)
        {
             for(float i=1;i<=master_N_value;i++)
             {
                sum = (1.0/i);
                final_add +=sum ;
             }
        }

        qDebug() << "Add iteration("<<iteration<<"): " << temp << "+"<< sum << "=" << final_add << "in thread" << QThread::currentThreadId();
    };

    std::function<void(int&)> prime = [&prime_num](int &iteration)
    {
        const int work = 1000 * 1000 * 40;
        volatile int v = 0;
        for (int j = 0; j < work; ++j)
            ++v;

        qDebug() << "Prime iteration("<<iteration<<"): "<< "in thread" << QThread::currentThreadId();
    };


    // Start the computation.
    qDebug() << "Staring FutureWatcher 1 & 2 & 3";
    futureWatcher1.setFuture(QtConcurrent::map(vector, fiba));
    futureWatcher2.setFuture(QtConcurrent::map(vector, add_series));
    futureWatcher3.setFuture(QtConcurrent::map(vector, prime));

    // Display the dialog and start the event loop.
    dialog1.exec();
    dialog2.exec();
    dialog3.exec();

    futureWatcher1.waitForFinished();
    futureWatcher2.waitForFinished();
    futureWatcher3.waitForFinished();

    // Query the future to check if was canceled.
    qDebug() << "Canceled?" << futureWatcher1.future().isCanceled();
    qDebug() << "Canceled?" << futureWatcher2.future().isCanceled();
    qDebug() << "Canceled?" << futureWatcher3.future().isCanceled();

    //final values
    qDebug() << "Final values Display";
    qDebug() << "Fibonacci:" << final_fib;
    qDebug() << "Additive Series:" <<final_add;
    qDebug() << "Prime Number at n:" << prime_num;

}
