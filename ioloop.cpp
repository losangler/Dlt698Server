#include "ioloop.h"
#include <QDebug>

using namespace Dlt698;

IOLoop::IOLoop()
{
    this->epoller = new Epoller(10, 1000);
    this->prototypeHandler = new ClientHandler();
}

std::unordered_map<int, Handler *> IOLoop::getHandlers() const
{
    return handlers_;
}

Epoller *IOLoop::getEpoller() const
{
    return epoller;
}

ClientHandler *IOLoop::getPrototypeHandler() const
{
    return prototypeHandler->clone();
}

void IOLoop::setPrototypeHandler(ClientHandler *value)
{
    prototypeHandler = value;
}

bool IOLoop::isStop() const
{
    return this->stop;
}

void IOLoop::Stop()
{
    this->stop = true;
}

IOLoop *IOLoop::Instance()
{
    static IOLoop instance;
    return &instance;
}

IOLoop::~IOLoop()
{
    for(auto &k : handlers_)
    {
        delete k.second;
    }
}

void IOLoop::start()
{
    epoll_event events[this->epoller->getMaxEvents()];
    while(!stop)
    {
        int nfds = this->epoller->waitSockets(events);
        for(int i = 0;i < nfds; ++i)
        {
            int fd = events[i].data.fd;
            Handler* handler = handlers_[fd];
            if(handler == nullptr)
            {
                qDebug() << "Handler is not exisit,fd =" << fd << "i =" << i;
                exit(1);
            }
            handler->handle(events[i]);
        }
    }
}

void IOLoop::addHandler(int fd, Handler *handler, unsigned int events)
{
    handlers_[fd] = handler;
    if(!this->epoller->addSocket(fd, events))
    {
        qDebug() << "Failed to insert handler to epoll";
    }
    else qDebug() << "Successed to insert handler,fd = " << fd;
}

void IOLoop::modifyHandler(int fd, unsigned int events)
{
    if(!this->epoller->modifySocket(fd, events))
    {
        qDebug() << "Failed to modify handler from epoll";
    }
    else qDebug() << "Successed to modify handler,fd =" << fd;
}

void IOLoop::removeHandler(int fd)
{
    Handler* handler = handlers_.at(fd);
    handlers_.erase(fd);
    delete handler;

    if(!this->epoller->removeSocket(fd))
    {
        qDebug() << "Failed to delete handler from epoll";
    }
    else qDebug() << "Successed to delete handler,fd =" << fd;
}
