#include <pistache/endpoint.h>
#include <pistache/http_headers.h>
#include <iostream>
#include <string>

#define CORES 4
#define PORT 8080

class ServerHandler : public Pistache::Http::Handler
{
  public:
    HTTP_PROTOTYPE(ServerHandler)

    void onRequest(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
    {
        response.send(Pistache::Http::Code::Ok, "Hello world");
    }
};

int main(int argc, char *argv[])
{
    const unsigned int cores = CORES;
    const unsigned int port = PORT;
    std::cout << "Starting server on port " << port << " with " << cores << " cores" << std::endl;
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(port));
    auto opts = Pistache::Http::Endpoint::options().threads(cores);
    Pistache::Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(std::make_shared<ServerHandler>());
    server.serve();
    return 0;
}
