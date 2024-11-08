#include <iostream>
#include <string>

int T;

int n;

int main () {

    std::cin >> T;

    while (T--) {
        std::string a; std::cin >> a;
        std::string b = "";

        for (int i = 0; i + 1 < a.size (); i += 2) {
            char x = a[i], y = a[i + 1];

            if (isdigit (y)) { std::swap (x, y); }

            int k = x - '0';

            for (int j = 1; j <= k; j++) { b = b + y; }
        }

        std::cout << b << "\n";
    }

    return 0;
}