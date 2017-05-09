#ifndef OPENNIDEVICE_H
#define OPENNIDEVICE_H

#include "abstractdevice.h"
#include "opennistream.h"

#include <OpenNI.h>

#include <QObject>
#include <QList>

class OpenNIDevice : public AbstractDevice
{
	Q_OBJECT

public:
	OpenNIDevice();
	~OpenNIDevice();

	bool isDepthSupported() { return m_isDepthSupported; }
	bool isColorSupported() { return m_isColorSupported; }
	bool isIRSupported() { return m_isIRSupported; }

public slots:
	virtual void open() override;
	virtual void close() override;
	virtual void startStream( AbstractStream::Type ) override;
	virtual void stopStream( AbstractStream::Type ) override;
	
private:
	// Internal device handled by driver
	openni::Device	m_device;
	// Streams
	OpenNIStream* m_depthStream;
	OpenNIStream* m_colorStream;
	OpenNIStream* m_IRStream;

	bool m_isDepthSupported;
	bool m_isColorSupported;
	bool m_isIRSupported;
};

#endif