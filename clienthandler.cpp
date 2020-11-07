#include "clienthandler.h"
#include "ioloop.h"
#include <QDebug>
#include <arpa/inet.h>

using namespace Dlt698;

ClientHandler::ClientHandler()
{

}

ClientHandler *ClientHandler::clone()
{
    return new ClientHandler();
}

int ClientHandler::handle(epoll_event e)
{
    int fd = e.data.fd;
    EpollEvent *event = new EpollEvent(fd);

    if(e.events & EPOLLHUP)
    {
        IOLoop::Instance()->removeHandler(fd);
        return -1;
    }
    else if(e.events & EPOLLERR)
    {
        qDebug() << "Error";
        this->error(event);
    }
    else if(e.events & EPOLLOUT)
    {
        qDebug() << "Write";
        this->write(event);
    }
    else if(e.events & EPOLLIN)
    {
        qDebug() << "Read";
        int received = event->read();
        if(received < 0)
        {
            qDebug() << "Error reading from socket";
        }
        else if(received > 0)
        {
            this->read(event);
        }

        if(received <= 0)
        {
            qDebug() << "Disconnect fd = " << fd;
            IOLoop::Instance()->removeHandler(fd);
        }
    }

    return 0;
}

void ClientHandler::read(EpollEvent *event)
{
    delete event;
}

void ClientHandler::write(EpollEvent *event)
{
    delete event;
}

void ClientHandler::error(EpollEvent *event)
{
    delete event;
}
