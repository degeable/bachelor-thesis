#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "VisualHearingAid.h"
#include "VHAWatch.h"
#include "VHADigital.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //qRegisterMetaType<VisualHearingAid>()
    qmlRegisterType<VisualHearingAid_FBO>("VisualHearingAid", 1, 0, "VisualHearingAid_FBO");
    qmlRegisterType<VHAWatch_FBO>("VHAWatch", 1, 0, "VHAWatch_FBO");
    qmlRegisterType<VHADigital_FBO>("VHADigital", 1, 0, "VHADigital_FBO");
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
