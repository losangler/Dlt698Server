#ifndef READTASK_H
#define READTASK_H

#include "epollevent.h"
#include "dlt698callservice.h"
#include "task.h"

using namespace Dlt698;

class ReadTask : public Task
{
public:
    ReadTask(EpollEvent *e);

    ~ReadTask();
    // Task interface
public:
    virtual void doTask() override;

private:
    EpollEvent *event;

    shared_ptr<Dlt698CallService> service;
};


#endif // READTASK_H
