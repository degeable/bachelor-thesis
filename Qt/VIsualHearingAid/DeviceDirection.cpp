#include "DeviceDirection.h"

DeviceDirection::DeviceDirection(QObject *parent)
    : QObject(parent),
      calibrationOffset(0),
      m_azimuth(0)

{


    // At first we have to connect to the sensor backend...
    if (!m_compassSensor.connectToBackend()) {
        qDebug() << "Cannot connect to compass sensor backend!";
    }

    // ... and then add a filter that will process the read data
    m_compassSensor.addFilter(this);

    // Do not report duplicated values
    m_compassSensor.setSkipDuplicates(true);

    // Start gathering the data
    m_compassSensor.start();
}

qreal DeviceDirection::azimuth() const
{
    return m_azimuth;
}

void DeviceDirection::calibrateOffset()
{
    calibrationOffset = azimuth();
}

bool DeviceDirection::filter(QCompassReading *reading)
{
    // Store the previous azimuth
    const qreal oldAzimuth = m_azimuth;

    m_azimuth = reading->azimuth(); //Switch the way the compass counts to match matrix compass

    // Emit changed signal if azimuth has changed
    if (oldAzimuth != m_azimuth){
        emit azimuthChanged();
           qDebug() <<"new compass data: "<<m_azimuth<<endl;
    }

    return false;
}

int DeviceDirection::getCalibrationOffset() const
{
    return calibrationOffset;
}
