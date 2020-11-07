#include "terminalservice.h"
#include "connectionpool.h"
#include <QSqlQuery>

using namespace Dlt698;
using namespace std;

TerminalService::TerminalService()
{

}

bool Dlt698::TerminalService::save(Dlt698::TerminalEntity &entity)
{
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO terminal (addr, status) "
                  "VALUES (:addr, :status)");
    query.bindValue(":addr", entity.getAddr().data());
    query.bindValue(":status", entity.getStatus());
    if(!this->queryExec(query, "insert database error:"))
    {
        return false;
    }
    return true;
}

TerminalEntity* TerminalService::getOne(int id)
{
    QSqlQuery query(this->db);
    query.prepare("SELECT * FROM terminal where id = :id");
    query.bindValue(":id", id);
    if(!this->queryExec(query, "select by id error:"))
    {
        return nullptr;
    }
    return this->getOne(query);
}

TerminalEntity* TerminalService::getOne(const string &addr)
{
    QSqlQuery query(this->db);
    query.prepare("SELECT * FROM terminal where addr = :addr");
    query.bindValue(":addr", addr.data());
    if(!this->queryExec(query, "select by addr error:"))
    {
        return nullptr;
    }
    return this->getOne(query);
}

TerminalEntity *TerminalService::getOne(QSqlQuery &query)
{
    TerminalEntity *res = new TerminalEntity();
    QSqlRecord rec = query.record();
    int idCol = rec.indexOf("id");
    int addrCol = rec.indexOf("addr");
    int statusCol = rec.indexOf("status");
    if(query.first())
    {
        res->setId(query.value(idCol).toInt());
        res->setAddr(query.value(addrCol).toString().toStdString());
        res->setStatus(query.value(statusCol).toInt());
    }
    else return nullptr;

    return res;
}

std::list<TerminalEntity*> TerminalService::getAll()
{
    list<TerminalEntity*> *res = new list<TerminalEntity*>();

    QSqlQuery query(this->db);
    query.prepare("SELECT * FROM terminal");
    if(!query.exec())
    {
        qDebug() << "select * from terminal error:" << this->db.lastError().text();
        return *res;
    }
    while(query.next())
    {
        res->push_back(this->getOne(query));
    }

    return *res;
}
