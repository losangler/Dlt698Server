#ifndef IOLOOP_H
#define IOLOOP_H

#include "handler.h"
#include "epoller.h"
#include "clienthandler.h"
#include <unordered_map>

namespace Dlt698 {

class IOLoop
{
public:
    static IOLoop *Instance();

    ~IOLoop();

    void start();

    void addHandler(int fd, Handler* handler, unsigned int events);

    void modifyHandler(int fd, unsigned int events);

    void removeHandler(int fd);

    ClientHandler *getPrototypeHandler() const;
    void setPrototypeHandler(ClientHandler *value);

    bool isStop() const;
    void Stop();

    Epoller *getEpoller() const;
    std::unordered_map<int, Handler *> getHandlers() const;

private:
    IOLoop();

private:
    Epoller *epoller;
    ClientHandler* prototypeHandler;
    std::unordered_map<int, Handler*> handlers_;
    bool stop = false;
};

}

#endif // IOLOOP_H
