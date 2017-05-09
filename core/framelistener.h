#ifndef FRAMELISTENER_H
#define FRAMELISTENER_H

#include <OpenNI.h>

#include <QObject>

class FrameListener : public QObject, public openni::VideoStream::NewFrameListener
{
	Q_OBJECT

public:
	FrameListener();
	~FrameListener();

	void onNewFrame( openni::VideoStream &stream ) override;

signals:
	void frame( const void*, const int&, const int& );

private:
	openni::VideoFrameRef* m_frame;
};

#endif