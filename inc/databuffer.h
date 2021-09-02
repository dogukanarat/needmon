#ifndef _NEEDMON_DATABUFFER_H
#define _NEEDMON_DATABUFFER_H

#include "consts.h"
#include "stdint.h"

namespace Needmon
{
    class DataBuffer
    {
        public:
        DataBuffer() {};
        ~DataBuffer();

        uint8_t buffer[ MESSAGE_FRAME_SIZE ];
    };
}

#endif