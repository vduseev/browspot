#include "framelistener.h"

FrameListener::FrameListener()
{
	m_frame = new openni::VideoFrameRef();
}

FrameListener::~FrameListener()
{
	delete m_frame;
}

void FrameListener::onNewFrame(openni::VideoStream &stream)
{
	if ( stream.readFrame( m_frame ) == openni::STATUS_OK )
	{		
		emit frame( 
			m_frame->getData(), 
			m_frame->getWidth(), 
			m_frame->getHeight() );
	}
}
