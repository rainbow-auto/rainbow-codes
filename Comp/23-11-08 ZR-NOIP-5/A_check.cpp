#include <iostream>
#include <string>

using namespace std;

int main () {

    freopen ("A_test.out", "r", stdin);

    std::string s; std::cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.size () - 1; i++) {
        if (s[i] != s[i + 1]) { cnt ++; }
    }

    std::cout << cnt << "\n";

    return 0;
}