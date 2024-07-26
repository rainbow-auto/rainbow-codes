#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>

const int maxn = 200005;

int n;
int a[maxn];

inline int abs (int x) { return x > 0 ? x : -x; }

namespace Task1 {
    const int maxn = 25;
    
    int ans[maxn], w;

    int p[maxn];

    inline void solve () {
        for (int i = 1; i <= n; i++) { p[i] = i; }

        w = 0x3f3f3f3f;
        memset (ans, 0x3f, sizeof (ans));

        do {

            bool flag = true;
            for (int i = 1; i <= n - 1; i++) { flag &= ((a[p[i]] & 1) != (a[p[i + 1]] & 1)); }

            if (not flag) { continue; }
            
            int wnow = 0;
            for (int i = 1; i <= n; i++) { wnow += abs (i - p[i]); }

            if (wnow > w) { continue; }

            if (wnow == w) {
                for (int i = 1; i <= n; i++) {
                    if (a[p[i]] == a[ans[i]]) { continue; }
                    
                    if (a[p[i]] < a[ans[i]]) { memcpy (ans, p, sizeof (p)); break; }
                    else { break; }
                }
            } else {
                w = wnow;
                memcpy (ans, p, sizeof (p));
            }

        } while (std::next_permutation (p + 1, p + n + 1));

        for (int i = 1; i <= n; i++) { std::cout << a[ans[i]] << " "; } std::cout << "\n";
    }
}

int main () {

    fropen ("sequence.in", "r", stdin);
    fropen ("sequence.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    Task1::solve ();

    return 0;
}