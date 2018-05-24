#include <QtWidgets>
#include <QtConcurrent>

#include <functional>

using namespace QtConcurrent;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    const int master_N_value = 1000;

    // Prepare the vector.
    QVector<int> vector;
    for (int i = 0; i < master_N_value; ++i)
        vector.append(i);

    // Create a progress dialog.
    QProgressDialog dialog;
    dialog.setLabelText(QString("Progressing using %1 thread(s)...").arg(QThread::idealThreadCount()));

    // Create a QFutureWatcher and connect signals and slots.
    QFutureWatcher<void> futureWatcher1;
    QFutureWatcher<void> futureWatcher2;
    QFutureWatcher<void> futureWatcher3;


    QObject::connect(&futureWatcher1, &QFutureWatcher<void>::finished, &dialog, &QProgressDialog::reset);
    QObject::connect(&futureWatcher2, &QFutureWatcher<void>::finished, &dialog, &QProgressDialog::reset);
    QObject::connect(&futureWatcher3, &QFutureWatcher<void>::finished, &dialog, &QProgressDialog::reset);

    QObject::connect(&dialog, &QProgressDialog::canceled, &futureWatcher1, &QFutureWatcher<void>::cancel);
    QObject::connect(&dialog, &QProgressDialog::canceled, &futureWatcher2, &QFutureWatcher<void>::cancel);
    QObject::connect(&dialog, &QProgressDialog::canceled, &futureWatcher3, &QFutureWatcher<void>::cancel);

    QObject::connect(&futureWatcher1,  &QFutureWatcher<void>::progressRangeChanged, &dialog, &QProgressDialog::setRange);
    QObject::connect(&futureWatcher2,  &QFutureWatcher<void>::progressRangeChanged, &dialog, &QProgressDialog::setRange);
    QObject::connect(&futureWatcher3,  &QFutureWatcher<void>::progressRangeChanged, &dialog, &QProgressDialog::setRange);

    QObject::connect(&futureWatcher1, &QFutureWatcher<void>::progressValueChanged,  &dialog, &QProgressDialog::setValue);
    QObject::connect(&futureWatcher2, &QFutureWatcher<void>::progressValueChanged,  &dialog, &QProgressDialog::setValue);
    QObject::connect(&futureWatcher3, &QFutureWatcher<void>::progressValueChanged,  &dialog, &QProgressDialog::setValue);

    // Our function to compute
    std::function<void(int&)> spin = [](int &iteration) {
        const int work = 1000 * 1000 * 40;
        volatile int v = 0;
        for (int j = 0; j < work; ++j)
            ++v;

        qDebug() << "iteration" << iteration << "in thread" << QThread::currentThreadId();
    };

    // Start the computation.
    futureWatcher1.setFuture(QtConcurrent::map(vector, spin));
    futureWatcher2.setFuture(QtConcurrent::map(vector, spin));
    futureWatcher3.setFuture(QtConcurrent::map(vector, spin));
    // Display the dialog and start the event loop.
    dialog.exec();

    futureWatcher1.waitForFinished();
    futureWatcher2.waitForFinished();
    futureWatcher3.waitForFinished();

    // Query the future to check if was canceled.
    qDebug() << "Canceled?" << futureWatcher1.future().isCanceled();
    qDebug() << "Canceled?" << futureWatcher2.future().isCanceled();
    qDebug() << "Canceled?" << futureWatcher3.future().isCanceled();
}
