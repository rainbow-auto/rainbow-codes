#include <iostream>

using namespace std;

const int maxn = 1005;

int a[maxn][maxn];

int n = 5;

inline int lowbit (int x) { return x & (-x); }
inline void _add (int i, int pos) { for (int j = pos; j <= n; j += lowbit(j)) { a[i][j] ++;  } }
inline void _sub (int i, int pos) { for (int j = pos; j <= n; j += lowbit(j)) { a[i][j] --;  } }
inline void add (int i, int l, int r) { _add(i, l); _sub(i, r + 1); }
inline int _query (int i, int pos) { int res = 0; for (int j = pos; j; j -= lowbit(j)) { res += a[i][j]; } return res; }
inline int query (int i, int l, int r) { return (r - l + 1) * _query(i, l) + (r - l + 1) * ( _query(i, r) - _query(i, l) ) / 2; }

int main () {

    add(1, 1, 4);
    add(1, 2, 5);

    for (int i = 1; i <= 5; i++) {
        cout << _query (1, i) << " ";
    } cout << endl;

    cout << query(1, 1, 5) << endl;

    return 0;
}