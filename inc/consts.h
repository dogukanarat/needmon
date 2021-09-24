#ifndef _NEEDMON_CONSTS_H
#define _NEEDMON_CONSTS_H

#include "types.h"

namespace Needmon
{
    typedef enum
    {
        MESSAGE_HEADER_IDX_SYNC_HIGH = 0,
        MESSAGE_HEADER_IDX_SYNC_LOW,
        MESSAGE_HEADER_IDX_MESSAGE_ID,
        MESSAGE_HEADER_IDX_MESSAGE_SIZE,
        MESSAGE_HEADER_SIZE,
    } MessageHeaderIndex;

    typedef enum
    {
        MAX_PAYLOAD_SIZE = 255,
    } PayloadConsts;

    typedef enum
    {
        MESSAGE_SIZE = MAX_PAYLOAD_SIZE + MESSAGE_HEADER_SIZE,
        MESSAGE_SYNC_HIGH = 0xAB,
        MESSAGE_SYNC_LOW = 0xCD,

    } MessageConsts;

}

#endif
