#include "ethernet_client.h"

using namespace Needmon;
using namespace OSAL;

Client::Client(Ethernet *ethernet)
{
    m_ethernet = ethernet;
}

ErrorNo Client::Connect()
{
    int result = true;

    int32_t errNo = 0;

    errNo = Socket::_connect(m_ethernet->m_serverSocket, m_ethernet->m_serverSocketAddress);

    if (errNo < 0)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    return result;
}

ErrorNo Client::Process()
{
    ErrorNo result = true;

    return result;
}

ErrorNo Client::Read(Buffer &buffer)
{
    ErrorNo result = false;

    if (m_ethernet->m_serverSocket != 0)
    {
        int32_t size = 0;

        size = result = Socket::_read(m_ethernet->m_serverSocket, buffer.GetAddress(), buffer.GetSize());

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

ErrorNo Client::Write(Buffer &buffer)
{
    ErrorNo result = false;

    if (m_ethernet->m_serverSocket != 0)
    {
        Int32 size = 0;

        size = Socket::_write(m_ethernet->m_serverSocket, buffer.GetAddress(), buffer.GetSize());

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
