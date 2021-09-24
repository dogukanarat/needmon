#ifndef _NEEDMON_COMMUNICATION_H
#define _NEEDMON_COMMUNICATION_H

#include <osal.h>
#include "types.h"
#include "buffer.h"

namespace Needmon
{
    typedef int ErrorNo;

    class Communication
    {
    public:
        virtual ErrorNo SetHandler(void (*receiveHandler)(UInt8 *, UInt32))
        {
            m_receiveHandler = receiveHandler;
            return TRUE;
        };
        virtual ErrorNo Connect() = 0;
        virtual ErrorNo Process() = 0;
        virtual ErrorNo Read(Buffer &buffer) = 0;
        virtual ErrorNo Write(Buffer &buffer) = 0;

    protected:
        Communication(){};
        virtual ~Communication(){};

        Buffer m_buffer;
        void (*m_receiveHandler)(UInt8 *, UInt32) = nullptr;
    };

}

#endif