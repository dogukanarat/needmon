#include <stdint.h>
#include <stdlib.h>
#include <typeinfo>

namespace Needmon
{
    const uint16_t DATA_FRAME_MAX_BUFFER_SIZE  = 255;

    typedef float  float32_t;
    typedef double float64_t;

    typedef union
    {
        uint8_t    ucData      ;
        uint16_t   usData      ;
        uint32_t   ulData      ;
        uint64_t   ullData     ;
        float32_t  fData       ;
        float64_t  dData       ;
        int8_t     cData       ;
        int16_t    sData       ;
        int32_t    lData       ;
        int64_t    llData      ;
        uint8_t    ucBytes[8]  ;
    } byteConnector_t;

    class DataFrame
    {
        public:
        DataFrame();
        ~DataFrame() {};

        void Write( uint8_t   &data );
        void Write( uint16_t  &data );
        void Write( uint32_t  &data );
        void Write( uint64_t  &data );
        void Write( int8_t    &data );
        void Write( int16_t   &data );
        void Write( int32_t   &data );
        void Write( int64_t   &data );
        void Write( float32_t &data );
        void Write( float64_t &data );

        void Read( uint8_t   &returnBuffer );
        void Read( uint16_t  &returnBuffer );
        void Read( uint32_t  &returnBuffer );
        void Read( uint64_t  &returnBuffer );
        void Read( int8_t    &returnBuffer );
        void Read( int16_t   &returnBuffer );
        void Read( int32_t   &returnBuffer );
        void Read( int64_t   &returnBuffer );
        void Read( float32_t &returnBuffer );
        void Read( float64_t &returnBuffer );



        protected:
        uint16_t dataFrameWriteIdx;
        uint16_t dataFrameReadIdx ;
        uint8_t  dataFrameBuffer[ DATA_FRAME_MAX_BUFFER_SIZE ];

        uint32_t GetDataCount();
        void     SetDataCount( uint32_t dataCount );

        void WriteToBuffer( byteConnector_t &converter, uint8_t byteCount );
        void ReadFromBuffer( byteConnector_t &converter, uint8_t byteCount );
    };
}
