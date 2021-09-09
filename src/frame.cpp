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

    m_payload.GetDataCount(m_messageSize);

    buffer.Set(FRAME_HEADER_IDX_SYNC_HIGH    , m_syncHigh    );
    buffer.Set(FRAME_HEADER_IDX_SYNC_LOW     , m_syncLow     );
    buffer.Set(FRAME_HEADER_IDX_MESSAGE_ID   , m_messageId   );
    buffer.Set(FRAME_HEADER_IDX_MESSAGE_SIZE , m_messageSize );

    while( payloadIdx < m_messageSize )
    {
        buffer.Set(FRAME_HEADER_SIZE + payloadIdx, m_payload.m_payloadBuffer[payloadIdx] );
        payloadIdx++;
    }
}

void Frame::Parse( Buffer& buffer )
{
    uint16_t payloadIdx = 0;
    
    buffer.Get(FRAME_HEADER_IDX_SYNC_HIGH    , m_syncHigh    );
    buffer.Get(FRAME_HEADER_IDX_SYNC_LOW     , m_syncLow     );
    buffer.Get(FRAME_HEADER_IDX_MESSAGE_ID   , m_messageId   );
    buffer.Get(FRAME_HEADER_IDX_MESSAGE_SIZE , m_messageSize );

    m_payload.SetDataCount( m_messageSize );

    while( payloadIdx < m_messageSize )
    {
        buffer.Get(FRAME_HEADER_SIZE + payloadIdx, m_payload.m_payloadBuffer[payloadIdx] );
        payloadIdx++; 
    }

}

void Frame::EncodeReset()
{

}

void Frame::DecodeReset()
{
    
}

void Frame::Encode(Packet& packet)
{
    packet.Encode(m_payload);
}

void Frame::Decode(Packet& packet)
{
    packet.Decode(m_payload);
}