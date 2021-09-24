#ifndef _NEEDMON_ETHERNET_H
#define _NEEDMON_ETHERNET_H

#include <osal.h>
#include "types.h"
#include "buffer.h"
#include "communication.h"

namespace Needmon
{
    typedef enum
    {
        ETHERNET_UDP,
        ETHERNET_TCP,
    } EthernetProtocol;

    class Ethernet
    {
    public:
        Ethernet(const Char *ipAddress, Int portNo);

        UInt16 m_portNo;
        Char *m_ipAddress;
        Int m_serverSocket;
        EthernetProtocol m_protocol;
        OSAL::Socket::host_t *m_host;
        OSAL::Socket::address_in_t *m_serverSocketAddress;
        OSAL::Socket::length_t m_serverLen;
    };

    class TCP : public Ethernet
    {
    public:
        TCP(const Char *ipAddress, Int portNo);
        ~TCP(){};
    };

    class UDP : public Ethernet
    {
    public:
        UDP(const Char *ipAddress, Int portNo);
        ~UDP(){};
    };
}
#endif
