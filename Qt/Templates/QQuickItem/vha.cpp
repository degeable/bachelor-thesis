#include "vha.h"

#include <QtQuick/qquickwindow.h>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLContext>
#include <QtCore/QRunnable>


Vha::Vha()
    : m_t(0)
    , m_renderer(nullptr)
{
    connect(this, &QQuickItem::windowChanged, this, &Vha::handleWindowChanged);
}

void Vha::setT(qreal t)
{
    if (t == m_t)
        return;
    m_t = t;
    emit tChanged();
    if (window())
        window()->update();
}

void Vha::handleWindowChanged(QQuickWindow *win)
{
    if (win) {
        connect(win, &QQuickWindow::beforeSynchronizing, this, &Vha::sync, Qt::DirectConnection);
        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &Vha::cleanup, Qt::DirectConnection);

        // Ensure we start with cleared to black. The Vha's blend mode relies on this.
        win->setColor(Qt::black);
    }
}


void Vha::cleanup()
{
    delete m_renderer;
    m_renderer = nullptr;
}

class CleanupJob : public QRunnable
{
public:
    CleanupJob(VhaRenderer *renderer) : m_renderer(renderer) { }
    void run() override { delete m_renderer; }
private:
    VhaRenderer *m_renderer;
};

void Vha::releaseResources()
{
    window()->scheduleRenderJob(new CleanupJob(m_renderer), QQuickWindow::BeforeSynchronizingStage);
    m_renderer = nullptr;
}

VhaRenderer::~VhaRenderer()
{
    delete m_program;
}

void Vha::sync()
{
    if (!m_renderer) {
        m_renderer = new VhaRenderer();
        connect(window(), &QQuickWindow::beforeRendering, m_renderer, &VhaRenderer::init, Qt::DirectConnection);
        connect(window(), &QQuickWindow::beforeRenderPassRecording, m_renderer, &VhaRenderer::paint, Qt::DirectConnection);
    }
    m_renderer->setViewportSize(window()->size() * window()->devicePixelRatio());
    m_renderer->setT(m_t);
    m_renderer->setWindow(window());

}

void VhaRenderer::init()
{

    initializeOpenGLFunctions();
    m_program = new QOpenGLShaderProgram();
    //glClearColor(0.1f, 0.1f, 0.2f, 1.0f); // opaque
    glClearColor(0.1f, 0.1f, 0.2f, 0.0f); // transparent

    // just the default shaders:
    const char *vertexShaderSrc =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

    const char *fragmentShaderSrc =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";

    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSrc);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSrc);
    m_program->link();
    positionAttr_ = m_program->attributeLocation("posAttr");
    colorAttr_ = m_program->attributeLocation("colAttr");
    matrixAttr_ = m_program->uniformLocation("matrix");


}


void VhaRenderer::paint()
{

    // use OpenGl 2.0
    glClear(GL_COLOR_BUFFER_BIT);

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

    glVertexAttribPointer(positionAttr_, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(colorAttr_, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    m_program->release();

}

