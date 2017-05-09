#include "opennistream.h"

#include <OpenNI.h>

#include <qdebug.h>
#include <QImage>

OpenNIStream::OpenNIStream( QObject *parent )
	: AbstractStream( parent )
	, m_hasListener( false )
{
	m_videoStream	= new openni::VideoStream();
	m_listener		= new FrameListener();
	m_image			= createEmptyImage();
}

OpenNIStream::~OpenNIStream()
{
	if ( m_running )
		stop();

	if ( m_created )
		destroy();
}

void OpenNIStream::create( openni::Device& device, openni::SensorType type )
{	
	m_oniType = type;
	switch ( m_oniType )
	{
	case openni::SENSOR_DEPTH:
		setType( OniDepth );
		break;
	case openni::SENSOR_COLOR:
		setType( OniColor );
		break;
	case openni::SENSOR_IR:
		setType( OniIR );
		break;
	}

	int ok = openni::STATUS_OK;	
	m_created = ( m_videoStream->create( device, type ) == ok ) ?
		true : false;
	QByteArray error = openni::OpenNI::getExtendedError();

	if ( m_created )
	{
		m_hasListener = ( m_videoStream->addNewFrameListener( m_listener ) == ok ) 
			? true : false;
		error = openni::OpenNI::getExtendedError();

		if ( m_hasListener )
		{
			connect( 
				m_listener, 
				SIGNAL( frame( const void*, const int&, const int& ) ),
				this, 
				SIGNAL( frameReady( const void*, const int&, const int& ) ) 
			);
			connect( 
				m_listener, 
				SIGNAL( frame( const void*, const int&, const int& ) ),
				this, 
				SLOT( processFrame( const void*, const int&, const int& ) ) 
			);
			
			emit created();
		}
		else
		{
			qCritical() 
				<< "SmartSensor>> Can`t add frame listener to " 
				<< "stream.\n"
				<< "Extended error: " << error;
		}
	}
	else
	{
		qCritical() 
			<< "SmartSensor>> Can`t add frame listener to " 
			<< "stream. This stream is not created by " 
			<< device.getDeviceInfo().getName() << " device.\n" 
			<< "Extended error: " << error;
	}
}

void OpenNIStream::destroy()
{
	if ( m_created )
	{
		m_videoStream->destroy();
		m_created = false;
		emit destroyed();
	}
}

void OpenNIStream::start()
{
	int ok = openni::STATUS_OK;
	if ( m_created )
	{
		m_running = ( m_videoStream->start() == ok ) ? true : false;
		QByteArray error = openni::OpenNI::getExtendedError();
		if ( m_running )
		{
			emit started();
		}
		else
		{
			qCritical() 
				<< "SmartSensor>> Can`t start stream.\n"	
				<< "Extended error: " << error;
		}
	}
	else
	{
		qCritical() 
			<< "SmartSensor>> Can`t start stream. "
			<< "Stream is not created";
	}
}

void OpenNIStream::stop()
{
	if ( m_running )
	{
		m_videoStream->stop();
		m_running = false;
		emit stopped();
	}
}

void OpenNIStream::processFrame( const void* data, const int& width, const int& height )
{
	delete m_image;
	
	switch ( m_oniType )
	{
	case openni::SENSOR_DEPTH:
		m_image = createDepthImage( (DepthPixel*)data, width, height );
		emit imageReady( m_image );
		break;
	case openni::SENSOR_COLOR:
		m_image = createColorImage( (ColorPixel*)data, width, height );
		emit imageReady( m_image );
		break;
	case openni::SENSOR_IR:
		m_image = createColorImage( (ColorPixel*)data, width, height );
		emit imageReady( m_image );
		break;
	}
}

QImage* OpenNIStream::createDepthImage(
		const DepthPixel* depthData,
		const int& width, const int& height )
{	
	/* Copy-past from QtKinectWrapper project */

	uint16_t XRes = width;
	uint16_t YRes = height;
	const DepthPixel* pixel = depthData;
	
	QImage* image = new QImage( XRes, YRes, QImage::Format::Format_RGB32 );
		
	unsigned maxdist = 0;
	for (unsigned nY = 0; nY < YRes; nY++)
	{
		for (unsigned nX=0; nX < XRes; nX++)
		{
			unsigned depth = *pixel;
			if (depth > maxdist) maxdist = depth;
			
			pixel++;
		}
	}

	pixel = depthData;
	for (unsigned nY = 0; nY < YRes; nY++)
	{
		uchar *imageptr = image->scanLine(nY);

		for (unsigned nX=0; nX < XRes; nX++)
		{
			unsigned depth = *pixel;

			if (depth > maxdist) depth = maxdist;
			if (depth)
			{
				depth = ( maxdist - depth ) * 255 / maxdist + 1;
			}
			// depth: 0: invalid
			// depth: 255: closest
			// depth: 1: furtherst (maxdist distance)

			// Here we could do depth*color, to show the colored depth
			imageptr[0] = depth;
			imageptr[1] = depth;
			imageptr[2] = depth;
			imageptr[3] = 0xff;
			
			pixel++;
			imageptr+=4;
		}
	}

	return image;
	/* End copy past */
}

QImage* OpenNIStream::createColorImage(
	const ColorPixel* colorData,
	const int& width, const int& height )
{
	uint16_t XRes = width;
	uint16_t YRes = height;
	const ColorPixel* pixel = colorData;
	
	QImage* image = new QImage( XRes, YRes, QImage::Format::Format_RGB32 );

	for (unsigned nY = 0; nY < YRes; nY++)
	{
		uchar *imageptr = image->scanLine(nY);

		for (unsigned nX=0; nX < XRes; nX++)
		{
			imageptr[0] = pixel->b;
			imageptr[1] = pixel->g;
			imageptr[2] = pixel->r;
			imageptr[3] = 0xff;
			
			pixel++;
			imageptr+=4;
		}
	}

	return image;
}
