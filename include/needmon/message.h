#ifndef _NEEDMON_MESSAGE_H
#define _NEEDMON_MESSAGE_H

#include "consts.h"
#include "payload.h"
#include "buffer.h"
#include "template.h"

namespace Needmon
{
    class Message
    {
    public:
        Message()
            : m_syncHigh(MESSAGE_SYNC_HIGH), m_syncLow(MESSAGE_SYNC_LOW){};
        ~Message(){};

        Payload m_payload;

        void SetMessageId(UInt8 &messageId);
        void GetMessageId(UInt8 &messageId);
        void Serialize(Buffer &buffer);
        void Parse(Buffer &buffer);
        void Decode(Template &templateBuffer);
        void Encode(Template &templateBuffer);
        void EncodeReset();
        void DecodeReset();

    private:
        UInt8 m_messageId;
        UInt8 m_messageSize;
        UInt8 m_syncHigh;
        UInt8 m_syncLow;
    };
}

#endif
