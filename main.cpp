#include <iostream>
#include "binary_string.h"

int main() {
    BinaryString binary1("101010");
    BinaryString binary2("110110");

    BinaryString binarySum = binary1 + binary2;

    std::cout << "Binary String 1: " << binary1 << std::endl;
    std::cout << "Binary String 2: " << binary2 << std::endl;
    std::cout << "Sum of Binary Strings: " << binarySum << std::endl;

    return 0;
}

