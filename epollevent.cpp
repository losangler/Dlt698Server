#include "epollevent.h"

using namespace Dlt698;

EpollEvent::EpollEvent(int fd)
{
    this->buffer = new char[BUFFER_SIZE];
    this->size = 0;
    this->socket.setSockfd(fd);
}

EpollEvent::~EpollEvent()
{
    delete[] this->buffer;
}

size_t EpollEvent::getSize() const
{
    return size;
}

void EpollEvent::setSize(const size_t &value)
{
    size = value;
}

char *EpollEvent::getBuffer() const
{
    return buffer;
}

void EpollEvent::setBuffer(char *value)
{
    buffer = value;
}

TcpSocket EpollEvent::getSocket() const
{
    return socket;
}

void EpollEvent::setSocket(const TcpSocket &value)
{
    socket = value;
}

size_t EpollEvent::read()
{
    this->size = this->socket.read(this->buffer, BUFFER_SIZE);
    return this->size;
}

size_t EpollEvent::write()
{
    return this->socket.write(this->buffer, this->size);
}
