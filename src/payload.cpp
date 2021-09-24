#include <iostream>
#include "payload.h"

using namespace Needmon;

/**
 * @brief 
 * 
 * @param converter 
 * @param byteCount 
 */
void Payload::WriteToBuffer(ByteConvertor &converter, UInt8 byteCount)
{
    UInt8 idx = 0;

    while (idx < byteCount)
    {
        m_payloadBuffer[m_writeIndex++] = converter.ucBytes[idx++];
    }

    m_dataCount = m_writeIndex;
}
/**
 * @brief 
 * 
 * @param converter 
 * @param byteCount 
 */
void Payload::ReadFromBuffer(ByteConvertor &converter, UInt8 byteCount)
{
    UInt8 idx = 0;

    while (idx < byteCount)
    {
        converter.ucBytes[idx++] = m_payloadBuffer[m_readIndex++];
    }
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(UInt8 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.ucData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(UInt16 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.usData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(UInt32 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.ulData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(UInt64 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.ullData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(Int8 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.cData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(Int16 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.sData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(Int32 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.lData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(Int64 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.llData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(Float32 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.fData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param writeBuffer 
 */
void Payload::Write(Float64 &writeBuffer)
{
    ByteConvertor convertor = {0};

    convertor.dData = writeBuffer;

    WriteToBuffer(convertor, sizeof(writeBuffer));
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(UInt8 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.ucData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(UInt16 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.usData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(UInt32 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.ulData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(UInt64 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.ullData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(Int8 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.cData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(Int16 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.sData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(Int32 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.lData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(Int64 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.llData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(Float32 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.fData;
}

/**
 * @brief 
 * 
 * @param readBuffer 
 */
void Payload::Read(Float64 &readBuffer)
{
    ByteConvertor convertor = {0};

    ReadFromBuffer(convertor, sizeof(readBuffer));

    readBuffer = convertor.dData;
}

void Payload::GetDataCount(UInt8 &dataCount)
{
    dataCount = m_dataCount;
}

void Payload::SetDataCount(UInt8 &dataCount)
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
    m_writeIndex = 0;
    m_readIndex = 0;
    m_dataCount = 0;
}

void Payload::DecodeReset()
{
    m_readIndex = 0;
}
