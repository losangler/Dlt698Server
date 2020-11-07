#include "tcpsocket.h"
#include <string.h>
#include <QDebug>

using namespace Dlt698;
using namespace std;

TcpSocket::TcpSocket(int fd)
    : sockfd(fd)
{

}

bool TcpSocket::connectToHost(const string &hostName, uint16_t port)
{
    sockaddr_in remoteAddr;
    memset(&remoteAddr, 0, sizeof(remoteAddr));
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_addr.s_addr = inet_addr(hostName.c_str());
    remoteAddr.sin_port = htons(port);
    if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        qDebug() << "Failed to get socket";
        return false;
    }

    if(connect(sockfd, (sockaddr*)&remoteAddr, sizeof(remoteAddr)) < 0)
    {
        qDebug() << "Failed to connect";
        return false;
    }

    return true;
}

size_t TcpSocket::read(void *buf, size_t n)
{
    return recv(sockfd, buf, n, 0);
}

size_t TcpSocket::write(const void *buf, size_t n)
{
    return send(sockfd, buf, n, 0);
}

int TcpSocket::getSockfd() const
{
    return sockfd;
}

void TcpSocket::setSockfd(int value)
{
    sockfd = value;
}
