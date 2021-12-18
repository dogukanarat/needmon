#ifndef _NEEDMON_COMMUNICATION_H
#define _NEEDMON_COMMUNICATION_H

#include "osal/osal.h"
#include "types.h"
#include "buffer.h"

namespace Needmon
{
    typedef int ErrorNo;

    class Communication
    {
    public:
        Communication()
        : m_buffer(Buffer())
        , m_receiveHandler(NULL)
        {};
        virtual ~Communication() {};

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
        Buffer m_buffer;
        void (*m_receiveHandler)(UInt8 *, UInt32);
    };

}

#endif
