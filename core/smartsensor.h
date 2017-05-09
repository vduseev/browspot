#ifndef SMARTSENSOR_H
#define SMARTSENSOR_H

#include <QObject>
#include <QList>

#include "smartsensor_global.h"

class AbstractDevice;

class SMARTSENSOR_EXPORT SmartSensor : public QObject
{
	Q_OBJECT

public:
	SmartSensor();
	~SmartSensor();

public slots:
	// Device control
	void openDevice( AbstractDevice* );
	void closeDevice( AbstractDevice* );
	// Stream control
	void startStream( AbstractDevice*, int streamType );
	void stopStream( AbstractDevice*, int streamType );

signals:
	void log( const QString& );
	void deviceAttached( 
		const QByteArray& uri, 
		const QByteArray& name, 
		const QByteArray& type );
	void deviceAttached( AbstractDevice* );

private slots:
	// enumeration
	void enumerateDevices();

private:
	QList<AbstractDevice*> m_devices;

	bool m_isOpenNIInitialized;
};

#endif // SMARTSENSOR_H
