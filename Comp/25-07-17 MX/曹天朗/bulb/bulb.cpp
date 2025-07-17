/*
追忆？？？？
*/

#include <bits/stdc++.h>
#pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;
constexpr int B = 355;

int n, q, k;
int c[maxn];

namespace Solution {
    std::bitset<maxn> b1[maxn / B];
    std::bitset<maxn> b1_r[maxn / B];
    std::bitset<maxn> b0[maxn / B];
    int siz[maxn];

    int bel[maxn], tot;

    std::vector<int> pos[maxn];

    inline void solve() {
        rep (i, 1, n) siz[c[i]]++;

        rep (i, 1, k) {
            if (siz[i] > B) {
                ++tot;
                bel[i] = tot;
            }
        }

        rep (i, 1, n) if (bel[c[i]]) b1[bel[c[i]]][i] = 1;
        rep (i, 1, tot) b0[i] = ~b1[i];
        b0[0] = ~b1[0];
        rep (i, 1, tot) b1_r[i] = b1[i] >> 1;

        rep (i, 1, n) if (not bel[c[i]]) pos[c[i]].push_back(i);

        assert(tot < maxn / B);

        while (q--) {
            int x; std::cin >> x;
            if (bel[x]) {
                b1[0] ^= b1[bel[x]];
                b0[0] ^= b0[bel[x]];
                b1_r[0] ^= b1_r[bel[x]];
            } else {
                for (auto p : pos[x]) {
                    b1[0][p] = b1[0][p] ^ 1;
                    b0[0][p] = b0[0][p] ^ 1;
                    b1_r[0][p - 1] = b1_r[0][p - 1] ^ 1;
                }
            }

            std::cout << (b0[0] & b1_r[0]).count() << "\n";
        }
    }
}

void solve() {
    std::cin >> n >> q >> k;
    rep (i, 1, n) std::cin >> c[i];

    Solution::solve();
}

bool MemED;
int main() {
	fastread
	lookMem	

    file("ex_bulb4")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

    lookTime

	return 0;
}
