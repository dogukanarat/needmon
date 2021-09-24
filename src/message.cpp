#include "message.h"

using namespace Needmon;

void Message::SetMessageId(uint8_t &messageId)
{
    m_messageId = messageId;
}

void Message::GetMessageId(uint8_t &messageId)
{
    messageId = m_messageId;
}

void Message::Serialize(Buffer &buffer)
{
    uint16_t payloadIdx = 0;

    m_payload.GetDataCount(m_messageSize);

    buffer.Set(MESSAGE_HEADER_IDX_SYNC_HIGH, m_syncHigh);
    buffer.Set(MESSAGE_HEADER_IDX_SYNC_LOW, m_syncLow);
    buffer.Set(MESSAGE_HEADER_IDX_MESSAGE_ID, m_messageId);
    buffer.Set(MESSAGE_HEADER_IDX_MESSAGE_SIZE, m_messageSize);

    while (payloadIdx < m_messageSize)
    {
        buffer.Set(MESSAGE_HEADER_SIZE + payloadIdx, m_payload.m_payloadBuffer[payloadIdx]);
        payloadIdx++;
    }
}

void Message::Parse(Buffer &buffer)
{
    uint16_t payloadIdx = 0;

    buffer.Get(MESSAGE_HEADER_IDX_SYNC_HIGH, m_syncHigh);
    buffer.Get(MESSAGE_HEADER_IDX_SYNC_LOW, m_syncLow);
    buffer.Get(MESSAGE_HEADER_IDX_MESSAGE_ID, m_messageId);
    buffer.Get(MESSAGE_HEADER_IDX_MESSAGE_SIZE, m_messageSize);

    m_payload.SetDataCount(m_messageSize);

    while (payloadIdx < m_messageSize)
    {
        buffer.Get(MESSAGE_HEADER_SIZE + payloadIdx, m_payload.m_payloadBuffer[payloadIdx]);
        payloadIdx++;
    }
}

void Message::EncodeReset()
{
}

void Message::DecodeReset()
{
}

void Message::Encode(Template &templateBuffer)
{
    templateBuffer.Encode(m_payload);
}

void Message::Decode(Template &templateBuffer)
{
    templateBuffer.Decode(m_payload);
}
