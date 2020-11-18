#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QMap>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

};

#endif
