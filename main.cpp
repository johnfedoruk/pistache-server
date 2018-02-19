#include <pistache/endpoint.h>
#include <pistache/http_headers.h>
#include <iostream>
#include <string>

#include "server/handler.hpp"
#include "server/headers/auth_token.hpp"

#define CORES 4
#define PORT 8080

int main(int argc, char *argv[])
{
    const unsigned int cores = CORES;
    const unsigned int port = PORT;
    std::cout << "Starting server on port " << port << " with " << cores << " cores" << std::endl;
    Pistache::Http::Header::Registry::registerHeader<AuthToken>();
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(port));
    auto opts = Pistache::Http::Endpoint::options().threads(cores);
    Pistache::Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(std::make_shared<ServerHandler>());
    server.serve();
    return 0;
}
