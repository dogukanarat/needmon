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

int Server::Connect()
{
    int result = true;

    if( Socket::_bind( m_ethernet->m_serverSocket,
        (Socket::address_t*)(m_ethernet->m_serverSocketAddress),
        m_ethernet->m_serverLen) < 0 )
    {
        OS::display("[SERVER] Controller server connection error! ");
        result = false;
    } else {}

    return result;
}

int Server::Process()
{
    int result = true;

    uint8_t buffer[1024];

    if( Socket::_listen( m_ethernet->m_serverSocket ) < 0 )
    {
        OS::display("[SERVER] Controller server listening error! ");
        result = false;
    } else {}

    OS::display("[SERVER] Controller server is accepting! ");

    m_clientSocket = Socket::_accept( m_ethernet->m_serverSocket,
                    (Socket::address_t*)(m_clientSocketAddress),
                    &m_clientSocketLen );

    OS::display("[SERVER] Controller server is accepted! ");

    while ( result == true )
    {
        Socket::_read( m_clientSocket, buffer, 1024);

        if( m_receiveHandler != nullptr )
        {
            m_receiveHandler(buffer, 1024);
        } else {}
    }

    Socket::_close( m_clientSocket );

    return result;
}

Client::Client(Ethernet* ethernet)
{
    m_ethernet = ethernet;
}

int Client::Connect()
{
    int result = true;

    if( Socket::_connect( m_ethernet->m_serverSocket,
        m_ethernet->m_serverSocketAddress) < 0 )
    {
        OS::display("[CLIENT] Controller client connection error! ");
        result = false;
    } else {}

    return result;
}

int Client::Process()
{
    int result = true;

    while ( result == true )
    {
        uint8_t buffer[1024];

        buffer[0] = 0x12;

        Socket::_write(m_ethernet->m_serverSocket, buffer, 1024 );
        
    }

    return result;
}