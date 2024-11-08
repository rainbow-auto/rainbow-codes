#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;

#define endl "\n"

const int maxn = 105;
const int inf = 100;

const unsigned long long mod = 998244353ull;
const unsigned long long base = 233ull;

int n, Q;
int a[maxn];

namespace Get {

    struct BIT {
        int tr[maxn];
        
        inline int lowbit (int x) { return x & (-x); }

        inline void add (int pos, int val) {  for (int i = pos; i <= n; i += lowbit(i)) { tr[i] += val; } }
        inline int _query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit(i)) { res += tr[i]; } return res;  }

        inline int query (int l, int r) { if (l > r) { return 0; } else { return _query (r) - _query (l - 1); } }

        inline void clear () { memset (tr, 0, sizeof (tr)); }
    } tr;

    inline int getCnt () {
        tr.clear ();

        int ans = 0;
        for (int i = n; i >= 1; i--) {
            ans += tr.query (1, a[i] - 1);
            tr.add (a[i], 1); // 整体都加1
        }
        return ans;
    }

}

int a_new[maxn];

int ans[maxn];

int main () {

    cin >> n >> Q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    for (int t = 1; t <= Q; t++) {
        char op; cin >> op;

        if (op == '0') {
            int curr = 0; 
            memset (a_new, 0, sizeof (a_new));

            for (int i = 2; i <= n; i++) {
                a_new[++curr] = a[i];
            }
            a_new[++curr] = a[1];

            memcpy (a, a_new, sizeof (a_new));

            ans[t] = Get::getCnt ();

        } else if (op == '1') {
            std::reverse (a + 1, a + n + 1);
            
            ans[t] = Get::getCnt ();
        }
    }

    unsigned long long final_ans = 0ull;
    unsigned long long pow = 1ull;
    for (int i = Q; i >= 1; i--) {
        final_ans = (final_ans + 1ull * pow * ans[i]) % mod;
        pow = (pow * base) % mod;
    }

    cout << final_ans << endl;

    return 0;
}