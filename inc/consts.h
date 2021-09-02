#ifndef __NEEDMON_CONSTS_H
#define __NEEDMON_CONSTS_H

namespace Needmon
{
    typedef float  float32_t;
    typedef double float64_t;

    typedef enum
    {
        MESSAGE_FRAME_HEADER_IDX_SYNC_HIGH    = 0,
        MESSAGE_FRAME_HEADER_IDX_SYNC_LOW        ,
        MESSAGE_FRAME_HEADER_IDX_MESSAGE_ID      ,
        MESSAGE_FRAME_HEADER_IDX_MESSAGE_SIZE    ,
        MESSAGE_FRAME_HEADER_SIZE                ,
        MESSAGE_FRAME_HEADER_IDX_DATA         = MESSAGE_FRAME_HEADER_SIZE,
    } MessageFrameIndex;

    typedef enum
    {
        DATA_FRAME_MAX_BUFFER_SIZE  = 255,
    } DataFrameConsts;
    
    typedef enum
    {
        MESSAGE_FRAME_SIZE         = DATA_FRAME_MAX_BUFFER_SIZE + MESSAGE_FRAME_HEADER_SIZE,
        MESSAGE_FRAME_SYNC_HIGH    = 0xAB,
        MESSAGE_FRAME_SYNC_LOW     = 0xCD,

    } MessageFrameConsts;


}

#endif