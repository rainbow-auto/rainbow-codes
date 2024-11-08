#include <iostream>
#include <set>

using i64 = long long;

const int maxn = 10000005;

i64 x, m, k;

i64 a[maxn][2], tot;
bool curr;

int main () {
    
    freopen ("trans.in", "r", stdin);
    freopen ("trans.out", "w", stdout);

    std::cin >> x >> k >> m;

    a[++tot][curr] = x;

    while (k--) {
        bool flag = false;

        int lastsiz = tot; tot = 0;
        for (int i = 1; i <= lastsiz; i++) {
            std::set <i64> ds;
            for (i64 t = 1; t * t <= a[i][curr]; t++) {
                if (a[i][curr] % t == 0) { 
                    ds.insert (t); 
                    if (a[i][curr] / t != t) { ds.insert (a[i][curr] / t); }
                }
            }

            if (ds.size () != 2) { flag = true; }

            for (auto now : ds) { 
                a[++tot][curr ^ 1] = now; 
                if (tot >= m) { break; }
            }
        }
        curr ^= 1;

        if (not flag) { break; }
    }

    k++;

    i64 sum = 0;
    for (int i = 1; i <= m; i++) { 
        if (a[i][curr] == 1) { 
            sum ++; 
        } else {
            if (i + k > m) { sum += (m - i + 1); break; }
            sum += k;
            sum += a[i][curr]; 
            i += k;
        }
    }

    std::cout << sum << "\n";

    return 0;
}