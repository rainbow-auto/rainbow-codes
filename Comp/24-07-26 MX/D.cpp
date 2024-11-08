#include <iostream>

const int maxn = 200005;

int n, q, k;
int l[maxn];

namespace Task1 {

    bool on[maxn];

    int ans = 0;
    inline void upd () {
        ans = 0;
        bool lst = false;
        for (int i = 1; i <= n; i++) {
            if (not on[l[i]]) { ans += lst; lst = false; }
            else { lst = true; }
        }
        ans += lst;
    }

    inline void solve () {
        while (q--) {
            int c; std::cin >> c;
            on[c] ^= 1;
            upd ();
            std::cout << ans << "\n";
        }        
    }    
}

int main () {

    freopen ("light.in", "r", stdin);
    freopen ("light.out", "w", stdout);

    std::cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) { std::cin >> l[i]; }

    Task1::solve ();

    return 0;
}