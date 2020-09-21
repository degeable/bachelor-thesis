#include <QGuiApplication>

#include <QtQuick/QQuickView>

#include "vha.h"


int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Vha>("VisualHearingAid", 1, 0, "Vha");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///main.qml"));
    view.show();

    return app.exec();
}
