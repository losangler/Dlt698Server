#include "thread.h"

using namespace Dlt698;
using namespace std;

Thread::Thread()
{
    this->isInterript = false;
}

Thread::~Thread()
{
    if(!this->isTnterrupted())
    {
        this->interrupt();
    }

    if(this->th.joinable())
    {
        this->th.join();
    }
}

void Thread::start()
{
    thread thr(bind(&Thread::run, this));
    this->th = move(thr);
}

thread::id Thread::getId()
{
    return this->th.get_id();
}

void Thread::interrupt()
{
    this->isInterript = true;
}

bool Thread::isTnterrupted()
{
    return this->isInterript;
}

void Thread::join()
{
    this->th.join();
}

void Thread::run()
{

}
