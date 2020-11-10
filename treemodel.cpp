#include "treemodel.h"

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    m_rootItem = new TreeItem;
    QList<QVariant> list;
    list.append("属性对象");
    auto item = new TreeItem(list, m_rootItem);
    m_rootItem->appendChild(item);

    QList<QVariant> BJ_List;
    BJ_List.append("BeiJing");
    auto BJ_Item = new TreeItem(BJ_List, item);
    item->appendChild(BJ_Item);

    QList<QVariant> ShX_List;
    ShX_List.append("ShannXi");
    QList<QVariant> XiAn_List;
    XiAn_List.append("XiAn");
    QList<QVariant> XiAn_GaoXin_List;
    XiAn_GaoXin_List.append("GaoXin");
    auto ShX_Item = new TreeItem(ShX_List, item);
    auto XA_Item = new TreeItem(XiAn_List, ShX_Item);
    auto XA_GX_Item = new TreeItem(XiAn_GaoXin_List, XA_Item);

    item->appendChild(ShX_Item);
    ShX_Item->appendChild(XA_Item);
    XA_Item->appendChild(XA_GX_Item);


    QList<QVariant> GuangDong_List;
    GuangDong_List.append("GuangDong");
    GuangDong_List.append("GD");
    QList<QVariant> DongGuan;
    DongGuan.append("DongGuan");
    DongGuan.append("DG");
    auto GuangDong_Item = new TreeItem(GuangDong_List, item);
    auto DongGuan_Item = new TreeItem(DongGuan, GuangDong_Item);
    item->appendChild(GuangDong_Item);
    GuangDong_Item->appendChild(DongGuan_Item);

    QList<QVariant> ShangHai;
    ShangHai.append("ShangHai");
    ShangHai.append("ShH");
    auto ShangHai_Item = new TreeItem(ShangHai, item);
    item->appendChild(ShangHai_Item);

}

TreeModel::~TreeModel()
{
    delete m_rootItem;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }

    TreeItem *parentItem;
    if (!parent.isValid())
    {
        parentItem = m_rootItem;
    }
    else
    {
        parentItem = static_cast<TreeItem*>(parent.internalPointer());
    }

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
    {
        return createIndex(row, column, childItem);
    }
    else
    {
        return QModelIndex();
    }
    // FIXME: Implement me!
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return QModelIndex();
    }

    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());
    if(item == m_rootItem)
    {
        return QModelIndex();
    }

    return createIndex(item->parent()->row(), 0, item->parent());
    // FIXME: Implement me!
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if(parent.column() > 0)
        return 0;

    if(!parent.isValid())
        return m_rootItem->childCount();

    return static_cast<TreeItem*>(parent.internalPointer())->childCount();
    // FIXME: Implement me!
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 2;

    return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    // FIXME: Implement me!
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case NAME:
        return static_cast<TreeItem*>(index.internalPointer())->data(0);
        break;
    case SIMPLIFY:
        return static_cast<TreeItem*>(index.internalPointer())->data(1);
        break;
    default:
        break;
    }

    // FIXME: Implement me!
    return QVariant();
}

QHash<int, QByteArray> TreeModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[NAME] = "name";
    names[SIMPLIFY] = "simplify";
    return names;
}
