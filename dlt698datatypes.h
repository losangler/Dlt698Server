#ifndef DLT698DATATYPES_H
#define DLT698DATATYPES_H

#pragma once

#include <bits/wordsize.h>

typedef bool            BOOLEAN;
typedef unsigned char   BYTE;
typedef int             INT32;
typedef unsigned int    UINT32;
typedef char            CHAR;
typedef short           SHORT;
typedef unsigned short  WORD;

#if __WORDSIZE == 64
typedef long int                LONG64;
typedef unsigned long int       ULONG64;
#else
__extension__
typedef long long int           LONG64;
typedef unsigned long long int  ULONG64;
#endif

/*typedef NULL        null_c;*/
typedef BOOLEAN		bool_c;
typedef BYTE		bit_string_c/*[SEQUENCENUM]*/;
typedef INT32		double_long_c;
typedef UINT32		double_long_unsigned_c;
typedef BYTE		Octet_string_c/*[SEQUENCENUM]*/;
typedef CHAR		visible_string_c/*[SEQUENCENUM]*/;
typedef BYTE		UTF8_string_c/*[SEQUENCENUM]*/;
typedef CHAR		integer_c;
typedef SHORT		long_c;
typedef BYTE		unsigned_c;
typedef WORD		long_unsigned_c;
typedef LONG64		long64_c;
typedef ULONG64		long64_unsigned_c;
//typedef enum		enum_c;
typedef float		float32_c ;
typedef double		float64_c ;

typedef long_unsigned_c OI_c;

typedef enum _eDataType
{
    t_null = 0,//空
    t_array = 1,//SEQUENCE OF Data 见6.3.3.1　）
    t_structure = 2,//SEQUENCE OF Data 见6.3.3.1　）
    t_bool = 3,//01-true;00-false
    t_bit_string = 4,//比特位串（BIT STRING）
    t_double_long = 5,//32比特位整数（Integer32）-2p31…2p31-1
    t_double_long_unsigned = 6,//32比特位正整数 0…2p32-1
    t_octet_string = 9,//8比特位位组（字节）串（OCTET STRING）
    t_visible_string = 10,//ASCII字符串（VisibleString）
    t_utf8_string = 12,//UTF-8编码的字符串
    t_bcd = 13,//
    t_integer = 15,//8比特位整数（integer） -128…127
    t_long = 16,//16比特位整数（long） -32768…32767
    t_unsigned = 17,//8比特位正整数（Unsigned8） 0…255
    t_long_unsigned = 18,//16比特位正整数（Unsigned16）0…65535
    t_long64 = 20,//64比特位整数（Integer64）-2p63…2p63-1
    t_long64_unsigned = 21,//64比特位正整数（Unsigned64）0…2p64-1
    t_enum = 22,//0…255
    t_float32 = 23,//octet-string（SIZE（4））
    t_float64 = 24,//octet-string（SIZE（8））
    t_date_time = 25,//octet-string（SIZE（10））
    t_date = 26,//octet-string（SIZE（5））
    t_time = 27,//octet-string（SIZE（3））
    t_datetime_s = 28,//octet-string（SIZE（7））
    t_datetimebcd_h = 29,//
    t_datetimebcd_s = 30,//
    t_datebcd = 31,//
    t_timebcd = 32,//
    t_oi = 80,//
    t_oad = 81,//
    t_road = 82,//
    t_omd = 83,//
    t_ti = 84,//
    t_tsa = 85,//
    t_mac = 86,//
    t_rn = 87,//
    t_region = 88,//
    t_scaler_unit = 89,//
    t_rsd = 90,//
    t_csd = 91,//
    t_ms = 92,//
    t_sid = 93,//
    t_sid_mac = 94,//
    t_comdcb = 95,////
    t_rcsd = 96,//
    /// 自定义数据类型
    t_nothing = 255//

}eDataType;

typedef enum _eDAR
{
    _Succ=0,//成功                 （0），
    _HardWareInvalid,//硬件失效             （1），
    _TemporaryInvalid,//暂时失效             （2），
    _RefuseReadWrite,//拒绝读写             （3），
    _ObjNoDefine,//对象未定义           （4），
    _ObjInterfaceUnConformity,//对象接口类不符合     （5），
    _ObjExist,//对象不存在           （6），
    _TypeUnConformity,//类型不匹配           （7），
    _OverstepBoundary,//越界                 （8），
    _DataBlockBad,//数据块不可用         （9），
    _FenFrameTransCancel,//分帧传输已取消       （10），
    _NotFenFrameTrans,//不处于分帧传输状态   （11），
    _BlockWriteCancel,//块写取消             （12），
    _NoExistBlockWriteState,//不存在块写状态       （13），
    _DatBlockIDInvalid,//数据块序号无效       （14），
    _PasswordError,//密码错/未授权        （15），
    _CommRateNoChange,//通信速率不能更改     （16），
    _YearZoneOver,//年时区数超           （17），
    _DayZoneOver,//日时段数超           （18），
    _RateOver,//费率数超             （19），
    _SecuritCertificateMisMatch,//安全认证不匹配       （20），
    _Recharge,//重复充值             （21），
    _ESAMFail,//ESAM验证失败        （22），
    _SecuritFail,//安全认证失败         （23），
    _ClientNoMismatch,//客户编号不匹配       （24），
    _RechargeTimesErr,//充值次数错误         （25），
    _BuyEletriOver,//购电超囤积           （26），
    _AddrException,//地址异常             （27），
    _SymmDecryptErr,//对称解密错误         （28），
    _UnsymmDecryptErr,//非对称解密错误       （29），
    _AutographErr,//签名错误             （30），
    _MeterHangup,//电能表挂起           （31），
    _TimeStampInvalid,//时间标签无效          (32)，
    _RequestTimeOut,//请求超时             （33），
    _ESAM_P1P2_Err,//ESAM的P1P2不正确    （34），
    _ESA_LC_Err,//ESAM的LC错误        （35），
    _Other = 255//其它                 （255）

}eDAR;

typedef enum _eLinkAPDU
{
    ///     预连接请求
    LinkRequest = 1,
    ///     预连接响应
    LinkRespnose = 129,

}eLinkAPDU;

typedef enum _eClientAPDU
{
    ///     建立应用连接请求
    ConnectRequest = 2,
    ///     断开应用连接请求
    ReleaseRequest = 3,
    ///     读取请求
    GetRequest = 5,
    ///     设置请求
    SetRequest = 6,
    ///     操作请求
    ActionRequest = 7,
    ///     上报应答
    ReportResponse = 8,
    ///     代理请求
    ProxyRequest = 9,
    //      异常响应
    Error_Response1=110

}eClientAPDU;

typedef enum _eServerAPDU
{
    ///     建立应用连接响应
    ConnectResponse = 130,
    ///     断开应用连接响应
    ReleaseResponse = 131,
    ///     断开应用连接通知
    ReleaseNotification = 132,
    ///     读取响应
    GetResponse = 133,
    ///     设置响应
    SetResponse = 134,
    ///     操作响应
    ActionResponse = 135,
    ///     上报通知
    ReportNotification = 136,
    ///     代理响应
    ProxyResponse = 137,
    //      异常响应
    Error_Response2=238

}eServerAPDU;

typedef enum _eSecurityAPDU
{
    ///     安全请求
    SecurityRequest = 16,
    ///     安全响应
    SecurityResponse = 144

}SecurityAPDU;

#endif // DLT698DATATYPES_H
