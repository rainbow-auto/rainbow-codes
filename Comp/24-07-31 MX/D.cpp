#include <iostream>

const int maxn = 100005;

int n;
int a[maxn];

namespace Sub1 {
    inline void solve () {
        for (int i = 1; i <= n; i++) {
            int mn_pos = i;

            for (int j = i; j <= n; j++) {
                if ((a[i] & a[j]) == 0) { 
                    if (a[j] < a[mn_pos]) { mn_pos = j; }
                }
            }

            std::swap (a[i], a[mn_pos]);
        }

        for (int i = 1; i <= n; i++) { std::cout << a[i] << " "; } std::cout << "\n";
    }
}

int main () {

    freopen ("seq.in", "r", stdin);
    freopen ("seq.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    Sub1::solve ();

    return 0;
}