#include <iostream>
#include <string>
#include <cstring>

using i64 = long long;

const int maxn = 200005;

int T;

int n;
int a[maxn];

int cnt[30];

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n;

        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        memset (cnt, 0, sizeof (cnt));

        for (int i = 1; i <= n; i++) { 
            for (char c = 'a'; c <= 'z'; c++) {
                if (cnt[c - 'a'] == a[i]) { cnt[c - 'a'] ++; std::cout << c; break; }
            }     
        }

        std::cout << "\n";
    }

    return 0;
}