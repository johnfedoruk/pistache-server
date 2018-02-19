#ifndef __SERVER_HANDLER__
#define __SERVER_HANDLER__

#pragma once

#include <pistache/endpoint.h>


class ServerHandler : public Pistache::Http::Handler
{
  public:
    HTTP_PROTOTYPE(ServerHandler)
    void onRequest(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response);
};

#endif