#ifndef WORKER_H
#define WORKER_H

#include <QDebug>
#include <QObject>
#include <QQuickItem>
#include <QVariant>
#include <QImage>

class Worker : public QObject
{
public:
    Worker(QVariant item, QString path);
    void startJob();
    void setThings(QVariant item, QString path);

private:
    QVariant m_item;
    QString m_path;
};

#endif // WORKER_H
