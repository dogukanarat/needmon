#include "topic.h"

using namespace Needmon;
using namespace std;

void Topic::Publish(Message &message)
{
    const lock_guard<std::mutex> lock(m_mutex);
    list<void (*)(Message &)>::iterator it;

    for (it = m_callbacks.begin(); it != m_callbacks.end(); ++it)
    {
        (*it)(message);
    }
}

void Topic::Subscribe(void (*callback)(Message &))
{
    const lock_guard<std::mutex> lock(m_mutex);
    m_callbacks.push_back(callback);
}
