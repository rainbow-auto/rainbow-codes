#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1000005;

int n;
int a[maxn];

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    std::vector<int> ord;
    for (int i = 1; i <= n; i++) { ord.push_back (i); }

    int ans = 1e9;

    do {
        int ansnow = -1e9;
        for (int i = 0; i + 1 < ord.size (); i++) {
            ansnow = std::max (ansnow, a[ord[i]] - a[ord[i + 1]]);
        }

        ans = std::min (ans, ansnow);
    } while (std::next_permutation (ord.begin (), ord.end ()));

    std::cout << ans << "\n";

    return 0;
}