#include "buffer.h"

using namespace Needmon;

uint8_t* Buffer::GetAddress()
{
    return m_buffer;
}

uint32_t Buffer::GetSize()
{
    return m_size;
}

uint8_t Buffer::Set(uint32_t index, uint8_t& value)
{
    uint8_t result = true;

    if( index < m_size )
    {
        m_buffer[index] = value;
    }
    else
    {
        result = false;
    }

    return result;
}

uint8_t Buffer::Get(uint32_t index, uint8_t& value)
{
    uint8_t result = true;

    if( index < m_size )
    {
        value = m_buffer[index];
    }
    else
    {
        return false;
    }

    return result;
}