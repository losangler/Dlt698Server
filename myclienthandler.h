#ifndef MYCLIENTHANDLER_H
#define MYCLIENTHANDLER_H

#include "clienthandler.h"
#include "dlt698callservice.h"
#include "threadpool.h"
#include "deque"
#include <memory>

#define MAX_APDU_SIZE 1024

using namespace Dlt698;

class MyClientHandler : public ClientHandler
{
public:
    MyClientHandler();

    MyClientHandler(const shared_ptr<ThreadPool> pool);

    virtual ClientHandler *clone() override;

protected:
    virtual void read(EpollEvent *event) override;

private:
    shared_ptr<ThreadPool> pool;

    deque<BYTE> buffer;
};

#endif // MYCLIENTHANDLER_H
