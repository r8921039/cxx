#include <boost/lambda/lambda.hpp>
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <string>

int main ()
{
    std::string str;
    std::ifstream file("test.txt", std::ios::in);

    if (file) {
        char c;
        while (file.get(c)) {
            std::cout << c << '|';
            std::cout << std::setfill('0') << std::setw(2) << std::uppercase << std::hex << (int)c << '\n';
            str.push_back(c);
        }
    }

    std::cout << "length: " << str.length() << '\n';

    //std::cout << str;
    for_each(str.begin(), str.end(), std::cout << boost::lambda::_1);

    std::cout << '\n' << "DONE" << '\n';
    return 0;
}

