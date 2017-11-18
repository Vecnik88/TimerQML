#include <QtGui>
#include <QtQml>
#include <QQuickWidget>

#include "timer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Timer>("io.qt.Timer", 1, 0, "Timer");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
