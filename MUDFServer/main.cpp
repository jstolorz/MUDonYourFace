#include <iostream>
#include "MUDFNetworking/base.h"

int main() {
    std::cout << "Hello, Server!" << static_cast<int>(MyEnum::Three) << std::endl;
    return 0;
}
