#include "handler.hpp"

void ServerHandler::onRequest(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
{
    response.send(Pistache::Http::Code::Ok, "Hello world");
}
