#ifndef ANIMALMODEL_H
#define ANIMALMODEL_H

#include <QAbstractListModel>

class Animal
{
public:
    Animal(const QString &type, const QString &size);

    QString type() const;
    QString size() const;

private:
    QString m_type;
    QString m_size;
};

class AnimalModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum AnimaRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    explicit AnimalModel(QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addAnimal(const Animal &animal);

    Q_INVOKABLE int getValue() const;
protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Animal> m_animals;
};

#endif // ANIMALMODEL_H
