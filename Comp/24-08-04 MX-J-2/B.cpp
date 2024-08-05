#include <iostream>

const int maxn = 1000005;

int n;
int a[maxn];

int main () {

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    bool flag = true;
    for (int i = 1; i <= n - 1; i++) { flag &= (a[i] == a[i + 1]); }

    if (flag) { std::cout << "0\n"; }
    else { std::cout << n - 1 << "\n"; }

    return 0;
}