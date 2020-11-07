#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#define MAX_PENDING 1024
#include "handler.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

namespace Dlt698 {

class ServerHandler : public Handler
{
public:
    ServerHandler(const uint16_t port = 0);

    bool listenStart();

    int getFd() const;

    sockaddr_in getAddr() const;

    void setAddr(const sockaddr_in &value);

    // Handler interface
public:
    virtual int handle(epoll_event e) override;

private:
    void setNonBlocking(int fd);

    void setReuseAddr(int fd);

private:
    int fd;
    sockaddr_in addr;
};

}

#endif // SERVERHANDLER_H
