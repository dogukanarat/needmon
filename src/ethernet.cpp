#include "ethernet.h"

using namespace Needmon;
using namespace OSAL;

Ethernet::Ethernet(const char* ipAddress, int portNo)
{
    m_ipAddress = const_cast<char*>(ipAddress);
    m_portNo    = portNo; 
    m_host      = (OS::host_t*)gethostbyname(ipAddress);

    m_serverSocketAddress = OS::address_in_init_by_name( m_host, m_portNo );
    m_serverLen           = sizeof(*m_serverSocketAddress);

}

TCP::TCP(const char * ipAddress, int portNo) : Ethernet(ipAddress, portNo)
{   
    m_serverSocket = OS::_socketStream();
    m_protocol = ETHERNET_TCP;
};

UDP::UDP(const char * ipAddress, int portNo)  : Ethernet(ipAddress, portNo)
{
    m_serverSocket = OS::_socketDgram();
    m_protocol = ETHERNET_UDP;
};