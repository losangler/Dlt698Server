#include "serverhandler.h"
#include "ioloop.h"
#include <string.h>
#include <QDebug>

using namespace Dlt698;

Dlt698::ServerHandler::ServerHandler(const uint16_t port)
{
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
}

bool ServerHandler::listenStart()
{
    if((fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        qDebug() << "Failed to create server socket";
        return false;
    }

    this->setReuseAddr(fd);

    if(bind(fd, (sockaddr*)&addr, sizeof(addr)) < 0)
    {
        qDebug() << "Failed to bind server socket";
        return false;
    }

    if(listen(fd, MAX_PENDING) < 0)
    {
        qDebug() << "Failed to listen on server socket";
        return false;
    }

    this->setNonBlocking(fd);
    return true;
}

int ServerHandler::handle(epoll_event e)
{
    int fd = e.data.fd;
    sockaddr_in clientAddr;
    socklen_t caLen = sizeof(clientAddr);

    int client = accept(fd, (sockaddr*)&clientAddr, &caLen);

    if(client < 0)
    {
        qDebug() << "Error accepting connection";
        return -1;
    }

    qDebug() << "accept connected: " << inet_ntoa(clientAddr.sin_addr) << "fd = " << client;

    Handler* clientHandler = IOLoop::Instance()->getPrototypeHandler();
    IOLoop::Instance()->addHandler(client, clientHandler, EPOLLIN | EPOLLHUP | EPOLLERR);
    return 0;
}

void ServerHandler::setNonBlocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

void ServerHandler::setReuseAddr(int fd)
{
    int on = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
}

sockaddr_in ServerHandler::getAddr() const
{
    return addr;
}

void ServerHandler::setAddr(const sockaddr_in &value)
{
    addr = value;
}

int ServerHandler::getFd() const
{
    return fd;
}
