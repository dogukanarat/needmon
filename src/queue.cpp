#include "queue.h"

using namespace Needmon;

Queue::Queue(uint16_t maxLength)
{
    m_maxLength = maxLength;
    m_frames = new std::shared_ptr<Frame>[m_maxLength];
    m_head = 0;
    m_tail = 0;
}

Queue& Queue::Push(std::shared_ptr<Frame> frame)
{
    if( m_length < m_maxLength)
    {
        m_frames[m_head++] = frame;
        m_length++;
        m_isFailed = false;
    }
    else
    {
        m_isFailed = true;
    }
    
    return *this;
}

Queue& Queue::Pop(std::shared_ptr<Frame> frame)
{
    if( m_length != 0 )
    {
        frame = m_frames[m_tail];
        m_length--;
        m_isFailed = false;
    }
    else
    {
        m_isFailed = true;
    }
    
    return *this;
}
uint16_t Queue::Length()
{
    return m_length;
}

uint8_t Queue::IsFailed()
{
    return m_isFailed;
}

