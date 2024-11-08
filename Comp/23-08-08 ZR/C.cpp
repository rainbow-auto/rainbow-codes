#include <iostream>

using namespace std;

int n, m, q;

#define int long long

namespace Task1 {
    const int maxn = 205;
        
    int a[maxn][maxn];

    inline void solve () {
        int lastans = 0;

        while (m--) {
            int opt; cin >> opt;
            int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
            
            x1 = (x1 + lastans) % n;
            x2 = (x2 + lastans) % n;
            y1 = (y1 + lastans) % n;
            y2 = (y2 + lastans) % n;

            if (opt == 1) {
                for (int i = x1; i <= x2; i++) {
                    for (int j = y1; j <= y2; j++) {
                        a[i][j] ++;
                    }
                }
            } else if (opt == 2) {
                int res = 0;

                for (int i = x1; i <= x2; i++) {
                    for (int j = y1; j <= y2; j++) {
                        res += a[i][j];
                    }
                }

                cout << res % q << endl;
                
                lastans = res;
            }
        }
    }
}   

int tr[maxn];
inline int lowbit (int x) { return x & (-x); }
inline void add (int pos, int x) { for (int i = pos; i <= n; i += lowbit(i)) { tr[i] += x } }
inline int query (int pos, int x) { int res = 0; for (int i = pos; i; i-= lowbit(i)) { res += tr[i]; } return res; } 

namespace Task2 {
    const int maxn = 3005;
        
    int a1[maxn][maxn];
    int a2[maxn][maxn];

    inline int lowbit (int x) { return x & (-x); }
    inline void _add1 (int i, int pos) { for (int j = pos; j <= n; j += lowbit(j)) { a1[i][j] += 1; } }
    inline void _add2 (int i, int pos) { for (int j = pos; j <= n; j += lowbit(j)) { a2[i][j] += pos * 1; } }
    inline void _sub1 (int i, int pos) { for (int j = pos; j <= n; j += lowbit(j)) { a1[i][j] -= 1; } }
    inline void _sub2 (int i, int pos) { for (int j = pos; j <= n; j += lowbit(j)) { a2[i][j] -= pos * 1; } }
    inline void add (int i, int l, int r) { _add1(i, l); _add2(i, l); _sub1(i, r + 1); _sub2(i, r + 1); }
    inline int _query (int i, int pos) { int res = 0; for (int j = pos; j; j -= lowbit(j)) { res += (pos + 1) * a1[i][j] - a2[i][j]; } return res; }
    inline int query (int i, int l, int r) { return _query(i, r) - _query(i, l - 1); }

    inline void solve () {
        int lastans = 0;

        while (m--) {
            // cout << "ok" << endl;
            
            int opt; cin >> opt;
            int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
            
            if (x1 > x2) { swap (x1, x2); }
            if (y1 > y2) { swap (y1, y2); }

            x1 = (x1 + lastans) % n;
            x2 = (x2 + lastans) % n;
            y1 = (y1 + lastans) % n;
            y2 = (y2 + lastans) % n;

			x1 ++; x2 ++; y1 ++; y2 ++;
			
            if (opt == 1) {
                for (int i = x1; i <= x2; i++) {
                    add(i, y1, y2);
                }
            } else if (opt == 2) {
                int res = 0;
                for (int i = x1; i <= x2; i++) {
                    res += query(i, y1, y2);
                }
                cout << res % q << endl;
                lastans = res;    
            }
        }
    }
}   

signed main () {

    cin >> n >> m >> q;

    // if (n <= 205 and m <= 205) {
        Task2::solve();
    // }

    return 0;
}
