#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 500005;

int n, q;
int a[maxn];
int ops[maxn], L[maxn], R[maxn];

namespace Task1 {
    int tag[maxn];
   
    inline void solve () {
        memset (tag, -1, sizeof (tag));
        for (int i = 1; i <= n; i++) { a[i] = 500000; }

        for (int opnow = 1; opnow <= q; opnow ++) {
            int op = ops[opnow], l = L[opnow], r = R[opnow];

            switch (op) {
                case 1:
                    for (int i = l; i <= r; i++) { a[i] ++; }
                    break;
                case 2:
                    for (int i = l; i <= r; i++) { a[i] --; if (tag[i] > a[i]) { tag[i] = -1; } }
                    break;
                case 3:
                    for (int i = l; i <= r; i++) { tag[i] = a[i]; }
                case 4:
                    for (int i = l; i <= r; i++) { a[i] = tag[i] == -1 ? a[i] : tag[i]; tag[i] = -1; }
                    break;
                case 5:
                    cout << a[l] << endl;
                    break;
            }
        }
    }
}

namespace Task2 {
    struct BIT {
        int tr[maxn];

        inline int lowbit (int x) { return x & (-x); }

        inline void _add (int pos, int val) { for (int i = pos; i <= n; i += lowbit (i)) { tr[i] += val; } }
        inline void add (int l, int r, int val) { _add (l, val); _add (r + 1, -val); }

        inline int query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit(i)) { res += tr[i]; } return res; }
    } t;

    inline void solve () { 
        t.add (1, n, 500000);
        for (int opnow = 1; opnow <= q; opnow ++) {
            int op = ops[opnow], l = L[opnow], r = R[opnow];
            
            switch (op) {
                case 1:
                    t.add (l, r, 1);
                    break;
                case 2:
                    t.add (l, r, -1);
                    break;
                case 5:
                    cout << t.query (l) << endl;
                    break;
            }
        }
    }
}

int main () {

    cin >> n >> q;

    bool Task2Flag = true;
    for (int i = 1; i <= q; i++) { cin >> ops[i] >> L[i] >> R[i]; Task2Flag &= ops[i] != 3 && ops[i] != 4; }


    if (Task2Flag) { Task2::solve (); }
    else { Task1::solve (); }

    return 0;
}