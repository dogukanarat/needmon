#include "queue.h"

using namespace Needmon;

Queue::Queue(uint16_t maxLength)
{
    m_maxLength = maxLength;
}

Queue& Queue::Push(std::shared_ptr<Frame> frame)
{
    //m_instances.push_back(frame);
    return *this;
}

Queue& Queue::Pop(std::shared_ptr<Frame> frame)
{
    //frame = m_instance.pop_front();
    return *this;
}

