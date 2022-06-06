#include "worker.h"

Worker::Worker(QVariant item, QString path)
{
    m_item = item;
    m_path = path;
}

void Worker::startJob()
{
    qDebug() << "NEVERMIND";
    qDebug() << "Path to save: " << m_path;
    QImage img = qvariant_cast<QImage>(m_item);
    img.save(m_path);
}

void Worker::setThings(QVariant item, QString path)
{
    m_item = item;
    m_path = path;
}
