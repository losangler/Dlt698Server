#include "dltstringbuffer.h"

DltStringBuffer::DltStringBuffer()
{

}

void DltStringBuffer::append(const string key, const string value)
{
    this->keys.push_back(key);
    this->values.push_back(value);
}

void DltStringBuffer::append(const string key, const int value)
{
    this->append(key, to_string(value));
}

void DltStringBuffer::append(const string key, const vector<shared_ptr<DltObject> > &value)
{
    string str = "[";
    for(size_t i = 0;i < value.size();i ++)
    {
        str.append(value[i]->toString());
        if(i != value.size() - 1)
            str.append(", ");
    }
    str.append("]");
    this->append(key, str);
}


string DltStringBuffer::toString()
{
    string str = "{";
    for(size_t i = 0;i < keys.size();i ++)
    {
        str.append(keys.at(i) + " = " + values.at(i));
        if(i != keys.size() - 1)
            str.append(", ");
    }
    str.append("}");
    return str;
}

