#include <iostream>
#include <string>

#define CORES 4

int main(int argc, char *argv[])
{
    const unsigned int cores = CORES;
    std::cout << "Starting server on " << cores << " cores" << std::endl;
    return 0;
}
