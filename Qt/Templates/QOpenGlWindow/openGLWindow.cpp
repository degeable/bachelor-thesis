#include "openGLWindow.h"
#include <QImage>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLContext>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLExtraFunctions>
#include <QPropertyAnimation>
#include <QPauseAnimation>
#include <QSequentialAnimationGroup>
#include <QTimer>
openGLWindow::openGLWindow()
    : m_program(0)
{
}

openGLWindow::~openGLWindow()
{
    makeCurrent();
    delete m_program;

}

static const char *vertexShaderSource =
                      "attribute highp vec4 posAttr;\n"
                      "attribute lowp vec4 colAttr;\n"
                      "varying lowp vec4 col;\n"
                      "uniform highp mat4 matrix;\n"
                      "void main() {\n"
                      "   col = colAttr;\n"
                      "   gl_Position = matrix * posAttr;\n"
                      "}\n";


static const char *fragmentShaderSource =
                    "varying lowp vec4 col;\n"
                    "void main() {\n"
                    "   gl_FragColor = col;\n"
                    "}\n";

void openGLWindow::initializeGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    if (m_program) {
        delete m_program;
        m_program = 0;
    }
    m_program = new QOpenGLShaderProgram;
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();


    positionAttr_ = m_program->attributeLocation("posAttr");
    colorAttr_ = m_program->attributeLocation("colAttr");
    matrixAttr_ = m_program->uniformLocation("matrix");

}


void openGLWindow::resizeGL(int w, int h)
{

}

void openGLWindow::paintGL()
{

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT);

      m_program->bind();

      QMatrix4x4 matrix;
      matrix.perspective(90.0f, 1.0f, 0.1f, 100.0f);
      matrix.translate(0, 0, -1);

      m_program->setUniformValue(matrixAttr_, matrix);

      float relSize = 0.8f;
      GLfloat vertices[] = {
          -relSize, -relSize, 0.0f,
          relSize, -relSize, 0.0f,
          0.0f, relSize, 0.0f
      };

      GLfloat colors[] = {
          1.0f, 0.0f, 0.0f,
          0.0f, 1.0f, 0.0f,
          0.0f, 0.0f, 1.0f
      };

      f->glVertexAttribPointer(positionAttr_, 3, GL_FLOAT, GL_FALSE, 0, vertices);
      f->glVertexAttribPointer(colorAttr_, 3, GL_FLOAT, GL_FALSE, 0, colors);

      f->glEnableVertexAttribArray(0);
      f->glEnableVertexAttribArray(1);

      f->glDrawArrays(GL_TRIANGLES, 0, 3);

      f->glDisableVertexAttribArray(1);
      f->glDisableVertexAttribArray(0);

      m_program->release();

}
