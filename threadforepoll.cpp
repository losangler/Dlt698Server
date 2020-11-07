#include "threadforepoll.h"
#include "serverhandler.h"
#include "myclienthandler.h"
#include "ioloop.h"

using namespace Dlt698;


ThreadForEpoll::ThreadForEpoll(QObject *par)
    : QObject(par)
{

}

ThreadForEpoll::~ThreadForEpoll()
{
    IOLoop::Instance()->Stop();
}

void ThreadForEpoll::run()
{
    ServerHandler *handler = new ServerHandler(8888);
    handler->listenStart();

    MyClientHandler *client = new MyClientHandler();
    IOLoop::Instance()->addHandler(handler->getFd(), handler, EPOLLIN);
    IOLoop::Instance()->setPrototypeHandler(client);
    IOLoop::Instance()->start();
}
