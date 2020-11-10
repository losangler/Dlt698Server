#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>

class TreeItem
{
public:
    TreeItem();
    TreeItem(const QList<QVariant> &data, TreeItem* parent);
    ~TreeItem();

    TreeItem* child(int row);
    void appendChild(TreeItem *child);
    int childCount() const;

    TreeItem* parent() const;
    void setParent(TreeItem* parent);

    QVariant data(int column) const;
    int columnCount() const;
    int row() const;

private:
    TreeItem *m_parentItem;
    QList<TreeItem*> m_childItems;
    QList<QVariant> m_itemData;
};

#endif // TREEITEM_H
