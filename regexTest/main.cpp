#include <iostream>
#include <string>
#include <regex>

int main() {

    std::string str("1");

    std::regex r("^\\d+$"); 

    std::smatch m;
    std::regex_search(str, m, r);

    std::cout << "after search, match was " 
              << (!m.empty() ? " true\n" : " not false\n");

    // std::regex r("^\\d+$"); 

    // std::smatch m;
    // std::regex_search(str, m, r);

    // for(auto v: m) {
    //     std::cout << v << std::endl;
    // }
    // std::cout << "after search, match was " 
    //           << (!m.empty() ? " found\n" : " not found\n");

    // std::string str("4");
    // std::regex r("^[2-3]$"); 

    // std::smatch m;
    // std::regex_search(str, m, r);

    // for(auto v: m) {
    //     std::cout << v << std::endl;
    // }
    // std::cout << "after search, match was " 
    //           << (!m.empty() ? " found\n" : " not found\n");
}