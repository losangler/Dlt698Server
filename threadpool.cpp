#include "threadpool.h"
#include <QDebug>

using namespace Dlt698;
using namespace std;

ThreadPool::ThreadPool(size_t threads)
{
    for(size_t i = 0;i < threads;i ++)
    {
        workers.push_back(new ThreadP(this));
        workers.back()->start();
    }
}

ThreadPool::~ThreadPool()
{
    {
        unique_lock<mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(auto &worker : workers)
    {
        delete worker;
    }
}

void ThreadPool::enqueue(Task *task)
{
    {
        unique_lock<mutex> lock(queue_mutex);

        if(stop)
            throw runtime_error("enqueue on stopped ThreadPool");

        tasks.push(task);
    }
    condition.notify_one();
}

ThreadP::ThreadP(ThreadPool *po)
    : pool(po)
{

}

void ThreadP::run()
{
    while(true)
    {
        Task* task;

        {
            unique_lock<mutex> lock(this->pool->queue_mutex);
            this->pool->condition.wait(lock,
                                       [this]{
                return this->pool->stop || !this->pool->tasks.empty();
            });
            if(this->pool->stop && this->pool->tasks.empty())
                return;
            task = move(this->pool->tasks.front());
            this->pool->tasks.pop();
        }

        try{
            task->doTask();
            delete task;
        }
        catch(std::exception& e)
        {
            qDebug() << e.what();
        }
    }
}
