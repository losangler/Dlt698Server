#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "thread.h"
#include "task.h"

namespace Dlt698 {

class ThreadPool
{
public:
    ThreadPool(size_t threads = 10);

    ~ThreadPool();

    void enqueue(Task *task);

private:
    std::vector<Thread*> workers;

    std::queue<Task*> tasks;

    std::mutex queue_mutex;

    std::condition_variable condition;

    bool stop;

    friend class ThreadP;
};


class ThreadP : public Thread
{
public:
    ThreadP(ThreadPool *po);

    // Thread interface
public:
    virtual void run() override;

private:
    ThreadPool *pool;
};

}

#endif // THREADPOOL_H
