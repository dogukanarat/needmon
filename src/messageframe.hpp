#include "dataframe.hpp"

namespace Needmon
{
    typedef enum
    {
        MESSAGE_FRAME_HEADER_IDX_SYNC_HIGH    = 0,
        MESSAGE_FRAME_HEADER_IDX_SYNC_LOW        ,
        MESSAGE_FRAME_HEADER_IDX_MESSAGE_ID      ,
        MESSAGE_FRAME_HEADER_IDX_MESSAGE_SIZE    ,
        MESSAGE_FRAME_HEADER_SIZE                ,

        MESSAGE_FRAME_HEADER_IDX_DATA         = MESSAGE_FRAME_HEADER_SIZE,
    } messageFrameIndex_t;

    const uint16_t MESSAGE_FRAME_SIZE         = DATA_FRAME_MAX_BUFFER_SIZE + MESSAGE_FRAME_HEADER_SIZE;
    const uint8_t  MESSAGE_FRAME_SYNC_HIGH    = 0xAB;
    const uint8_t  MESSAGE_FRAME_SYNC_LOW     = 0xCD;

    class MessageFrame : public DataFrame
    {
        public:
        MessageFrame();
        ~MessageFrame() {};

        void SetMessageID( uint8_t &messageID );
        void GetMessageID( uint8_t &messageID );

        void Serialize( uint8_t *buffer );
        void Parse( uint8_t *buffer );

        private:
        uint8_t _messageID  ;
        uint8_t _messageSize;
        uint8_t _syncHigh;
        uint8_t _syncLow;

    };
}