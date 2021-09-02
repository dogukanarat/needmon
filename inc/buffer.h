#ifndef _NEEDMON_BUFFER_H
#define _NEEDMON_BUFFER_H

#include "consts.h"
#include "stdint.h"

namespace Needmon
{
    class Buffer
    {
        public:
        Buffer() {};
        ~Buffer() {};

        uint8_t* GetBuffer();

        protected:
        uint8_t m_buffer[ FRAME_SIZE ];
    };
}

#endif