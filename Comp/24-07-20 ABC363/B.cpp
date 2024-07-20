#include <iostream>

const int maxn = 1005;

int n, t, p;
int a[maxn];

int main () {

    std::cin >> n >> t >> p;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    int day = 0;
    while (true) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) { cnt += (a[i] >= t); }

        if (cnt >= p) { break; }

        day ++;
        t--;
    }

    std::cout << day << "\n";

    return 0;
}