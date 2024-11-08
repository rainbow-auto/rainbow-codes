#include <iostream>

int T;

int n;
std::string a;

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n;
        std::cin >> a; a = " " + a;

        int ans = 0;

        bool jumped = false;

        for (int i = 1; i <= n; i++) {
            if (a[i] == '*' and not jumped) { i++; jumped = true; }
            if (a[i] == '*' and jumped) { break; }

            ans += a[i] == '@';

            jumped = false;
        }

        std::cout << ans << "\n";
    }

    return 0;
}