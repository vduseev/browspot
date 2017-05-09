#ifndef OPENNISTREAM_H
#define OPENNISTREAM_H

#include "abstractstream.h"
#include "framelistener.h"
#include "opennidatatypes.h"

#include <QObject>
#include <OpenNI.h>

class OpenNIStream : public AbstractStream
{
	Q_OBJECT

public:	
	OpenNIStream( QObject *parent = (QObject*)0 );
	~OpenNIStream();

	// Depth filters available for use
	enum DepthFilters
	{
		Statistical,
		Kalman,
		Median,
		TeleaFastMarching
	};

signals:
	void imageReady( const QImage* );

public slots:
	virtual void create( openni::Device&, openni::SensorType );
	virtual void destroy() override;
	virtual void start() override;
	virtual void stop() override;

	void processFrame( const void*, const int&, const int& );

private:
	FrameListener*			m_listener;
	openni::VideoStream*	m_videoStream;
	openni::SensorType		m_oniType;
	QImage* m_image;
	bool	m_hasListener;

private:
	QImage* createDepthImage(
		const DepthPixel*,
		const int&, const int& );
	QImage* createColorImage(
		const ColorPixel*,
		const int&, const int& );
};

#endif

