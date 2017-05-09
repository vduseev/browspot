#ifndef LARGEIMAGE_H
#define LARGEIMAGE_H

#include <QWidget>
#include <QImage>

class LargeImage : public QWidget
{
	// This allows the connection between class and Qt Meta-system
    Q_OBJECT

public:
    LargeImage();

public slots:
	void receiveImage( const QImage* );
	
protected:
	void resizeEvent( QResizeEvent* event );
	void paintEvent( QPaintEvent* event );

private:
	const QImage* m_image;
	QRect m_rectangle;
};

#endif