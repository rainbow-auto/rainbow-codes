#include <iostream>
#include <string>

const int maxn = 1005;

int n, k;

std::string s[maxn];

int main () {

    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) { std::cin >> s[i]; }

    int res = 1;
    int len_now = 0;

    for (int i = 1; i <= n; i++) {
        if (len_now + s[i].size () <= k) { len_now += s[i].size () + 1; continue; }
        res ++;
        len_now = s[i].size () + 1;
    }

    std::cout << res << "\n";

    return 0;
}