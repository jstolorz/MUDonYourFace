#include <iostream>
#include <boost/asio.hpp>
#include <array>

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {

    try{

        boost::asio::io_context io_context;

        tcp::resolver resolver{io_context};

        auto endpoints = resolver.resolve("127.0.0.1", "1337");

        tcp::socket socket{io_context};
        boost::asio::connect(socket,endpoints);

        while (true){
            std::array<char,128> buf{};
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf),error);

            if(error == boost::asio::error::eof){
                break;
            } else if(error){
                throw boost::system::system_error(error);
            }

            std::cout.write(buf.data(),len);
        }

    }catch (std::exception& ex){
        std::cerr << ex.what() << "\n";
    }

    return 0;
}
