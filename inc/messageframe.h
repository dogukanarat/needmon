#ifndef _MESSAGEFRAME_HPP
#define _MESSAGEFRAME_HPP

#include "consts.h"
#include "dataframe.h"
#include "databuffer.h"

namespace Needmon
{
    class MessageFrame : public DataFrame
    {
        public:
        MessageFrame();
        ~MessageFrame() {};

        void SetMessageID( uint8_t &messageID );
        void GetMessageID( uint8_t &messageID );

        void Serialize( DataBuffer &buffer );
        void Parse( DataBuffer &buffer );

        private:
        uint8_t _messageID  ;
        uint8_t _messageSize;
        uint8_t _syncHigh;
        uint8_t _syncLow;

    };
}

#endif