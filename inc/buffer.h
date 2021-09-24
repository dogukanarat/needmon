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
        Buffer(){};
        ~Buffer(){};

        UInt8 Set(uint32_t index, UInt8 &value);
        UInt8 Get(uint32_t index, UInt8 &value);
        UInt8 *GetAddress();
        UInt32 GetSize();

    protected:
        UInt32 m_size = BUFFER_SIZE;
        UInt8 m_buffer[BUFFER_SIZE];
    };
}

#endif