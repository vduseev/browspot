#ifndef ABSTRACTDEVICE_H
#define ABSTRACTDEVICE_H

#include <QObject>

#include "abstractstream.h"

class AbstractDevice : public QObject
{
	Q_OBJECT

public:
	AbstractDevice(QObject *parent = (QObject*)0)
		: QObject( parent )
		, m_open( false )
	{
	}
	~AbstractDevice() {}

	enum Type
	{
		LightCoding		= 0x0010,
		Kinect			= 0x0010, 
		Carmin			= 0x0010,
		PrimeSense		= 0x0010,
		WebCamera		= 0x0034
	};
		
	bool isOpen() const { return m_open; }
	const QByteArray& uri() const { return m_uri; }
	const QByteArray& name() const { return m_name; }
	const Type& type() const { return m_type; }

signals:
	void streamFound( AbstractStream::Type );
	
public slots:
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void startStream( AbstractStream::Type ) = 0;
	virtual void stopStream( AbstractStream::Type ) = 0;

	void setUri( const QByteArray& uri ) { m_uri = uri; }
	void setName( const QByteArray& name ) { m_name = name; }
	void setType( const Type& type ) { m_type = type; }

protected:
	bool m_open;

	QByteArray	m_uri;
	QByteArray	m_name;
	Type		m_type;
};

#endif // ABSTRACTDEVICE_H
