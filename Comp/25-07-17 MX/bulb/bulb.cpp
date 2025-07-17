/*
追忆？？？？
*/

#include <bits/stdc++.h>
// #pragma GCC optimize(2)

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

constexpr int maxn = 50005;

int n, q, k;
int c[maxn];

namespace Subtask1 {
    std::bitset<maxn> b1[maxn];
    std::bitset<maxn> b01;

    inline void solve() {
        rep (i, 1, n) b1[c[i]][i] = 1;

        while (q--) {
            int x; std::cin >> x;
            b1[0] ^= b1[x];

            b01 = (~b1[0]) & (b1[0] >> 1);
            std::cout << b01.count() << "\n";
        }
    }
}

void solve() {
    std::cin >> n >> q >> k;
    rep (i, 1, n) std::cin >> c[i];

    Subtask1::solve();
}

bool MemED;
int main() {
	fastread
	lookMem	

    file("bulb")

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
