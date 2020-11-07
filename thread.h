#ifndef THREAD_H
#define THREAD_H

#include <thread>
#include <atomic>

namespace Dlt698 {

class Thread
{
public:
    Thread();

    virtual ~Thread();

    void start();

    std::thread::id getId();

    void interrupt();

    bool isTnterrupted();

    void join();

    virtual void run();


private:
    std::atomic_bool isInterript;
    std::thread th;
};

}

#endif // THREAD_H
