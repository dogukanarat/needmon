#include <iostream>
#include "payload.h"

using namespace Needmon;

/**
 * @brief 
 * 
 * @param converter 
 * @param byteCount 
 */
void Payload::WriteToBuffer( byteConnector_t &converter, uint8_t byteCount )
{
    uint8_t idx = 0;

    while( idx < byteCount )
    {
        m_payloadBuffer[ m_writeIndex++ ] = converter.ucBytes[ idx++ ];
    }

    m_dataCount = m_writeIndex;
}
/**
 * @brief 
 * 
 * @param converter 
 * @param byteCount 
 */
void Payload::ReadFromBuffer( byteConnector_t &converter, uint8_t byteCount )
{
    uint8_t idx = 0;

    while( idx < byteCount )
    {
        converter.ucBytes[ idx++ ] = m_payloadBuffer[ m_readIndex++ ];
    }
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( uint8_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.ucData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( uint16_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.usData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( uint32_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.ulData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( uint64_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.ullData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( int8_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.cData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( int16_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.sData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( int32_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.lData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( int64_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.llData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( float32_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.fData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param data 
 */
void Payload::Write( float64_t &data )
{
    byteConnector_t convertor = { 0 };
    
    convertor.dData = data;

    WriteToBuffer( convertor, sizeof( data ) );
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( uint8_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.ucData;  
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( uint16_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.usData;  
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( uint32_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.ulData;  
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( uint64_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.ullData;  
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( int8_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.cData;  
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( int16_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.sData;  
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( int32_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.lData;  
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( int64_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.llData;  
}

    /**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( float32_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.fData;  
}

/**
 * @brief 
 * 
 * @param returnBuffer 
 */
void Payload::Read( float64_t &returnBuffer )
{
    byteConnector_t convertor = { 0 };

    ReadFromBuffer( convertor, sizeof(returnBuffer) );

    returnBuffer = convertor.dData;  
}

void Payload::GetDataCount( uint8_t& dataCount )
{
    dataCount = m_dataCount;
}

void Payload::SetDataCount( uint8_t& dataCount )
{
    m_dataCount = dataCount;
    m_writeIndex = m_dataCount;
}

void Payload::Reset()
{
    m_writeIndex = 0;
    m_readIndex = 0;
}

void Payload::EncodeReset()
{
    m_writeIndex  = 0;
    m_readIndex   = 0;
    m_dataCount   = 0;
}

void Payload::DecodeReset()
{
    m_readIndex   = 0;
}