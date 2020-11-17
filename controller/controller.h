#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
public:
   explicit Controller(QObject *parent = nullptr);
};

#endif
