#ifndef __AUTH_TOKEN__
#define __AUTH_TOKEN__

#pragma once

#include <pistache/http_headers.h>
#include <pistache/net.h>

class AuthToken : public Pistache::Http::Header::Header
{
  public:
    NAME("auth-token");

    void parse(const std::string &data);
    void write(std::ostream &os) const;

    std::string token();

  private:
    std::string data;
};

#endif
