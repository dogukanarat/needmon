#include "dataframe.hpp"
#include <iostream>

namespace Needmon
{
    /**
     * @brief Construct a new Data Frame:: Data Frame object
     * 
     */
    DataFrame::DataFrame()
    {
        dataFrameWriteIdx = 0;
        dataFrameReadIdx  = 0;
    }

    /**
     * @brief 
     * 
     * @param converter 
     * @param byteCount 
     */
    void DataFrame::WriteToBuffer( byteConnector_t &converter, uint8_t byteCount )
    {
        uint8_t idx = 0;

        while( idx < byteCount )
        {
            dataFrameBuffer[ dataFrameWriteIdx++ ] = converter.ucBytes[ idx++ ];
        }
    }
    /**
     * @brief 
     * 
     * @param converter 
     * @param byteCount 
     */
    void DataFrame::ReadFromBuffer( byteConnector_t &converter, uint8_t byteCount )
    {
        uint8_t idx = 0;

        while( idx < byteCount )
        {
            converter.ucBytes[ idx++ ] = dataFrameBuffer[ dataFrameReadIdx++ ];
        }
    }

    /**
     * @brief 
     * 
     * @param data 
     */
    void DataFrame::Write( uint8_t &data )
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
    void DataFrame::Write( uint16_t &data )
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
    void DataFrame::Write( uint32_t &data )
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
    void DataFrame::Write( uint64_t &data )
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
    void DataFrame::Write( int8_t &data )
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
    void DataFrame::Write( int16_t &data )
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
    void DataFrame::Write( int32_t &data )
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
    void DataFrame::Write( int64_t &data )
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
    void DataFrame::Write( float32_t &data )
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
    void DataFrame::Write( float64_t &data )
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
    void DataFrame::Read( uint8_t &returnBuffer )
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
    void DataFrame::Read( uint16_t &returnBuffer )
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
    void DataFrame::Read( uint32_t &returnBuffer )
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
    void DataFrame::Read( uint64_t &returnBuffer )
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
    void DataFrame::Read( int8_t &returnBuffer )
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
    void DataFrame::Read( int16_t &returnBuffer )
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
    void DataFrame::Read( int32_t &returnBuffer )
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
    void DataFrame::Read( int64_t &returnBuffer )
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
    void DataFrame::Read( float32_t &returnBuffer )
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
    void DataFrame::Read( float64_t &returnBuffer )
    {
        byteConnector_t convertor = { 0 };

        ReadFromBuffer( convertor, sizeof(returnBuffer) );

        returnBuffer = convertor.dData;  
    }

    uint32_t DataFrame::GetDataCount( )
    {
        return dataFrameWriteIdx;
    }

    void DataFrame::SetDataCount( uint32_t dataCount )
    {
        dataFrameWriteIdx = dataCount;
    }

}
