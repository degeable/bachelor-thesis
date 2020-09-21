#include "VisualHearingAid.h"


void VisualHearingAid_FBO::setFrozen(bool frozen)
{
    if (m_frozen == frozen)
        return;
    m_frozen = frozen;
    emit frozenChanged(m_frozen);
    update();
}

void VisualHearingAid_FBO::setAngle(int angle)
{
    if (m_angle == angle)
        return;

    m_angle = angle;
    qDebug()<<"new angle set in FBO: "<<m_angle<<endl;
    emit AngleChanged(m_angle);
    //update(); //we dont need to update because the angle has no interest in the render thread
}

void VisualHearingAid_FBO::recvSoundEvents()
{
    recvCompass();
    try {
          m_SoundEvents = SoundSource.get();
    } catch (std::runtime_error& e) {
        cout<<"Socket Error: "<<e.what()<<endl;
        m_socketStatus = 1;
     }
    if(!m_frozen)
        update(); // we update so we sync the SoundEVents with the renderer Thread
}

void VisualHearingAid_FBO::setMatrixAngle(int matrixAngle)
{
    m_matrixAngle = matrixAngle;
}

void VisualHearingAid_FBO::setMatrixPort(int port)
{
    SoundSource.closeSocket();
    try {
       SoundSource = SoundEventSource(port);
    } catch (std::runtime_error& e) {
       cout<<"Set new Matrix port failed: "<<e.what()<<endl;
       m_socketStatus = 1;
    }
    m_socketStatus = 0;
    cout<<"new Matrix port set: "<<port<<endl;

}




int VisualHearingAid_FBO::getSocketStatus() const
{
    return m_socketStatus;
}

void VisualHearingAid_FBO::setCompassPort(int port)
{
    MatrixCompass.closeSocket();
    try {
       MatrixCompass = DirectionEventSource(port);
    } catch (std::runtime_error& e) {
       cout<<"Set new Compass port failed: "<<e.what()<<endl;
       //TODO set status flag so we can produce an error in QML?
    }
    cout<<"new Compass port set: "<<port<<endl;

}

int VisualHearingAid_FBO::getCompassPort()
{
   return MatrixCompass.getPort();
}


VisualHearingAid_FBO::VisualHearingAid_FBO(QQuickItem* parent, int MatrixCompassPort, int MatrixSoundPort)
    : QQuickFramebufferObject(parent),
      m_matrixAngle(0),
      m_socketStatus(0),
      useHeadingTracking(0),
      MatrixCompass(MatrixCompassPort),
      SoundSource(MatrixSoundPort)


{

    //Timer to recv the SoundEvents
    QTimer *soundTimer = new QTimer(this);
    QObject::connect(soundTimer, SIGNAL(timeout()), this, SLOT(recvSoundEvents()));
    soundTimer->start(5);

}

void VisualHearingAid_FBO::setUseCompass()
{
    if(!useHeadingTracking){
        useHeadingTracking=1;
    }else{
        useHeadingTracking=0;
    }
}

void VisualHearingAid_FBO::calibrateHeadings()
{
    cout<<"calibrated.."<<endl;
    MatrixCompass.calibrateOffset();
    deviceCompass.calibrateOffset();
}

int VisualHearingAid_FBO::getMatrixPort()
{
  return SoundSource.getPort();
}

void VisualHearingAid_FBO::recvCompass()
{
      if (!useHeadingTracking)
          return;


    //if the Compass port is 0, we dont need to smooth out the vlaues...
   /* if(MatrixCompass.getPort()!= 0){
        m_matrixAngle = 0.85*m_matrixAngle + 0.15 * MatrixCompass.get();
    }else{ */
        m_matrixAngle = MatrixCompass.get(); //to
      //}
    m_phoneAngle = deviceCompass.azimuth(); // from

    m_matrixAngle -= MatrixCompass.getCalibrationOffset(); //bring calibration in
    m_phoneAngle -= deviceCompass.getCalibrationOffset();

    if(m_matrixAngle < 0 )
        m_matrixAngle += 360;

    if(m_phoneAngle < 0 )
        m_phoneAngle += 360;

    int diff = (m_matrixAngle - m_phoneAngle) % 360;
    if(diff < 0) {
           diff += 360; //normalize to [0, 360) range
       }

    if(diff > 180) {
       diff -= 360; //normalize to (-180, 180] range
       }
     diff = -diff;

    qDebug()<<"Matrix: "<<m_matrixAngle<<" PhoneAngle: "<<m_phoneAngle<<" diff: "<<diff<<endl;
    setAngle(diff);

}

auto VisualHearingAid_FBO::createRenderer() const -> QQuickFramebufferObject::Renderer*
{
    return new VisualHearingAid();
}



VisualHearingAid::VisualHearingAid()
    : m_program(0),
      _alpha(0.9),
      _frozen(false)
{
    QScreen *s = QGuiApplication::primaryScreen();
    _width = s->availableSize().width() ;
    _height = s->availableSize().height() ;

    qInfo() <<"Screen size: "<< _width << "x"<<_height<<endl;

    initOGL();

    //print local IP adress for creator.cfg
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
            qInfo() << address.toString();
    }
}

VisualHearingAid::~VisualHearingAid()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glDeleteTextures(1, &_texture);
    //maybe that does the same?
    m_program = 0;
    delete m_program;

}

void VisualHearingAid::resize()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, _width, _height);
}

void VisualHearingAid::initOGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    if (m_program) {
        delete m_program;
        m_program = 0;
    }

    //compile shader
    const char vertex_src [] = "\
            precision mediump float;					\
    attribute float aSecondsAgo;					\
    attribute vec4 aDirection;					\
    attribute float aEnergy;					\
    attribute vec4 aColor;						\
    uniform float uSize;						\
    uniform float uSpeed;						\
    uniform float uAspect;						\
    varying vec4 vColor;						\
    \
    void main()									\
    {											\
        float scale =							\
                1.0 / (1.0 + uSpeed * aSecondsAgo);	\
        vec4 pos = aDirection;					\
        pos.xy *= scale;						\
        pos.z = 0.0;							\
        if(uAspect>1.0)							\
        {										\
            pos.x /= uAspect;					\
        }										\
        else									\
        {										\
            pos.y *= uAspect;					\
        }										\
        gl_Position = pos;						\
        gl_PointSize = uSize*aEnergy*scale;		\
        vColor = aColor;						\
    }											\
    ";


    const char fragment_src [] = "\
            precision mediump float;					\
    uniform sampler2D uSampler;					\
    varying vec4 vColor;						\
    \
    void  main()								\
    {											\
        vec4 c;									\
        c = texture2D(uSampler, gl_PointCoord);	\
        gl_FragColor = c * vColor;				\
    }											\
    ";
    m_program = new QOpenGLShaderProgram;
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,vertex_src);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragment_src);
    m_program->link();


    // gather attribute and uniform handles

    _aSecondsAgo = m_program->attributeLocation("aSecondsAgo");
    _aDirection = m_program->attributeLocation("aDirection");
    _aEnergy = m_program->attributeLocation("aEnergy");
    _aColor = m_program->attributeLocation("aColor");

    if ( _aSecondsAgo < 0  ||  _aDirection < 0  ||  _aEnergy < 0 || _aColor < 0 ) {
        cout << _aSecondsAgo << " " << _aDirection << " " << _aEnergy /*<< " " << _aColor*/ << endl;
        throw runtime_error("Unable to get attribute location");
    }

    _uSize = m_program->uniformLocation("uSize");
    _uSpeed = m_program->uniformLocation("uSpeed");
    _uAspect = m_program->uniformLocation("uAspect");
    _uSampler = m_program->uniformLocation("uSampler");

    if ( _uSize < 0 || _uSpeed < 0 || _uAspect < 0 || _uSampler < 0 ) {
        throw runtime_error("Unable to get uniform location");
    }

    // load sphere texture without png++ lib
    QImage sphere = QImage(QString(":/pic/sphere.png")).mirrored();

    if (sphere.isNull()){
        cerr << "image could not be loaded"<< endl;
        throw runtime_error("loaded image is NULL");
    }
    //convert to RGBA (not sure if thats necessary)
    sphere = sphere.convertToFormat(QImage::Format_RGBA8888);
    qDebug()<<"Texture Width: "<<sphere.width()<<" and Height: "<<sphere.height()<<endl;

    f->glGenTextures(1, &_texture);
    f->glBindTexture(GL_TEXTURE_2D, _texture);
    f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sphere.width(),
                    sphere.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,
                    sphere.bits());


    // Set the filtering mode
    f->glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    f->glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

    // set up alpha blending
    f->glEnable(GL_BLEND);
    f->glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // set viewport to window width
    resize();

}


void VisualHearingAid::synchronize(QQuickFramebufferObject *item)
{
    m_window = item->window();

    VisualHearingAid_FBO* obj = static_cast<VisualHearingAid_FBO*>(item);
    Q_UNUSED(obj);
    //check if freeze button was pressed
    _frozen = obj->frozen();
    //get new SoundEvents
    vector<SoundEvent> _result = obj->soundEvents();
    _events.insert(_events.end(), _result.begin(), _result.end());
}


void VisualHearingAid::render()
{

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    f->glClearColor(0.0, 0.0, 0.0, 1.0);
    f->glClear(GL_COLOR_BUFFER_BIT);

    // remember current time
    struct timeval t;
    gettimeofday(&t, NULL);
    static long int last = t.tv_sec * 1000000 + t.tv_usec;

    long int now = t.tv_sec * 1000000 + t.tv_usec;

    // simplify handling of frozen / non-frozen states
    // if not frozen, freeze time simply is the current time
    if (!_frozen)
    {
        _freezeTime = now;
    }

    float frozenSeconds = (now-_freezeTime)/1000000.0;

    // age existing events by lapsed time since last render
    // assign color based on id
    {
        for(unsigned int i=0; i< _events.size(); i++)
        {
            _events[i].secondsAgo += (now-last)/1000000.0;
            _events[i].r = _COLOR[_events[i].id % 6].r;
            _events[i].g = _COLOR[_events[i].id % 6].g;
            _events[i].b = _COLOR[_events[i].id % 6].b;
            _events[i].a = _alpha;
        }
        last = now;
    }

    //	cout << _events.size() << " events" << endl;

    while (!_events.empty() && _events.front().secondsAgo > (30.0 + frozenSeconds) )
    {
        _events.pop_front();
    }

    // we have to convert to vector to have a contiguous memory block
    // v has to be static, not local, as graphics driver is accessing
    // the memory also after this method ends
    static vector<SoundEvent> v;
    v = {_events.begin(), _events.end()};
    qDebug() << v.size() << " points to render" << endl;

    for(unsigned int i=0; i < v.size(); i++)
    {
        v[i].secondsAgo -= frozenSeconds;
    }

    m_program->bind(); //This is equivalent to calling glUseProgram()

    if (v.size() > 0)
    {

        f->glVertexAttribPointer(_aSecondsAgo, 1, GL_FLOAT, GL_FALSE, sizeof(SoundEvent), &v.at(0).secondsAgo);
        f->glEnableVertexAttribArray(_aSecondsAgo);
        f->glVertexAttribPointer(_aDirection, 3, GL_FLOAT, GL_FALSE, sizeof(SoundEvent), &v.at(0).x);
        f->glEnableVertexAttribArray(_aDirection);
        f->glVertexAttribPointer(_aEnergy, 1, GL_FLOAT, GL_FALSE, sizeof(SoundEvent), &v.at(0).E);
        f->glEnableVertexAttribArray(_aEnergy);
        f->glVertexAttribPointer(_aColor, 4, GL_FLOAT, GL_FALSE, sizeof(SoundEvent), &v.at(0).r);
        f->glEnableVertexAttribArray(_aColor);
    }


    //changed _width/4.0 : _height/4.0 so the bubbles are bigger on mobile screens
    f->glUniform1f(_uSize, (_width<_height) ? _width/1.0 : _height/1.0);

    f->glUniform1f(_uSpeed, 1.0);

    f->glUniform1f(_uAspect, _width / (float) _height);

    f->glActiveTexture ( GL_TEXTURE0 );
    f->glBindTexture(GL_TEXTURE_2D, _texture);
    f->glUniform1i(_uSampler,0);

    f->glDrawArrays(GL_POINTS, 0, v.size());

    //if (!_frozen)
    //    update();
    resize();
    m_program->release();


}

QOpenGLFramebufferObject* VisualHearingAid::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    return new QOpenGLFramebufferObject(size, format);
}
