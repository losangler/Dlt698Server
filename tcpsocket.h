#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>

namespace Dlt698 {

class TcpSocket
{
public:
    TcpSocket(int fd = 0);

    bool connectToHost(const std::string &hostName, std::uint16_t port);

    size_t read(void *buf, size_t n);

    size_t write(const void *buf, size_t n);

    int getSockfd() const;

    void setSockfd(int value);

private:
    int sockfd;
};

}

#endif // TCPSOCKET_H
