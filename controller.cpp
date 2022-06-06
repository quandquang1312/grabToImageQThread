#include "controller.h"

Controller::Controller()
{
    workerThread.setObjectName("Worker Thread");
}

Controller::~Controller()
{
    qDebug() << "Quit worker";

    workerThread.quit();
    workerThread.wait();
}

void Controller::prepareTakingShot(QVariant item, const QString path)
{
    Worker *worker = new Worker(item, path);
    qDebug() << "Worker is in: " << worker->thread();
    // worker->setThings(item, path);
    worker->moveToThread(&workerThread);
    qDebug() << "Worker is in: " << worker->thread();
    worker->startJob();
}
