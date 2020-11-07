#ifndef DLT698OAD_H
#define DLT698OAD_H

#include "dlt698proctol.h"

class Dlt698Oad : public Dlt698Proctol
{
public:
    Dlt698Oad();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;
    string toString() override;

    OI_c getOi() const;
    void setOi(const OI_c &value);

    unsigned_c getAttrId() const;
    void setAttrId(const unsigned_c &value);

    unsigned_c getAttrFea() const;
    void setAttrFea(const unsigned_c &value);

    unsigned_c getElemIdx() const;
    void setElemIdx(const unsigned_c &value);

private:
    OI_c oi;//对象标识

    struct _tOAD
    {
        unsigned_c attrId:5;//属性标识
        unsigned_c attrFea:3;//属性特征
        unsigned_c elemIdx;//属性内元素索引

    }OAD;
};

#endif // DLT698OAD_H
