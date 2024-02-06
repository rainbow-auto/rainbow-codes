#include <iostream>
#include <string>

using i64 = long long;

int T;

int main () {

    std::cin >> T;

    while (T--) {
        int n; std::cin >> n;
        std::string s; std::cin >> s; s = " " + s;
        
        int first = 0;
        int last = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i] == 'B') {
                last = i;
                if (not first) { first = i; }
            }
        }

        std::cout << last - first + 1 << "\n";
    }

    return 0;
}