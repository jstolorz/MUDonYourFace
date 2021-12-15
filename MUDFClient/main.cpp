#include <iostream>
#include "MUDFNetworking/base.h"

int main() {
    std::cout << "Hello, Client!" << static_cast<int>(MyEnum::One) << std::endl;
    return 0;
}
