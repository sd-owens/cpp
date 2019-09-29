#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string str("1231");
    std::regex r("^(\\d)\\d"); // entire match will be 2 numbers

    std::smatch m;
    std::regex_search(str, m, r);

    for(auto v: m)
        std::cout << v << std::endl;
}