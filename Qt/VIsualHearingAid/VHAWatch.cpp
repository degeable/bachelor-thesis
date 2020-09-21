
#include <ctime>
#include <cmath>
#include <vector>
#include "VHAWatch.h"

using std::vector;
using std::runtime_error;

//*****VHAWatch_FBO*****

VHAWatch_FBO::VHAWatch_FBO(QQuickItem *parent)
                : QQuickFramebufferObject(parent)
{
}
auto VHAWatch_FBO::createRenderer() const -> QQuickFramebufferObject::Renderer*
{
    return new VHAWatch();
}

//*****VHAWatch*****

VHAWatch::VHAWatch()
          :m_program(0)

{
    QScreen *s = QGuiApplication::primaryScreen();
    _width = s->availableSize().width();
    _height = s->availableSize().height();
    initOGL();
}

VHAWatch::~VHAWatch()
{
    //maybe that does the same?
    m_program = 0;
    delete m_program;
}

void VHAWatch::initOGL()
{

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();


    if (m_program) {
        delete m_program;
        m_program = 0;
    }

    const char vertex_src [] = "\
    attribute vec2 position;                 \
    attribute vec4 color2;                    \
    uniform float aspect2;                    \
    varying vec4 vColor2;	                 \
                                             \
    void main()                              \
    {                                        \
       vec4 pos;	                         \
       if(aspect2>1.0)                        \
       {                                     \
          pos.x = position.x/aspect2;	     \
          pos.y = position.y;                \
       }                                     \
       else                                  \
       {                                     \
          pos.x = position.x;                \
          pos.y = position.y*aspect2;         \
       }                                     \
       pos.z = 0.0;                          \
       pos.w = 1.0;                          \
       gl_Position = pos;                    \
       vColor2 = color2;                       \
    }                                        \
    ";

    const char fragment_src [] = "\
       varying mediump vec4 vColor2;	                 \
       void  main()                          \
       {                                     \
          gl_FragColor  =  vColor2;           \
       }                                     \
    ";

    m_program = new QOpenGLShaderProgram;
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,vertex_src);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragment_src);
    m_program->link();

    _aPosition = m_program->attributeLocation("position");
    _aColor2 = m_program->attributeLocation("color2");

    if ( _aPosition < 0  || _aColor2 < 0 ) {
        throw runtime_error("Unable to get attribute location");
    }

    _uAspect2 = m_program->uniformLocation("aspect2");

    if ( _uAspect2 < 0 ) {
            throw runtime_error("Unable to get uniform location");
    }

    resize();
}

void VHAWatch::resize()
{
     QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, _width, _height);
}


void VHAWatch::synchronize(QQuickFramebufferObject *item)
{
    m_window = item->window();

    VHAWatch_FBO* obj = static_cast<VHAWatch_FBO*>(item);
    Q_UNUSED(obj);

    // sync values ...
}



void VHAWatch::render()
{

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    vector<float> vertexData;
    for (int i=0; i<12; i++)
    {
        vertexData.push_back(((i%3) ? 0.9 : 0.8) * sin(i/12.0 * 2.0 * M_PI));
        vertexData.push_back(((i%3) ? 0.9 : 0.8) * cos(i/12.0 * 2.0 * M_PI));
        vertexData.push_back(1.0 * sin(i/12.0 * 2.0 * M_PI));
        vertexData.push_back(1.0 * cos(i/12.0 * 2.0 * M_PI));
    }
    float s = now->tm_sec/60.0 * 2.0 * M_PI;
    float m = (now->tm_min+now->tm_sec/60.0)/60.0 * 2.0 * M_PI;
    float h = (now->tm_hour+now->tm_min/60.0+now->tm_sec/3600.0)/12.0 * 2.0 * M_PI;
    float hw = 0.015, hl = 0.55;
    float mw = 0.015, ml = 0.80;
    float sw = 0.005, sl = 0.80;
    vertexData.push_back(-hw * sin(h) - hw *  cos(h));
    vertexData.push_back(-hw * cos(h) - hw * -sin(h));
    vertexData.push_back(-hw * sin(h) + hw *  cos(h));
    vertexData.push_back(-hw * cos(h) + hw * -sin(h));
    vertexData.push_back( hl * sin(h) + hw *  cos(h));
    vertexData.push_back( hl * cos(h) + hw * -sin(h));
    vertexData.push_back( hl * sin(h) + hw *  cos(h));
    vertexData.push_back( hl * cos(h) + hw * -sin(h));
    vertexData.push_back( hl * sin(h) - hw *  cos(h));
    vertexData.push_back( hl * cos(h) - hw * -sin(h));
    vertexData.push_back(-hw * sin(h) - hw *  cos(h));
    vertexData.push_back(-hw * cos(h) - hw * -sin(h));

    vertexData.push_back(-mw * sin(m) - mw *  cos(m));
    vertexData.push_back(-mw * cos(m) - mw * -sin(m));
    vertexData.push_back(-mw * sin(m) + mw *  cos(m));
    vertexData.push_back(-mw * cos(m) + mw * -sin(m));
    vertexData.push_back( ml * sin(m) + mw *  cos(m));
    vertexData.push_back( ml * cos(m) + mw * -sin(m));
    vertexData.push_back( ml * sin(m) + mw *  cos(m));
    vertexData.push_back( ml * cos(m) + mw * -sin(m));
    vertexData.push_back( ml * sin(m) - mw *  cos(m));
    vertexData.push_back( ml * cos(m) - mw * -sin(m));
    vertexData.push_back(-mw * sin(m) - mw *  cos(m));
    vertexData.push_back(-mw * cos(m) - mw * -sin(m));

    vertexData.push_back(-sw * sin(s) - sw *  cos(s));
    vertexData.push_back(-sw * cos(s) - sw * -sin(s));
    vertexData.push_back(-sw * sin(s) + sw *  cos(s));
    vertexData.push_back(-sw * cos(s) + sw * -sin(s));
    vertexData.push_back( sl * sin(s) + sw *  cos(s));
    vertexData.push_back( sl * cos(s) + sw * -sin(s));
    vertexData.push_back( sl * sin(s) + sw *  cos(s));
    vertexData.push_back( sl * cos(s) + sw * -sin(s));
    vertexData.push_back( sl * sin(s) - sw *  cos(s));
    vertexData.push_back( sl * cos(s) - sw * -sin(s));
    vertexData.push_back(-sw * sin(s) - sw *  cos(s));
    vertexData.push_back(-sw * cos(s) - sw * -sin(s));

    f->glClearColor(0.0, 0.0, 0.0, 0.0);
    f->glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();
    f->glVertexAttribPointer(_aPosition, 2, GL_FLOAT, GL_FALSE, 0, &vertexData.at(0));
    f->glEnableVertexAttribArray(_aPosition);
    f->glVertexAttrib3f(_aColor2, 0.9, 0.9, 0.9);
    f->glDisableVertexAttribArray(_aColor2);
    f->glUniform1f(_uAspect2, _width / (float) _height);
    f->glLineWidth(1);
    f->glDrawArrays (GL_LINES, 0, 24);
    f->glLineWidth(10);
    f->glDrawArrays (GL_TRIANGLES, 24, 18);

    update();
    m_program->release();
}

QOpenGLFramebufferObject* VHAWatch::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    return new QOpenGLFramebufferObject(size, format);
}


