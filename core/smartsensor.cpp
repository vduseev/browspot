#define NOMINMAX

#include "smartsensor.h"
#include "abstractdevice.h"
#include "opennidevice.h"
#include "abstractstream.h"
#include "opennistream.h"

#include <QString>
#include <QTime>

#include <OpenNI.h>

SmartSensor::SmartSensor()
{	
	// Load OpenNI.
	// Initialize the library. This will load all available drivers, 
	// and see which devices are available. It is forbidden to call any 
	// other method in OpenNI before calling initialize()
	QString error = "no error";
	m_isOpenNIInitialized = 
		( openni::OpenNI::initialize() == openni::Status::STATUS_OK ) ? true : false;
	error = openni::OpenNI::getExtendedError();
	if ( m_isOpenNIInitialized )
	{
		QTime time;
		emit log( "OpenNI initialized at " + time.currentTime().toString() + "." );	
		openni::Version version = openni::OpenNI::getVersion();
		emit log( QString("   Build number: " 
			+ QString::number( version.build ) 
			+ " (is incremented for each new API build)") );
		emit log( QString("   Maintenance build number: " 
			+ QString::number( version.maintenance )) );
		emit log( QString("   Major version number: " 
			+ QString::number( version.major ) 	
			+ " (incremented for major API restructuring)") );
		emit log( QString("   Minor version number: " 
			+ QString::number( version.minor ) 	
			+ " (incremented when signficant new features added)") );
	}
	else
	{
		emit log( "OpenNI is not initialized." );
		emit log( "Extended error: " + error.simplified() );
	}
}

SmartSensor::~SmartSensor()
{
}

void SmartSensor::enumerateDevices()
{
	if ( m_isOpenNIInitialized )
	{
		// Initialize device array
		openni::Array<openni::DeviceInfo>* deviceInfoList 
			= new openni::Array<openni::DeviceInfo>();
		// Enumerate devices
		openni::OpenNI::enumerateDevices( deviceInfoList );
		if ( deviceInfoList->getSize() > 0 )
		{
			for (int i = 0; i < deviceInfoList->getSize(); i++)
			{
				openni::DeviceInfo info = deviceInfoList->operator[](i);
				OpenNIDevice* device = new OpenNIDevice();
				device->setUri( info.getUri() );
				if ( !m_devices.contains( device ) )
				{
					m_devices.append( device );
					emit deviceAttached( device );
				}
			}
		}
	}
}

void SmartSensor::openDevice( AbstractDevice* device )
{
	if ( m_devices.contains( device ) )
	{
		if ( device->type() == AbstractDevice::LightCoding )
		{
			OpenNIDevice* oniDevice = dynamic_cast<OpenNIDevice*>( device );
			if ( oniDevice->isOpen () )
			{
				emit log( "Device is already open." );
			}
			else
			{
				oniDevice->open();
				if ( oniDevice->isOpen() )
				{
					emit log( oniDevice->name() + " device with URI " +
						oniDevice->uri() + " is opened." );
				}
			}
		}
	}
	else
	{
		emit log( "No device with URI " + device->uri() );
	}
}

void SmartSensor::closeDevice( AbstractDevice* device )
{
	if ( m_devices.contains( device ) )
	{
		if ( device->isOpen() )
		{
			device->close();
			emit log( 
				device->name() + " device with URI " +
				device->uri() + " is closed." );
		}
		else
		{
			emit log( "Device is closed." );
		}
	}
	else
	{
		emit log( "No device with URI " + device->uri() );
	}
}

void SmartSensor::startStream( AbstractDevice* device, int streamType )
{
	if ( m_devices.contains( device ) )
	{
		if ( device->type() == AbstractDevice::LightCoding )
		{
			OpenNIDevice* oniDevice = dynamic_cast<OpenNIDevice*>( device );
			if ( oniDevice->isOpen () )
			{				
				oniDevice->startStream( (AbstractStream::Type)streamType );
			}
		}
		else
		{
			emit log( "Device is not open" );
		}
	}
	else
	{
		emit log( "No device with URI " + device->uri() );
	}
}

void SmartSensor::stopStream( AbstractDevice* device, int streamType )
{
	if ( m_devices.contains( device ) )
	{
		if ( device->type() == AbstractDevice::LightCoding )
		{
			OpenNIDevice* oniDevice = dynamic_cast<OpenNIDevice*>( device );
			if ( oniDevice->isOpen () )
			{
				oniDevice->stopStream( (AbstractStream::Type)streamType );
			}
		}
		else
		{
			emit log( "Device is not open" );
		}
	}
	else
	{
		emit log( "No device with URI " + device->uri() );
	}
}