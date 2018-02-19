#include "auth_token.hpp"

void AuthToken::parse(const std::string &data)
{
    this->data = data;
}

void AuthToken::write(std::ostream &os) const
{
    os << this->data;
}

std::string AuthToken::token()
{
    if(&this->data) {
        return this->data;
    }
    else {
        std::cout << "no data" << std::endl;
        return "";
    }
}