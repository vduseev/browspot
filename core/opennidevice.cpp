#include "opennidevice.h"

#include <QString>
#include <qdebug.h>

OpenNIDevice::OpenNIDevice()
	: AbstractDevice()
{
	setType( LightCoding );
}

OpenNIDevice::~OpenNIDevice()
{
	if ( isOpen() )
	{
		close();
	}
}

void OpenNIDevice::open()
{	
	int ok = openni::STATUS_OK;
	m_open = ( m_device.open( m_uri.constData() ) == ok ) ? true : false;
	
	// If there is an error, then report it
	if ( m_open )
	{	
		setName( m_device.getDeviceInfo().getName() );

		if ( m_device.hasSensor( openni::SENSOR_DEPTH ) )
		{
			m_isDepthSupported = true;
			m_depthStream = new OpenNIStream();
			emit streamFound( AbstractStream::OniDepth );
		}

		if ( m_device.hasSensor( openni::SENSOR_COLOR ) )
		{
			m_isColorSupported = true;
			m_colorStream = new OpenNIStream();
			emit streamFound( AbstractStream::OniColor );
		}

		if ( m_device.hasSensor( openni::SENSOR_IR ) )
		{
			m_isIRSupported = true;
			m_IRStream = new OpenNIStream();
			emit streamFound( AbstractStream::OniIR );
		}
	}
	else
	{	
		QByteArray error =  openni::OpenNI::getExtendedError();
		qCritical() << "SmartSensor>> Can`t open device. URI: " << m_uri;
		qCritical()	<< "SmartSensor>> Extended error: " << error.simplified();
	}
}

void OpenNIDevice::close()
{
	m_device.close();
	m_open = false;
}

void OpenNIDevice::startStream( AbstractStream::Type type )
{
	if ( type == AbstractStream::OniDepth && m_isDepthSupported )
	{
		if ( m_depthStream->isCreated() )
		{
			m_depthStream->start();
		}
		else
		{
			m_depthStream->create( m_device, openni::SENSOR_DEPTH );
			m_depthStream->start();
		}
	}
	else if ( type == AbstractStream::OniColor && m_isColorSupported )
	{
		if ( m_colorStream->isCreated() )
		{
			m_colorStream->start();
		}
		else
		{
			m_colorStream->create( m_device, openni::SENSOR_COLOR );
			m_colorStream->start();
		}
	}
	else if ( type == AbstractStream::OniIR && m_isIRSupported )
	{
		if ( m_IRStream->isCreated() )
		{
			m_IRStream->start();
		}
		else
		{
			m_IRStream->create( m_device, openni::SENSOR_IR );
			m_IRStream->start();
		}
	}
}

void OpenNIDevice::stopStream( AbstractStream::Type type )
{
	if ( type == AbstractStream::OniDepth && m_isDepthSupported )
	{
		if ( m_depthStream->isCreated() )
		{
			if ( m_depthStream->isRunning() )
			{
				m_depthStream->stop();
			}
		}
	}
	else if ( type == AbstractStream::OniColor && m_isColorSupported )
	{
		if ( m_colorStream->isCreated() )
		{
			if ( m_colorStream->isRunning() )
			{
				m_colorStream->stop();
			}
		}
	}
	else if ( type == AbstractStream::OniIR && m_isIRSupported )
	{
		if ( m_IRStream->isCreated() )
		{
			if ( m_IRStream->isRunning() )
			{
				m_IRStream->stop();
			}
		}
	}
}