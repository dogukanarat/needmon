#include "buffer.h"

using namespace Needmon;

UInt8 *Buffer::GetAddress()
{
    return m_buffer;
}

UInt32 Buffer::GetSize()
{
    return m_size;
}

UInt8 Buffer::Set(UInt32 index, UInt8 &value)
{
    UInt8 result = true;

    if (index < m_size)
    {
        m_buffer[index] = value;
    }
    else
    {
        result = false;
    }

    return result;
}

UInt8 Buffer::Get(UInt32 index, UInt8 &value)
{
    UInt8 result = true;

    if (index < m_size)
    {
        value = m_buffer[index];
    }
    else
    {
        return false;
    }

    return result;
}