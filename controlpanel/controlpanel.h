#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include "controlpanel_global.h"

#include <QMainWindow>
#include <QMenu>

class AbstractDevice;

namespace Ui {
	class ControlPanel;
}

class ControlPanel : public QMainWindow
{
	// This allows the connection between class and Qt Meta-system
    Q_OBJECT

public:
    explicit ControlPanel(QWidget *parent = 0);

signals:
	void enumerateDevicesButtonClicked();

public slots:
	void log( const QString& text);
	void insertDevice( AbstractDevice* device );
	void removeDevice( AbstractDevice* device );
	
protected:

private:
	Ui::ControlPanel* ui;
};

#endif // CONTROLPANEL_H
