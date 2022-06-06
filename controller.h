#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "worker.h"

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QQuickItem>
#include <QImage>
#include <QVariant>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();
    ~Controller();

    Q_INVOKABLE void prepareTakingShot(QVariant item, const QString path);
signals:
    Q_INVOKABLE void startTakingShot();
private:
    QThread workerThread;
};

#endif // CONTROLLER_H
