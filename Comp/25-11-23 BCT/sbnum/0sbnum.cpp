// 这下知道 T1 为啥叫 sbnum 了。

#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++) 
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--) 
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";

using i64 = long long;

constexpr int maxn = 100005;

std::string s;
int n;
i64 k;

namespace Sol {
    struct Tree {
        int tr[maxn];

        inline int lowbit(int x) {
            return x & (-x);
        }

        inline int qry(int pos) {
            int res = 0;
            for (int i = pos; i; i -= lowbit(i)) res += tr[i];
            return res;
        }

        inline void mdf(int pos, int v) {
            for (int i = pos; i <= n; i += lowbit(i)) tr[i] += v;
        }

        inline void clr() {
            rep (i, 1, n) tr[i] = 0;
        }
    } tr;

    inline void solve() {
        n = s.size();
        s = " " + s;

        std::array<std::vector<int>, 10> pos;

        per (i, n, 1) pos[s[i] - '0'].push_back(i);

        tr.clr();
        rep (i, 1, n) tr.mdf(i, 1);

        rep (i, 1, n) {
            bool flg = false;
            rep (c, 1, 9) {
                if (not pos[c].empty()) {
                    int x = pos[c].back();
                    int cnt = tr.qry(x) - 1;
                    if (k >= cnt) {
                        std::cout << c;
                        k -= cnt;
                        tr.mdf(x, -1);
                        pos[c].pop_back();
                        flg = true;
                        break;
                    }
                }
            }
            assert(flg);
        }

        std::cout << "\n";
    }
}

inline void solve() {
    std::cin >> s >> k;
    
    Sol::solve();
}

int main() {
    fastread

    // file("sbnum")

    int _; std::cin >> _;
    while (_--) solve();

    return 0;
}