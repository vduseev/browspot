#ifndef ABSTRACTSTREAM_H
#define ABSTRACTSTREAM_H

#include <QObject>
#include <QImage>

class AbstractStream : public QObject
{
	Q_OBJECT

public:
	AbstractStream(QObject *parent = (QObject*)0)
		: QObject(parent)
		, m_created( false )
		, m_running( false )
	{
	}
	~AbstractStream() {}

	enum Type
	{
		OniColor		= 0x01,
		OniDepth		= 0x02,
		OniIR			= 0x03,
		RGB8			= 0x01
	};

	virtual void create() {};
	virtual void destroy() = 0;
	virtual void start() = 0;
	virtual void stop() = 0;

	bool isCreated()		const { return m_created; }
	bool isRunning()		const { return m_running; }	
	void setType( const Type& type ) { m_type = type; }
	const Type& type() const { return m_type; }

signals:
	void created();
	void started();
	void stopped();
	void destroyed();
	/**
		\brief Frame signal.
	*/
	void frameReady( const void* data, const int& width, const int& height );

public:
	QImage* createEmptyImage()
	{
		QImage* image = new QImage( 1, 1, QImage::Format::Format_RGB32 );
		image->fill( Qt::GlobalColor::black );
		return image;
	}

protected:
	bool m_created;
	bool m_running;
	Type m_type;
};

#endif // ABSTRACTSTREAM_H
