#include "dlt698data.h"
#include <QDebug>

Dlt698Data::Dlt698Data(eDataType type) : eTyp(type)
{
    this->byDat = vector<BYTE>();
    this->childs = vector<shared_ptr<Dlt698Data> >();
}

void Dlt698Data::decode(const vector<BYTE> &res, size_t &pos)
{
    if(pos >= res.size())
        return;
    this->eTyp = (eDataType)res.at(pos ++);
    switch (this->eTyp) {
    case t_null:
        break;
    case t_structure:
    case t_array:
    {
        BYTE num = res.at(pos ++);
        for(int i = 0;i < num;i ++)
        {
            shared_ptr<Dlt698Data> child(new Dlt698Data());
            child->decode(res, pos);
            this->childs.push_back(child);
        }
    }
        break;
    case t_bool:
        this->vectorCopy(res, pos, this->byDat, sizeof(bool_c));
        break;
    case t_utf8_string:

    case t_visible_string:

    case t_octet_string:

    case t_bit_string:
    {
        BYTE num = res.at(pos ++);
        this->vectorCopy(res, pos, this->byDat, sizeof(bit_string_c) * num);
    }
        break;
    case t_double_long:
        this->vectorCopy(res, pos, this->byDat, sizeof(double_long_c));
        break;
    case t_double_long_unsigned:
        this->vectorCopy(res, pos, this->byDat, sizeof(double_long_unsigned_c));
        break;
    case t_bcd:

        break;
    case t_integer:
        this->vectorCopy(res, pos, this->byDat, sizeof(integer_c));
        break;
    case t_long:
        this->vectorCopy(res, pos, this->byDat, sizeof(long_c));
        break;
    case t_unsigned:
        this->vectorCopy(res, pos, this->byDat, sizeof(unsigned_c));
        break;
    case t_long_unsigned:
        this->vectorCopy(res, pos, this->byDat, sizeof(t_long64_unsigned));
        break;
    case t_long64:
        this->vectorCopy(res, pos, this->byDat, sizeof(long64_c));
        break;
    case t_long64_unsigned:
        this->vectorCopy(res, pos, this->byDat, sizeof(long64_unsigned_c));
        break;
    case t_date_time:
        this->vectorCopy(res, pos, this->byDat, 10);
        break;
    case t_datetime_s:
        this->vectorCopy(res, pos, this->byDat, 7);
        break;
    case t_enum:
        this->vectorCopy(res, pos, this->byDat, sizeof(BYTE));
        break;
    default:
        break;
    }
}

void Dlt698Data::encode(vector<BYTE> &res)
{
    res.push_back((BYTE)this->eTyp);

    size_t pos = 0;
    switch (this->eTyp) {
    case t_null:
        break;
    case t_structure:
    case t_array:
    {
        int num = this->childs.size();
        res.push_back(num);
        for(auto &k : this->childs)
        {
            k->encode(res);
        }
    }
        break;
    case t_bool:
        this->vectorCopy(this->byDat, pos, res, sizeof(bool_c));
        break;
    case t_utf8_string:

    case t_visible_string:

    case t_octet_string:

    case t_bit_string:
    {
        BYTE num = res.at(pos ++);
        this->baseEncode(res, &num, sizeof(BYTE));
        this->vectorCopy(this->byDat, pos, res, sizeof(bit_string_c) * num);
    }
        break;
    case t_double_long:
        this->vectorCopy(this->byDat, pos, res, sizeof(double_long_c));
        break;
    case t_double_long_unsigned:
        this->vectorCopy(this->byDat, pos, res, sizeof(double_long_unsigned_c));
        break;
    case t_bcd:

        break;
    case t_integer:
        this->vectorCopy(this->byDat, pos, res, sizeof(integer_c));
        break;
    case t_long:
        this->vectorCopy(this->byDat, pos, res, sizeof(long_c));
        break;
    case t_unsigned:
        this->vectorCopy(this->byDat, pos, res, sizeof(unsigned_c));
        break;
    case t_long_unsigned:
        this->vectorCopy(this->byDat, pos, res, sizeof(t_long64_unsigned));
        break;
    case t_long64:
        this->vectorCopy(this->byDat, pos, res, sizeof(long64_c));
        break;
    case t_long64_unsigned:
        this->vectorCopy(this->byDat, pos, res, sizeof(long64_unsigned_c));
        break;
    case t_date_time:
        this->vectorCopy(this->byDat, pos, res, 10);
    case t_datetime_s:
        this->vectorCopy(this->byDat, pos, res, 7);
        break;
    case t_enum:
        this->vectorCopy(this->byDat, pos, res, sizeof(BYTE));
        break;
    default:
        break;
    }
}

eDataType Dlt698Data::getETyp() const
{
    return eTyp;
}

void Dlt698Data::setETyp(const eDataType &value)
{
    eTyp = value;
}

vector<BYTE> Dlt698Data::getByDat() const
{
    return byDat;
}

void Dlt698Data::getByDat(void *dat, size_t &pos, size_t size)
{
    if(this->byDat.size() <= 0)
        return;
    this->baseDecode(this->byDat, pos, dat, size);
}

void Dlt698Data::setByDat(const vector<BYTE> &value)
{
    byDat = value;
}

void Dlt698Data::setByDat(const void *dat, size_t size)
{
    this->byDat.swap(*(new vector<BYTE>()));
    this->baseEncode(this->byDat, dat, size);
}

void Dlt698Data::addChild(shared_ptr<Dlt698Data> child)
{
    this->childs.push_back(child);
}

shared_ptr<Dlt698Data> Dlt698Data::getChild(int id) const
{
    return this->childs.at(id);
}

void Dlt698Data::vectorCopy(const vector<BYTE> &res, size_t &pos, vector<BYTE> &aim, size_t size)
{
    aim.resize(aim.size() + size, 0);
    this->baseDecode(res, pos, &aim[aim.size() - size], size);
}

size_t Dlt698Data::getChildsSize() const
{
    return this->childs.size();
}

string Dlt698Data::toString()
{
    DltStringBuffer buffer;
    buffer.append("DATA类型", this->eTyp);
    if(this->byDat.size() <= 0)
        buffer.append("DATA数据", "");
    else buffer.append("DATA数据", this->byteToString(&this->byDat[0], this->byDat.size()));

    vector<shared_ptr<DltObject> > objects(this->childs.begin(), this->childs.end());
    buffer.append("CHILDS", objects);
    return buffer.toString();
}
