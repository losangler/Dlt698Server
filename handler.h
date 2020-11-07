#ifndef HANDLER_H
#define HANDLER_H

#include <sys/epoll.h>

namespace Dlt698 {

class Handler
{
public:
    Handler();

    virtual ~Handler();
    virtual int handle(epoll_event e);
};


}

#endif // HANDLER_H
