#include <iostream>

int T;

int n;
std::string s;

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n;
        std::cin >> s;

        int ans = 1;
        int pos = 1;

        bool last = false;
        while (pos < s.size ()) {
            ans ++;
            if (s[pos] == s[pos - 1]) { 
                if (not last) { pos += 2; last = true; }
                else { pos ++; last = false; }
            }
            else { pos ++; last = false; }
        }

        if (pos > s.size ()) { ans --; }

        std::cout << ans << "\n";
    }

    return 0;
}