#include <iostream>
#include <algorithm>
#include <string>

using i64 = long long;

std::string s;

int main () {

    std::cout << 0 % 3 << "\n";

    std::cin >> s;

    std::sort (s.begin (), s.end(), [] (char a, char b) { return a < b; });

    std::cout << s << "\n";
    
    std::sort (s.begin (), s.end(), [] (char a, char b) { return a > b; });

    std::cout << s << "\n";

    return 0;
}