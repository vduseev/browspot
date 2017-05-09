#include "devicetreeitem.h"
#include "abstractdevice.h"

DeviceTreeItem::DeviceTreeItem( QTreeWidget* parent, AbstractDevice* prototype )
	: QTreeWidgetItem( parent )
	, m_prototype( prototype )
{

}

DeviceTreeItem::~DeviceTreeItem()
{

}
