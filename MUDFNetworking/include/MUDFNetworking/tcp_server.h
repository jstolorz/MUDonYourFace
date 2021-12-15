#ifndef MUDONYOURFACE_TCP_SERVER_H
#define MUDONYOURFACE_TCP_SERVER_H


#include <string>
#include <boost/asio.hpp>

namespace MOYF {

    enum class IPV{
        V4,V6
    };

    class TCPServer {

    public:
        TCPServer(IPV ipv, int port);
        int run();

    private:
        void start_accept();
    private:
        IPV _ip_version;
        int _port;
        boost::asio::io_context _io_context;
        boost::asio::ip::tcp::acceptor _acceptor;
    };
}



#endif //MUDONYOURFACE_TCP_SERVER_H
