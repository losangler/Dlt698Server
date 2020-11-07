#include "epoller.h"
#include <QDebug>

using namespace Dlt698;

Epoller::Epoller(int max, int time)
    : maxEvents(max), timeOut(time)
{
    this->epollFd = epoll_create1(0);
    if(this->epollFd < 0)
    {
        qDebug() << "Failed to create epoll";
        exit(1);
    }
}

bool Epoller::addSocket(int sockfd, unsigned int events)
{
    epoll_event e;
    e.data.fd = sockfd;
    e.events = events;

    return epoll_ctl(this->epollFd, EPOLL_CTL_ADD, sockfd, &e) >= 0;
}

bool Epoller::removeSocket(int sockfd)
{
    return epoll_ctl(this->epollFd, EPOLL_CTL_DEL, sockfd, NULL) >= 0;
}

bool Epoller::modifySocket(int sockfd, unsigned int events)
{
    epoll_event e;
    e.events = events;

    return epoll_ctl(this->epollFd, EPOLL_CTL_MOD, sockfd, &e) >= 0;
}

int Epoller::waitSockets(epoll_event *events)
{
    return epoll_wait(this->epollFd, events, this->maxEvents, this->timeOut);
}

int Epoller::getEpollFd() const
{
    return epollFd;
}

void Epoller::setEpollFd(int value)
{
    epollFd = value;
}

int Epoller::getMaxEvents() const
{
    return maxEvents;
}

void Epoller::setMaxEvents(int value)
{
    maxEvents = value;
}

int Epoller::getTimeOut() const
{
    return timeOut;
}

void Epoller::setTimeOut(int value)
{
    timeOut = value;
}
