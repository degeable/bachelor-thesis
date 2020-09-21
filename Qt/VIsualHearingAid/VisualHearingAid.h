#ifndef VISUALHEARINGAID_H
#define VISUALHEARINGAID_H

#include <QObject>
#include <QOpenGLFramebufferObjectFormat>
#include <QQuickFramebufferObject>
#include <QQuickWindow>
#include <QOpenGLTexture>
#include <QImageReader>
#include <QtSensors/QCompass>
#include <QtSensors/qorientationsensor.h>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QNetworkInterface>
#include <QTimer>
#include <QDebug>
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



#include "SoundEventSource.h"
#include "DirectionEventSource.h"
#include "DeviceDirection.h"

using std::deque;
using std::signal;
using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::runtime_error;

//FramebufferObject class that creates the VisualHearing Renderer when used in QML
class VisualHearingAid_FBO
        : public QQuickFramebufferObject
{
    Q_OBJECT
    Q_PROPERTY(bool frozen READ frozen WRITE setFrozen NOTIFY frozenChanged)
    Q_PROPERTY(int angle READ angle WRITE setAngle NOTIFY AngleChanged)
    Q_PROPERTY(int matrixAngle READ matrixAngle WRITE setMatrixAngle)
    Q_PROPERTY(int phoneAngle READ phoneAngle)
    Q_PROPERTY(vector<SoundEvent> SoundEvents READ soundEvents NOTIFY SoundEventsChanged)

    bool m_frozen;
    int m_angle;
    int m_matrixAngle;
    int m_phoneAngle;
    vector<SoundEvent> m_SoundEvents;
    int m_socketStatus;
    int useHeadingTracking;

public:

    explicit VisualHearingAid_FBO(QQuickItem* parent = nullptr,int MatrixCompassPort = 9000, int MatrixSoundPort= 9001);
    Renderer* createRenderer() const override;

    bool frozen() const{ return m_frozen; }
    int angle() const{ return m_angle; }
    int matrixAngle() const{return  m_matrixAngle;}
    int phoneAngle() const{return  m_phoneAngle;}
    vector<SoundEvent> soundEvents() const{return m_SoundEvents;}


private:
    DirectionEventSource MatrixCompass;
    DeviceDirection deviceCompass;
    SoundEventSource SoundSource;

public slots:
    void setUseCompass();
    void calibrateHeadings();
    void recvCompass();
    void setFrozen(bool frozen);
    void setAngle(int angle);
    void recvSoundEvents();
    void setMatrixAngle(int matrixAngle);
    void setMatrixPort(int port);
    int getMatrixPort();
    int getSocketStatus() const;
    void setCompassPort(int port);
    int getCompassPort();

signals:
    void frozenChanged(bool frozen);
    void AngleChanged(int angle);
    void SoundEventsChanged(vector<SoundEvent> SoundEvents);
};






//Renderer-class for VisualHearingAid
class VisualHearingAid
        : public QQuickFramebufferObject::Renderer,
        protected QOpenGLFunctions
{
public:
    VisualHearingAid();
    ~VisualHearingAid();
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

    int _height;
    int _width;
    GLuint _vertexShader;
    GLuint _fragmentShader;

    GLint _aSecondsAgo;
    GLint _aDirection;
    GLint _aEnergy;
    GLint _aColor;

    GLint _uSize;
    GLint _uSpeed;
    GLint _uAspect;
    GLint _uSampler;

    GLuint _texture;

    GLfloat _alpha;
    bool _frozen;
    long _freezeTime;


private:
    deque<SoundEvent> _events;

    const struct color {
        GLfloat r;
        GLfloat g;
        GLfloat b;
    } _COLOR[6] = {
    {0.0, 0.0, 1.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 1.0},
    {1.0, 1.0, 0.0},
    {1.0, 0.0, 1.0},
    //		{0.0, 0.0, 0.0},
};
};



#endif // VISUALHEARINGAID_H
