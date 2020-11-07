#ifndef THREADFOREPOLL_H
#define THREADFOREPOLL_H

#include <QObject>
#include "thread.h"

using namespace Dlt698;

class ThreadForEpoll : public Thread, public QObject
{
public:
    ThreadForEpoll(QObject* par = nullptr);

    ~ThreadForEpoll();
    // QThread interface
protected:
    virtual void run() override;
};

#endif // THREADFOREPOLL_H
