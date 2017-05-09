#include "controlpanel.h"
#include "ui_controlpanel.h"

#include "devicetreeitem.h"

#include "qdebug.h"
#include <QTreeWidget>

ControlPanel::ControlPanel( QWidget *parent ) :
    QMainWindow( parent ),
	ui( new Ui::ControlPanel )
{
    ui->setupUi(this);
    create();
}

void ControlPanel::log( const QString& text )
{
	ui->outputTextEdit->insertPlainText(text);
}

void ControlPanel::insertDevice( AbstractDevice* device )
{
	
}

void ControlPanel::removeDevice( AbstractDevice* device )
{
}