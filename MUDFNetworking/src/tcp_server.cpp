#include <iostream>
#include "MUDFNetworking/tcp_server.h"


namespace MOYF {

    using boost::asio::ip::tcp;

    TCPServer::TCPServer(IPV ipv, int port):
    _ip_version(ipv),
    _port(port),
    _acceptor(_io_context, tcp::endpoint(_ip_version == IPV::V4 ? tcp::v4() : tcp::v6(), _port)){
    }

    int TCPServer::run() {
        try {
            start_accept();
            _io_context.run();
        }catch (std::exception& ex){
            std::cerr << ex.what() << "\n";
            return -1;
        }
        return 0;
    }

    void TCPServer::start_accept() {
        // Create a connection

        // Asynchronously accept the connection

    }


}
