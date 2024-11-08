#include <iostream>
#include <algorithm>
#include <vector>

using i64 = long long;

const int maxn = 1000005;

int n;
int a[maxn];

namespace Task1 {
    std::vector<int> vec;
    inline void solve () {
        for (int i = 1; i <= n; i++) {
            vec.push_back (a[i]);
            std::reverse (vec.begin (), vec.end ());
        }

        for (auto now : vec) { std::cout << now << " "; }
        std::cout << "\n";
    }
}

namespace Task2 {
    int ans[maxn << 1];

    inline void solve () {
        int lpos = n;
        int rpos = n;

        ans[n] = a[1];

        bool rev = false;
        for (int i = 2; i <= n; i++) {
            if (i & 1) {
                ans[++rpos] = a[i];
            } else {
                ans[--lpos] = a[i];
            }

            rev ^= 1;
        }

        if (rev) {
            for (int i = lpos; i <= rpos; i++) { std::cout << ans[i] << " "; } std::cout << "\n";
        } else {
            for (int i = rpos; i >= lpos; i--) { std::cout << ans[i] << " "; } std::cout << "\n";
        }
    }
}

int main () {

    freopen ("reverse.in", "r", stdin);
    freopen ("reverse.ans", "w", stdout);

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    Task2::solve ();

    return 0;
}