#include "openGLWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    openGLWindow w;
    w.show();
    return a.exec();
}
