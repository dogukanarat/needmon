#include "messageframe.hpp"

namespace Needmon
{
    MessageFrame::MessageFrame()
    {
    }

    void MessageFrame::SetMessageID( uint8_t &messageID )
    {
        _messageID = messageID;
    }

    void MessageFrame::GetMessageID( uint8_t &messageID )
    {
        messageID = _messageID;
    }

    void MessageFrame::Serialize( uint8_t *buffer )
    {
        _messageSize = GetDataCount();

        uint16_t dataFrameIdx = MESSAGE_FRAME_HEADER_IDX_DATA;

        buffer[ MESSAGE_FRAME_HEADER_IDX_SYNC_HIGH ]    = _syncHigh   ;
        buffer[ MESSAGE_FRAME_HEADER_IDX_SYNC_LOW ]     = _syncLow    ;
        buffer[ MESSAGE_FRAME_HEADER_IDX_MESSAGE_ID ]   = _messageID  ;
        buffer[ MESSAGE_FRAME_HEADER_IDX_MESSAGE_SIZE ] = _messageSize;
        
        while( dataFrameIdx - MESSAGE_FRAME_HEADER_IDX_DATA < dataFrameWriteIdx )
        {
            buffer[ dataFrameIdx ] = dataFrameBuffer[ dataFrameIdx - MESSAGE_FRAME_HEADER_IDX_DATA ];
            dataFrameIdx++;
        }
    }

    void MessageFrame::Parse( uint8_t *buffer )
    {
        _syncHigh    = buffer[ MESSAGE_FRAME_HEADER_IDX_SYNC_HIGH ]    ;
        _syncLow     = buffer[ MESSAGE_FRAME_HEADER_IDX_SYNC_LOW ]     ;
        _messageID   = buffer[ MESSAGE_FRAME_HEADER_IDX_MESSAGE_ID ]   ;
        _messageSize = buffer[ MESSAGE_FRAME_HEADER_IDX_MESSAGE_SIZE ] ;

        SetDataCount( _messageSize );

        uint16_t dataFrameIdx = MESSAGE_FRAME_HEADER_IDX_DATA;

        while( dataFrameIdx - MESSAGE_FRAME_HEADER_IDX_DATA < dataFrameWriteIdx )
        {
            dataFrameBuffer[ dataFrameIdx - MESSAGE_FRAME_HEADER_IDX_DATA ] = buffer[ dataFrameIdx ];
            dataFrameIdx++;
        }

    }

}