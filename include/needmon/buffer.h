#ifndef _NEEDMON_BUFFER_H
#define _NEEDMON_BUFFER_H

#include "types.h"
#include "consts.h"

namespace Needmon
{
    const UInt32 BUFFER_SIZE = MESSAGE_SIZE;

    class Buffer
    {
    public:
        Buffer()
        : m_size(BUFFER_SIZE)
        {};

        ~Buffer(){};

        UInt8 Set(UInt32 index, UInt8 &value);
        UInt8 Get(UInt32 index, UInt8 &value);
        UInt8 *GetAddress();
        UInt32 GetSize();

    protected:
        UInt32 m_size;
        UInt8 m_buffer[BUFFER_SIZE];
    };
}

#endif
