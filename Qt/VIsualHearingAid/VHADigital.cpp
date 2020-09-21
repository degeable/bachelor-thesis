#include "VHADigital.h"

using std::vector;
using std::runtime_error;

//*****VHADigital_FBO*****

VHADigital_FBO::VHADigital_FBO(QQuickItem *parent)
                : QQuickFramebufferObject(parent)
{
}
auto VHADigital_FBO::createRenderer() const -> QQuickFramebufferObject::Renderer*
{
    return new VHADigital();
}

//*****VHADigital*****

VHADigital::VHADigital() :
            m_program(0)

{
    QScreen *s = QGuiApplication::primaryScreen();
    _width = s->availableSize().width();
    _height = s->availableSize().height();
    initOGL();
}

VHADigital::~VHADigital()
{
    //maybe that does the same?
    m_program = 0;
    delete m_program;
}

void VHADigital::initOGL()
{
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

void VHADigital::synchronize(QQuickFramebufferObject *item)
{
    m_window = item->window();

    VHADigital_FBO* obj = static_cast<VHADigital_FBO*>(item);
    Q_UNUSED(obj);

    //no values to sync here
}



void VHADigital::render()
{

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    time_t t = time(0);   // get time now
    tm* now = localtime(&t);

    VectorCharacter vc;
    v.clear();
    vc.vertexData(v, 1.2, -0.9, 12.6, now->tm_hour/10);
    vc.vertexData(v, 1.2, -0.3, 12.6, now->tm_hour%10);
    vc.vertexData(v, 1.2, -0.9, 11.6, now->tm_min/10);
    vc.vertexData(v, 1.2, -0.3, 11.6, now->tm_min%10);

    f->glClearColor(0.0, 0.0, 0.0, 0.0);
    f->glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();


    if(v.size()>0){
        f->glVertexAttribPointer(_aPosition, 2, GL_FLOAT, GL_FALSE, 0, &v.at(0));
        f->glEnableVertexAttribArray(_aPosition);
        f->glVertexAttrib3f(_aColor2, 0.9, 0.9, 0.9);
        f->glDisableVertexAttribArray(_aColor2);
        f->glUniform1f(_uAspect2, _width / (float) _height);
        f->glLineWidth(1);
        f->glDrawArrays (GL_LINES, 0, v.size()/2);
    }

    update();
    m_program->release();
}

void VHADigital::resize()
{
        QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
        _width = 320;
        _height = 480;
        f->glViewport(0, 0, _width, _height);
}

QOpenGLFramebufferObject* VHADigital::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    return new QOpenGLFramebufferObject(size, format);
}


