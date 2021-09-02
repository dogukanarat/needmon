namespace Needmon
{
    class Packet
    {
        public:
        Packet() = default;
        ~Packet() = default;

        virtual void Encode();
        virtual void Decode();
    };
}