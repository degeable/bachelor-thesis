#ifndef DEVICEDIRECTION_H
#define DEVICEDIRECTION_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <QtSensors/QCompassFilter>

using std::cout;
using std::endl;

 /**
  * The CompassSensor class uses the QCompass class from the QtSensors
  * module to retrieve the current azimuth values from the compass sensor of the device.
  */
class DeviceDirection : public QObject, public QCompassFilter
 {
     Q_OBJECT

     // The property to access the azimuth value of the compass sensor
     Q_PROPERTY(qreal azimuth READ azimuth NOTIFY azimuthChanged)

 public:
     DeviceDirection(QObject *parent = 0);

     // The accessor method for the azimuth property
     qreal azimuth() const;

     void calibrateOffset();

     int getCalibrationOffset() const;

Q_SIGNALS:
     // The change notification signal of the azimuth property
     void azimuthChanged();

 protected:
     /**
      * This method is reimplemented from the QCompassFilter interface and is
      * called by the QCompass whenever new values are available.
      */
     bool filter(QCompassReading *reading);

 private:
     // The compass sensor
     QCompass m_compassSensor;

     // The azimuth value
     int calibrationOffset;
     qreal m_azimuth;
 };

#endif // DEVICEDIRECTION_H
