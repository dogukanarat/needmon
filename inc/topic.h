#ifndef _NEEDMON_TOPIC_H
#define _NEEDMON_TOPIC_H

#include <list>

namespace Needmon
{
    class Topic
    {
    public:
        Topic(){};
        ~Topic(){};

        void Publish(){};
        void Subscribe(){};

    protected:
        std::list<void()> m_callbacks;
    }
}
#endif
