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

int main () {

    // freopen ("reverse.in", "r", stdin);
    // freopen ("reverse_task1.ans", "w", stdout);

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    Task1::solve ();

    return 0;
}