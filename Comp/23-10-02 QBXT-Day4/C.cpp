#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 100005;

string s;
int n, m, p;
long long a[maxn];

struct Query {
    int op;
    long long x, y;
};
vector<Query> qs;

namespace Task1 { // 暴力

    inline void solve () {
        int curr = 0;

        for (auto q : qs) {
            if (q.op == 1) {
                a[q.x] = q.y;
            } else if (q.op == 2) {
                int res = 0;

                for (int l = q.x; l <= q.y; l++) {
                    int last = 0;
                    for (int r = l; r <= q.y; r++) {
                        last = (last * 10ll % p + a[r] % p) % p;

                        if (last == 0) { res ++; }
                    }
                }                

                cout << res << endl;
            }
        }
    }

}

namespace Task2 { // 不带修
    inline void solve () {

    }
}

namespace Task3 { // p == 2
    
    struct BIT {
        int tr[maxn];

        inline int lowbit (int x) { return x & (-x); }

        inline void add (int pos, int val) { for (int i = pos; i <= n; i += lowbit (i)) { tr[i] += val; } }

        inline int _query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }
        inline int query (int l, int r) { return _query (r) - _query (l - 1); }
    } tr1, tr2;


    inline void solve () {
        
        for (int i = 1; i <= n; i++) {
            if (a[i] % 2 == 0) { tr1.add (i, 1); tr2.add (i, i); }
        }

        for (auto q : qs) {
            if (q.op == 1) {
                int old_a = a[q.x]; a[q.x] = q.y;

                if (old_a % 2 != 0 and a[q.x] % 2 == 0) { tr1.add (q.x, 1); tr2.add (q.x, q.x); }

            } else if (q.op == 2) {
                int res = tr2.query (q.x, q.y) - tr1.query (q.x, q.y) * (q.x - 1);
                cout << res << endl;
            }
        }

    }

}

int main () {

    freopen ("eat.in", "r", stdin);
    freopen ("eat.out", "w", stdout);

    string s; cin >> s;
    n = s.size ();
    for (int i = 1; i <= n; i++) { a[i] = s[i - 1] - '0'; }

    cin >> p >> m;

    bool Task2Flag = true;
    while (m --) {
        int op; cin >> op;
        int x, y; cin >> x >> y;

        qs.push_back ( Query { op, x, y } );
        Task2Flag &= (op != 2);
    }

    if (n <= 100 and m <= 100) { Task1::solve (); }
    else if (Task2Flag) { Task2::solve (); }
    else if (p == 2) { Task3::solve (); }

    return 0;
}