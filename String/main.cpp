#include "Stringa.h"
#include <iostream>

int main() {
    Stringa usStr("Hi");
    Stringa movestr = usStr;

    std::cout << "Us: ";
    usStr.Show();

    std::cout << "Mov: ";
    movestr.Show();

    return 0;
}
