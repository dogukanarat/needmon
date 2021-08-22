
namespace Needmon
{
    class Connection
    {
        public:
        virtual ~Connection() {};

        virtual int Connect() = 0;
    };

    class TCPConnectionBase
    {
        public:
        ~TCPConnectionBase() {};

        int TCPConnectionConnect();
    };

    class TCPConnection : public Connection , private TCPConnectionBase
    {
        public:
        ~TCPConnection() {};

        virtual int Connect();
    };

    class UDPConnectionBase
    {
        public:
        ~UDPConnectionBase() {};

        int UDPConnectionConnect();
    };

    class UDPConnection : public Connection , private UDPConnectionBase
    {
        public:
        ~UDPConnection() {};

        virtual int Connect();
    };

    /** --------------------------------------------- */

    int TCPConnectionBase::TCPConnectionConnect()
    {
        return 1;
    }

    int UDPConnectionBase::UDPConnectionConnect()
    {
        return 2;
    }

    int TCPConnection::Connect()
    {
        return TCPConnectionConnect();
    }

    int UDPConnection::Connect()
    {
        return UDPConnectionConnect();
    }

}