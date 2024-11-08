#include <iostream>
#include <string>
#include <algorithm>

int main () {

    std::string s1 = "aa";
    std::string s2 = "aaaa";

    if (s1 < s2) { std::cout << "s1 < s2\n"; }
    else { std::cout << "s1 > s2\n"; }

    return 0;
}