#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
QT_BEGIN_NAMESPACE

class QOpenGLTexture;
class QOpenGLShaderProgram;
class QOpenGLBuffer;
class QOpenGLVertexArrayObject;

QT_END_NAMESPACE

class openGLWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    openGLWindow();
    ~openGLWindow();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:

    QOpenGLShaderProgram *m_program;

    uint positionAttr_;
    uint colorAttr_;
    int matrixAttr_;
};
#endif // OPENGLWINDOW_H
