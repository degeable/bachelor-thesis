#ifndef Vha_H
#define Vha_H

#include <QtQuick/QQuickItem>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLFunctions>

class VhaRenderer : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    VhaRenderer() : m_t(0), m_program(0) { }
    ~VhaRenderer();

    void setT(qreal t) { m_t = t; }
    void setViewportSize(const QSize &size) { m_viewportSize = size; }
    void setWindow(QQuickWindow *window) { m_window = window; }

public slots:
    void init();
    void paint();

private:

    QSize m_viewportSize;
    qreal m_t;
    QOpenGLShaderProgram *m_program;
    QQuickWindow *m_window;

    uint positionAttr_;
    uint colorAttr_;
    int matrixAttr_;
};

class Vha : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(qreal t READ t WRITE setT NOTIFY tChanged)

public:
    Vha();

    qreal t() const { return m_t; }
    void setT(qreal t);

signals:
    void tChanged();

public slots:
    void sync();
    void cleanup();

private slots:
    void handleWindowChanged(QQuickWindow *win);

private:
    void releaseResources() override;


    qreal m_t;
    VhaRenderer *m_renderer;
};


#endif // Vha_H
