#include "myclienthandler.h"
#include "myservicelinkrequest.h"
#include "servicereportnotificationrecordlist.h"
#include "myservicereportnotificationlist.h"
#include "readtask.h"
#include "connectionpool.h"
#include "dlt698lendomain.h"
#include <QDebug>

MyClientHandler::MyClientHandler()
{
    this->pool = shared_ptr<ThreadPool>(new ThreadPool());

    new ServiceReportNotificationRecordList();
    new MyServiceReportNotificationList();
    new MyServiceLinkRequest();

//    ConnectionPool::getInstance().setPassword("123qWe,.");
    ConnectionPool::getInstance().createConnection(10);
}

MyClientHandler::MyClientHandler(const shared_ptr<ThreadPool> pool)
{
    this->pool = pool;
}

ClientHandler *MyClientHandler::clone()
{
    return new MyClientHandler(this->pool);
}

void MyClientHandler::read(EpollEvent *event)
{
    this->buffer.insert(this->buffer.end(), event->getBuffer(), event->getBuffer() + event->getSize());

    while(!this->buffer.empty())
    {
        if(this->buffer.front() != 0x68)
        {
            this->buffer.pop_front();
            continue;
        }
        if(this->buffer.size() < 3)
        {
            break;
        }

        {
            Dlt698LenDomain len;
            vector<BYTE> res{this->buffer.at(1), this->buffer.at(2)};
            size_t pos = 0;
            len.decode(res, pos);
            if(len.getLen() > MAX_APDU_SIZE)
            {
                this->buffer.pop_front();
                continue;
            }
            if(len.getLen() + 2 > this->buffer.size())
                break;
        }

        if(this->buffer.at(this->buffer.at(1) + 1) != 0x16)
        {
            this->buffer.pop_front();
            continue;
        }

        EpollEvent *e = new EpollEvent(event->getSocket().getSockfd());
        char *buff = e->getBuffer();
        size_t l = this->buffer.at(1) + 2;
        for(size_t i = 0;i < l && i < BUFFER_SIZE;i ++)
        {
            buff[i] = this->buffer.front();
            buffer.pop_front();
        }
        e->setSize(l);

        ReadTask *task = new ReadTask(e);
        this->pool->enqueue(task);
    }

    delete event;
}
