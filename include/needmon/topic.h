#ifndef _NEEDMON_TOPIC_H
#define _NEEDMON_TOPIC_H

#include <list>
#include "types.h"
#include "message.h"
#include <thread>
#include <mutex>

namespace Needmon
{
    class Topic
    {
    public:
        Topic(){};
        ~Topic(){};

        void Publish(Message &message);
        void Subscribe(void (*callback)(Message &));

    protected:
        mutable std::mutex m_mutex;
        std::list<void (*)(Message &)> m_callbacks;
    };
}
#endif
