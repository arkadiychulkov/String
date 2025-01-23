#include "Stringa.h"
#include <iostream>
#include <fstream>

int main() {
	try
	{
        Stringa str1("Hello");
        Stringa str3("");

        /*std::ofstream file("output.txt");
        std::string fname = "output.txt";*/
        str1.Serialize();
        //file.close();

        //std::ifstream inFile("output.txt");
        str3.Deserialize();
        //inFile.close();

        std::cout << str3;

        return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}
