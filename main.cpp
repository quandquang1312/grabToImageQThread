#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "controller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<Controller>("Controller", 1, 0, "Controller");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    engine.thread()->setObjectName("Main Thread");

    return app.exec();
}
