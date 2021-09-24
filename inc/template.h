#ifndef _NEEDMON_MESSAGE_HANDLER_H
#define _NEEDMON_MESSAGE_HANDLER_H

#include "payload.h"

namespace Needmon
{
    class Template
    {
    public:
        Template(){};
        ~Template(){};

        virtual void Encode(Payload &payload){};
        virtual void Decode(Payload &payload){};
    };
}

#endif
