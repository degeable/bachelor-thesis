#ifndef VHADIGITAL_H
#define VHADIGITAL_H
#include <QOpenGLFramebufferObjectFormat>
#include <QQuickFramebufferObject>
#include <QQuickWindow>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QGuiApplication>
#include <QScreen>

#include <iostream>
#include <exception>
#include <sys/time.h>
#include <vector>

#include "VectorCharacter.h"

using std::cout;
using std::cerr;
using std::endl;
using std::runtime_error;

//*****VHADigital_FBO*****

class VHADigital_FBO
        : public QQuickFramebufferObject
{
public:
    explicit VHADigital_FBO(QQuickItem* parenxst = nullptr);
    Renderer* createRenderer() const override;
};

//*****VHADigital*****

class VHADigital
        : public QQuickFramebufferObject::Renderer,
          protected QOpenGLFunctions
{
public:
    VHADigital();
    ~VHADigital();
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

    vector<float> v;
    GLint _aPosition;
    GLint _aColor2;
    GLint _uAspect2;

    int _height;
    int _width;

};



#endif // VHADIGITAL_H
