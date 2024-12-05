#include "Stringa.h"
#include <iostream>

int main() {
    Stringa str1("Hello");
    Stringa str2(" World!");

    Stringa str3 = str1 + str2;
    str1 += str2;

    std::cout << "+ " << str3 << std::endl;
    std::cout << "+= " << str1 << std::endl;
    std::cout << "[1] " << str1[1] << std::endl;
    std::cout << "== " << (str1 == str3) << std::endl;
    std::cout << "!= " << (str1 != str2) << std::endl;
    std::cout << "> " << (str1 > str2) << std::endl;
    std::cout << "< " << (str1 < str3) << std::endl;

    return 0;
}
