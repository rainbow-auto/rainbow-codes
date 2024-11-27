// 错完了
// 摆了

#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++)
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << " : " << (x) << "\n"; 
#define dbendl std::cerr << "\n";

using i64 = long long;
using f64 = double;

const int maxn = 2000005;
const int mod = 998244353;

int n;
int a[maxn];

namespace Solution {

    struct DS {
        int cnt[maxn];
        int col;

        inline void ins(int x) {
            if (not cnt[x]) col++;
            cnt[x]++;
        }

        inline void del(int x) {
            cnt[x]--;
            if (not cnt[x]) col--;
        }
    } ds;

    int f[maxn];

    inline void solve() {
        int L = 0;
        int sum = 0;
        f[0] = 1;
        rep (i, 1, n) {
            dbg(i);
            ds.ins(a[i]);
            (sum += f[i - 1]) %= mod;

            db << "L: " << L << "\n";
            dbg(ds.col);

            while (L <= i and ds.col > 4) {
                ds.del(a[L]);
                (((sum -= f[L - 1]) %= mod) += mod) %= mod;
                L++;
            }
            if (ds.col == 4) f[i] = sum;
            dbg(f[i]);

            dbendl;
        }

        std::cout << f[n] << "\n"; 
    }
}

int main() {

    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];

    Solution::solve();

    return 0;
}