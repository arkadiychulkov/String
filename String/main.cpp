#include "Stringa.h"
#include <iostream>

int main() {
    Stringa defstr;
    Stringa sizeStr(100);
    Stringa usStr("Hi");
    Stringa copStr(usStr);

    std::cout << "Def: ";
    defstr.Show();

    std::cout << "string 100: ";
    sizeStr.Show();

    std::cout << "Us: ";
    usStr.Show();

    std::cout << "Cop: ";
    copStr.Show();

    return 0;
}
