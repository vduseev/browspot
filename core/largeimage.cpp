#include "largeimage.h"

#include <QPainter>

LargeImage::LargeImage()
{
	resize( 640, 480 );
    create();
	setWindowTitle(QString( "SmartSensor large image" ));

	QImage* image = new QImage( 1, 1, QImage::Format::Format_RGB32 );
	image->fill( Qt::GlobalColor::black );
	m_image = image;
}

void LargeImage::receiveImage( const QImage* image )
{
	m_image = image;
	this->update();
}

void LargeImage::resizeEvent( QResizeEvent* event )
{
	m_rectangle = QRect( 0, 0, this->width(), this->height() );
	QWidget::resizeEvent( event );
}

void LargeImage::paintEvent( QPaintEvent* event )
{
	QPainter painter( this );
	painter.drawImage( m_rectangle, *m_image );
}