#include <iostream>

const int maxn = 500005;

int T;

int n;
int a[maxn];

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] <= (a[i] xor a[j]) and (a[i] xor a[j]) <= a[j]) { ans ++; }
            }
        }

        std::cout << ans << "\n";
    }


    return 0;
}