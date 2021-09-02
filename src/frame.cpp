#include "frame.h"

using namespace Needmon;

void Frame::SetMessageId( uint8_t& messageId )
{
    m_messageId = messageId;
}

void Frame::GetMessageId( uint8_t& messageId )
{
    messageId = m_messageId;
}

void Frame::Serialize( Buffer& buffer )
{
    m_messageSize = GetDataCount();

    uint16_t dataFrameIdx = FRAME_HEADER_IDX_DATA;

    uint8_t* tempBuffer = buffer.GetBuffer();

    tempBuffer[ FRAME_HEADER_IDX_SYNC_HIGH ]    = m_syncHigh   ;
    tempBuffer[ FRAME_HEADER_IDX_SYNC_LOW ]     = m_syncLow    ;
    tempBuffer[ FRAME_HEADER_IDX_MESSAGE_ID ]   = m_messageId  ;
    tempBuffer[ FRAME_HEADER_IDX_MESSAGE_SIZE ] = m_messageSize;
    
    while( dataFrameIdx - FRAME_HEADER_IDX_DATA < writeIdx )
    {
        tempBuffer[ dataFrameIdx ] = serialBuffer[ dataFrameIdx - FRAME_HEADER_IDX_DATA ];
        dataFrameIdx++;
    }
}

void Frame::Parse( Buffer &buffer )
{
    uint8_t* tempBuffer = buffer.GetBuffer();

    m_syncHigh    = tempBuffer[ FRAME_HEADER_IDX_SYNC_HIGH ]    ;
    m_syncLow     = tempBuffer[ FRAME_HEADER_IDX_SYNC_LOW ]     ;
    m_messageId   = tempBuffer[ FRAME_HEADER_IDX_MESSAGE_ID ]   ;
    m_messageSize = tempBuffer[ FRAME_HEADER_IDX_MESSAGE_SIZE ] ;

    SetDataCount( m_messageSize );

    uint16_t dataFrameIdx = FRAME_HEADER_IDX_DATA;

    while( dataFrameIdx - FRAME_HEADER_IDX_DATA < writeIdx )
    {
        serialBuffer[ dataFrameIdx - FRAME_HEADER_IDX_DATA ] = tempBuffer[ dataFrameIdx ];
        dataFrameIdx++;
    }

}