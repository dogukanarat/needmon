#include "needmon/ethernet.h"

using namespace Needmon;
using namespace OSAL;

Ethernet::Ethernet(const Char *ipAddress, int portNo)
{
    m_ipAddress = const_cast<Char *>(ipAddress);
    m_portNo = portNo;
    m_host = (OS::host_t *)gethostbyname(ipAddress);

    m_serverSocketAddress = OS::address_in_init_by_name(m_host, m_portNo);
    m_serverLen = sizeof(*m_serverSocketAddress);
}

TCP::TCP(const Char *ipAddress, Int portNo) : Ethernet(ipAddress, portNo)
{
    m_serverSocket = OS::_socketStream();
    m_protocol = ETHERNET_TCP;
};

UDP::UDP(const Char *ipAddress, Int portNo) : Ethernet(ipAddress, portNo)
{
    m_serverSocket = OS::_socketDgram();
    m_protocol = ETHERNET_UDP;
};
