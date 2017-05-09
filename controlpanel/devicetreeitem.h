#ifndef DEVICETREEITEM_H
#define DEVICETREEITEM_H

#include <QTreeWidget>
#include <QTreeWidgetItem>

class AbstractDevice;

class DeviceTreeItem : public QTreeWidgetItem
{
public:
	DeviceTreeItem( QTreeWidget* parent, AbstractDevice* prototype );
	~DeviceTreeItem();

private:
	AbstractDevice* m_prototype;	
};

#endif // DEVICETREEITEM_H
