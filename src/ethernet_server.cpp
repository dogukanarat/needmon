#include "needmon/ethernet_server.h"

using namespace Needmon;
using namespace OSAL;

Server::Server(Ethernet *ethernet)
{
    m_ethernet = ethernet;
    m_clientSocketAddress = static_cast<Socket::address_in_t *>(OS::memAllocate(sizeof(Socket::address_in_t)));
    m_clientSocketLen = sizeof(*m_clientSocketAddress);
}

Server::~Server()
{
    if (m_clientSocket != 0)
    {
        Socket::_close(m_clientSocket);
    }
    else
    {
    }
}

ErrorNo Server::Connect()
{
    ErrorNo result = true;
    int32_t errNo = 0;

    errNo = Socket::_bind(m_ethernet->m_serverSocket,
                          (Socket::address_t *)(m_ethernet->m_serverSocketAddress),
                          m_ethernet->m_serverLen);

    if (errNo < 0)
    {
#ifdef PRINT_ERRORS
        OS::print("[SERVER] Controller server connection error! (errno: %d)\n", errNo);
#endif
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

ErrorNo Server::Process()
{
    ErrorNo result = true;
    int32_t errNo = 0;

    if (m_ethernet->m_protocol == ETHERNET_TCP)
    {
        errNo = Socket::_listen(m_ethernet->m_serverSocket);

        if (errNo < 0)
        {
#ifdef PRINT_ERRORS
            OS::print("[SERVER] Controller server listening error! (errno: %d)\n", errNo);
#endif
            result = false;
        }
        else
        {
            m_clientSocket = Socket::_accept(m_ethernet->m_serverSocket,
                                             (Socket::address_t *)(m_clientSocketAddress),
                                             &m_clientSocketLen);

            if (m_clientSocket != 0)
            {
                result = true;
            }
            else
            {
                result = false;
            }
        }
    }
    else if (m_ethernet->m_protocol == ETHERNET_UDP)
    {
    }
    else
    {
    }

    return result;
}

ErrorNo Server::Read(Buffer &buffer)
{
    ErrorNo result = false;

    if (m_clientSocket != 0)
    {
        int32_t size = 0;
        size = Socket::_read(m_clientSocket, buffer.GetAddress(), buffer.GetSize());
        if (size > 0)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
    }

    return result;
}

ErrorNo Server::Write(Buffer &buffer)
{
    ErrorNo result = false;

    if (m_clientSocket != 0)
    {
        int32_t size = 0;

        size = Socket::_write(m_clientSocket, buffer.GetAddress(), buffer.GetSize());

        if (size > 0)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
    }

    return result;
}
