#include <string>
#include "handler.hpp"
#include "headers/auth_token.hpp"

static const std::string TOKEN = "f8fe3bc90778c9eb1e3a80ac5ac4b7b71e50eeee13a887878dc6a683972aa0dd";

void ServerHandler::onRequest(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response)
{
    try
    {
        auto headers = request.headers();
        auto token_header = headers.tryGet<AuthToken>();
        if (token_header)
        {
            std::string token = token_header->token();
            if (TOKEN.compare(token) == 0)
            {
                response.send(Pistache::Http::Code::Ok, "Hello, World");
                return;
            }
        }
        response.send(Pistache::Http::Code::Unauthorized, "Unauthorized");
    }
    catch (int e)
    {
        response.send(Pistache::Http::Code::Unauthorized, "Unauthorized");
    }
}
