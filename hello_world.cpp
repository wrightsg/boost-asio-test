#include <string>
#include <iostream>

#include <boost/asio.hpp>

namespace net = boost::asio;

int main (int argc, char** argv)
{
    net::ip::tcp::iostream s("www.boost.org", "http");

    s << "GET / HTTP/1.0\r\n";
    s << "Host: www.boost.org\r\n";
    s << "Accept: */*\r\n";
    s << "Connection: close\r\n\r\n";

    std::string header;
    while (s && std::getline(s, header) && header != "\r")
        std::cout << header << "\n";

    std::cout << s.rdbuf();

    return 0;
}
