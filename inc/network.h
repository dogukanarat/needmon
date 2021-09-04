
#include "stdint.h"
#include "os_socket.h"

namespace Needmon
{
    class Communication
    {
        public:
        virtual int SetHandler(void (*receiveHandler)(uint8_t*,uint32_t)) { m_receiveHandler = receiveHandler; return true; };
        virtual int Connect() = 0;
        virtual int Process() = 0;

        protected:
        Communication() {};
        virtual ~Communication() {};

        void (*m_receiveHandler)(uint8_t*,uint32_t) = nullptr;
    };

    class Ethernet
    {
        public:
        Ethernet(const char* ipAddress, int portNo);

        uint16_t m_portNo;
        char* m_ipAddress;
        int m_serverSocket;
        OSAL::Socket::host_t* m_host;
        OSAL::Socket::address_in_t* m_serverSocketAddress;
        OSAL::Socket::length_t m_serverLen;
        
    };

    class TCP : public Ethernet
    {
        public:
        TCP(const char * ipAddress, int portNo) 
        : Ethernet{ ipAddress, portNo}
        {
        m_serverSocket = OSAL::Socket::_socketStream();
        };

        ~TCP() {};
    };

    class UDP : public Ethernet
    {
        public:
        UDP(const char * ipAddress, int portNo) 
        : Ethernet{ ipAddress, portNo}
        {
        m_serverSocket = 0;
        };

        ~UDP() {};
    };

    class Server : public Communication
    {
        public:
        Server(Ethernet* ethernet);
        ~Server() {};

        OSAL::Socket::address_in_t* m_clientSocketAddress = nullptr;
        OSAL::Socket::length_t m_clientSocketLen;
        int m_clientSocket;
        Ethernet* m_ethernet;

        int Connect() override;
        int Process() override;
    };

    class Client : public Communication
    {
        public:
        Client(Ethernet* ethernet);
        ~Client() {};

        Ethernet* m_ethernet;

        int Connect() override;
        int Process() override;
    };


}
