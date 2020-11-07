#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "handler.h"
#include "epollevent.h"

namespace Dlt698 {

class ClientHandler : public Handler
{
public:
    ClientHandler();

    virtual ClientHandler* clone();
    // Handler interface
public:
    virtual int handle(epoll_event e) override;

protected:
    virtual void read(EpollEvent *event);

    virtual void write(EpollEvent *event);

    virtual void error(EpollEvent *event);

};

}

#endif // CLIENTHANDLER_H
