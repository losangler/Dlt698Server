#ifndef EPOLLER_H
#define EPOLLER_H

#include "epoller_global.h"
#include <sys/epoll.h>

namespace Dlt698 {

class EPOLLERSHARED_EXPORT Epoller
{

public:
    Epoller(int max = 10, int time = 1000);

    bool addSocket(int sockfd, unsigned int events);

    bool removeSocket(int sockfd);

    bool modifySocket(int sockfd, unsigned int events);

    int waitSockets(epoll_event *events);

    int getEpollFd() const;
    void setEpollFd(int value);

    int getMaxEvents() const;
    void setMaxEvents(int value);

    int getTimeOut() const;
    void setTimeOut(int value);

private:
    int epollFd;
    int maxEvents;
    int timeOut;
};


}


#endif // EPOLLER_H
