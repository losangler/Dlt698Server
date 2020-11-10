#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include "treeitem.h"

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

    enum ItemRoles {
        NAME = Qt::UserRole + 1,
        SIMPLIFY
    };

public:
    explicit TreeModel(QObject *parent = 0);
    ~TreeModel();

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const;
private:
    TreeItem *m_rootItem;
};

#endif // TREEMODEL_H
