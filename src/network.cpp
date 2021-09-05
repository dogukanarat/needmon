#include "network.h"
#include "osal.h"

using namespace Needmon;
using namespace OSAL;

Ethernet::Ethernet(const char* ipAddress, int portNo)
{
    m_ipAddress = const_cast<char*>(ipAddress);
    m_portNo    = portNo; 
    m_host      = (Socket::host_t*)gethostbyname(ipAddress);

    m_serverSocketAddress = Socket::address_in_init_by_name( m_host, m_portNo );
    m_serverLen           = sizeof(*m_serverSocketAddress);

}

Server::Server(Ethernet* ethernet)
{
    m_ethernet = ethernet;
    m_clientSocketAddress = static_cast<Socket::address_in_t*>(OS::memAllocate(sizeof(Socket::address_in_t)));
    m_clientSocketLen     = sizeof(*m_clientSocketAddress);
}

Server::~Server()
{
    if( m_clientSocket != 0 )
    {
        Socket::_close( m_clientSocket );
    } else {}
}

ErrorNo Server::Connect()
{
    ErrorNo result = true;

    int errno = 0;

    errno = Socket::_bind( m_ethernet->m_serverSocket,
            (Socket::address_t*)(m_ethernet->m_serverSocketAddress),
            m_ethernet->m_serverLen);

    if( errno < 0 )
    {
        OS::print("[SERVER] Controller server connection error! (errno: %d)\n", errno);
        result = false;
    } else {}

    return result;
}

ErrorNo Server::Process()
{
    ErrorNo result = true;

    int errno = 0;

    errno = Socket::_listen( m_ethernet->m_serverSocket );

    if( errno < 0 )
    {
        OS::print("[SERVER] Controller server listening error! (errno: %d)\n", errno);
        result = false;
    }
    else
    {
        m_clientSocket = Socket::_accept( m_ethernet->m_serverSocket,
                        (Socket::address_t*)(m_clientSocketAddress),
                        &m_clientSocketLen );
        
        if( m_clientSocket != 0 )
        {
            result = true;
        }
    }

    return result;
}

ErrorNo Server::Read(Buffer& buffer)
{
    ErrorNo result = false;

    if(m_clientSocket != 0)
    {
        uint32_t size = 0;
        size = Socket::_read( m_clientSocket, buffer.GetAddress(), buffer.GetSize());
        if( size > 0)
        {
            result = true;
        } else {}
    } else {}

    return result;
}

ErrorNo Server::Write(Buffer& buffer)
{
    ErrorNo result = false;

    if(m_clientSocket != 0)
    {
        uint32_t size = 0;
        size = Socket::_write( m_clientSocket, buffer.GetAddress(), buffer.GetSize());
        if( size > 0)
        {
            result = true;
        } else {}
    } else {}

    return result;
}

Client::Client(Ethernet* ethernet)
{
    m_ethernet = ethernet;
}

ErrorNo Client::Connect()
{
    int result = true;

    OS::print("[CLIENT] Connecting...\n");

    int errno = Socket::_connect( m_ethernet->m_serverSocket, m_ethernet->m_serverSocketAddress);

    OS::print("[CLIENT] (errno: %d)\n", errno);

    if( errno < 0 )
    {
        OS::print("[CLIENT] Controller client connection error! (errno: %d)", errno);
        result = false;
    } else {}

    return result;
}

ErrorNo Client::Process()
{
    ErrorNo result = true;
    return result;
}

ErrorNo Client::Read(Buffer& buffer)
{
    ErrorNo result = false;
    if(m_ethernet->m_serverSocket != 0)
    {
        uint32_t size = 0;
        size = result = Socket::_read( m_ethernet->m_serverSocket, buffer.GetAddress(), buffer.GetSize());
        if( size > 0)
        {
            result = true;
        } else {}
    } else {}

    return result;
}

ErrorNo Client::Write(Buffer& buffer)
{
    ErrorNo result = false;

    if(m_ethernet->m_serverSocket != 0)
    {
        uint32_t size = 0;
        size = Socket::_write( m_ethernet->m_serverSocket, buffer.GetAddress(), buffer.GetSize());

        if( size > 0)
        {
            result = true;
        } else {}
    } else {}

    return result;
}
