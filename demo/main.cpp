#include <iostream>

extern "C" {
    #include "libavcodec/avcodec.h"
}

int main() {

    std::cout << avcodec_configuration() << std::endl;

    return 0;
}