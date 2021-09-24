#ifndef _NEEDMON_PAYLOAD_H
#define _NEEDMON_PAYLOAD_H

#include <stdlib.h>
#include <typeinfo>
#include "types.h"
#include "consts.h"

namespace Needmon
{
    typedef union
    {
        UInt8 ucData;
        UInt16 usData;
        UInt32 ulData;
        UInt64 ullData;
        Float32 fData;
        Float64 dData;
        Int8 cData;
        Int16 sData;
        Int32 lData;
        Int64 llData;
        UInt8 ucBytes[8];
    } ByteConvertor;

    class Payload
    {
    public:
        Payload()
            : m_writeIndex(0), m_readIndex(0){};
        ~Payload(){};

        void Write(UInt8 &);
        void Write(UInt16 &);
        void Write(UInt32 &);
        void Write(UInt64 &);
        void Write(Int8 &);
        void Write(Int16 &);
        void Write(Int32 &);
        void Write(Int64 &);
        void Write(Float32 &);
        void Write(Float64 &);

        void Read(UInt8 &);
        void Read(UInt16 &);
        void Read(UInt32 &);
        void Read(UInt64 &);
        void Read(Int8 &);
        void Read(Int16 &);
        void Read(Int32 &);
        void Read(Int64 &);
        void Read(Float32 &);
        void Read(Float64 &);

        UInt8 m_writeIndex;
        UInt8 m_readIndex;
        UInt8 m_dataCount;
        UInt8 m_payloadBuffer[MAX_PAYLOAD_SIZE];

        void GetDataCount(UInt8 &dataCount);
        void SetDataCount(UInt8 &dataCount);
        void EncodeReset();
        void DecodeReset();
        void Reset();
        void WriteToBuffer(ByteConvertor &converter, UInt8 byteCount);
        void ReadFromBuffer(ByteConvertor &converter, UInt8 byteCount);
    };
}

#endif