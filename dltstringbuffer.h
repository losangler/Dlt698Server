#ifndef DLTSTRINGBUFFER_H
#define DLTSTRINGBUFFER_H

#include "dltobject.h"
#include <memory>
#include <vector>

using namespace std;

class DltStringBuffer : public DltObject
{
public:
    DltStringBuffer();

    void append(const string key,const string value);

    void append(const string key,const int value);

    void append(const string key,const vector<shared_ptr<DltObject> > &value);

    string toString();

private:
    vector<string> keys;
    vector<string> values;
};

#endif // DLTSTRINGBUFFER_H
