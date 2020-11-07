#ifndef EPOLLEVENT_H
#define EPOLLEVENT_H

#define BUFFER_SIZE 1024

#include <sys/epoll.h>
#include "tcpsocket.h"

namespace Dlt698 {

class EpollEvent
{
public:
    EpollEvent(int fd = 0);

    ~EpollEvent();

    size_t getSize() const;
    void setSize(const size_t &value);

    char *getBuffer() const;
    void setBuffer(char *value);

    TcpSocket getSocket() const;
    void setSocket(const TcpSocket &value);

    size_t read();
    size_t write();
private:
    TcpSocket socket;
    char* buffer;
    size_t size;
};

}

#endif // EPOLLEVENT_H
