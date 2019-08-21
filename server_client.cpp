#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <boost/asio.hpp>

namespace net = boost::asio;

TEST_CASE()
{
    net::io_context io_context;

    constexpr unsigned short port = 51000;
    net::ip::tcp::endpoint endpoint;

    net::ip::tcp::acceptor acceptor(io_context, endpoint);

    //net::ip::tcp::socket socket;

    //acceptor.accept(socket);
}
