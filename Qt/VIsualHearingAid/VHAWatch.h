#include <QOpenGLFramebufferObjectFormat>
#include <QQuickFramebufferObject>
#include <QQuickWindow>
#include <QOpenGLTexture>
#include <QImageReader>
#include <QImage>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QGuiApplication>
#include <QScreen>

#include <iostream>
#include <csignal>
#include <exception>
#include <cmath>
#include <sys/time.h>
#include <vector>
#include <csignal>
#include <deque>
#include <iostream>


using std::deque;
using std::signal;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::runtime_error;

//*****VHAWatch_FBO*****

class VHAWatch_FBO
        : public QQuickFramebufferObject
{
public:
    explicit VHAWatch_FBO(QQuickItem* parent = nullptr);
    Renderer* createRenderer() const override;
};

//*****VHAWatch*****

class VHAWatch
        : public QQuickFramebufferObject::Renderer,
          protected QOpenGLFunctions
{
public:
    VHAWatch();
    ~VHAWatch();
    void synchronize(QQuickFramebufferObject *item) override;
    void initOGL();
    void render() override;
    void resize();
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;

private:
    QQuickWindow* m_window;
    QOpenGLShaderProgram *m_program;
    QSize m_viewportSize;

protected:

    GLint _aPosition;
    GLint _aColor2;
    GLint _uAspect2;

    int _height;
    int _width;

};


