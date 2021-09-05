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
    uint16_t payloadIdx = 0;

    GetDataCount(m_messageSize);

    buffer.Set(FRAME_HEADER_IDX_SYNC_HIGH    , m_syncHigh    );
    buffer.Set(FRAME_HEADER_IDX_SYNC_LOW     , m_syncLow     );
    buffer.Set(FRAME_HEADER_IDX_MESSAGE_ID   , m_messageId   );
    buffer.Set(FRAME_HEADER_IDX_MESSAGE_SIZE , m_messageSize );

    while( payloadIdx < m_messageSize )
    {
        buffer.Set(FRAME_HEADER_SIZE + payloadIdx, m_payloadBuffer[payloadIdx] );
        payloadIdx++;
    }
}

void Frame::Parse( Buffer& buffer )
{
    uint16_t payloadIdx = 0;
    
    buffer.Get(FRAME_HEADER_IDX_SYNC_HIGH    , m_syncHigh    );
    buffer.Get(FRAME_HEADER_IDX_SYNC_LOW     , m_syncLow     );
    buffer.Get(FRAME_HEADER_IDX_MESSAGE_ID   , m_messageId   );
    buffer.Get(FRAME_HEADER_IDX_MESSAGE_SIZE , m_dataCount   );

    SetDataCount( m_messageSize );

    while( payloadIdx < m_messageSize )
    {
        buffer.Get(FRAME_HEADER_SIZE + payloadIdx, m_payloadBuffer[payloadIdx] );
        payloadIdx++; 
    }

}

void Frame::Reset()
{
    m_writeIndex  = 0;
    m_readIndex   = 0;
    m_dataCount   = 0;
}