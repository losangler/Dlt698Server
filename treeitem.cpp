#include "treeitem.h"

TreeItem::TreeItem() : m_parentItem(NULL)
{

}

TreeItem::TreeItem(const QList<QVariant> &data, TreeItem *parent)
    : m_itemData(data), m_parentItem(parent)
{

}

TreeItem::~TreeItem()
{
    qDeleteAll(m_childItems);
}

TreeItem *TreeItem::child(int row)
{
    return this->m_childItems.at(row);
}

void TreeItem::appendChild(TreeItem *child)
{
    this->m_childItems.append(child);
}

int TreeItem::childCount() const
{
    return this->m_childItems.count();
}

TreeItem *TreeItem::parent() const
{
    return this->m_parentItem;
}

void TreeItem::setParent(TreeItem *parent)
{
    this->m_parentItem = parent;
}

QVariant TreeItem::data(int column) const
{
    return this->m_itemData.at(column);
}

int TreeItem::columnCount() const
{
    return this->m_itemData.count();
}

int TreeItem::row() const
{
    if(!m_parentItem)
        return 0;
    return this->m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));
}
