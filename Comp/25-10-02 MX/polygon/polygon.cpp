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

constexpr int maxn = 20;

int n, q;
int cnt[maxn];

std::set<int> g[maxn];

inline void op(int a, int b, int c, int d) {
    cnt[a]--; cnt[b]--;
    g[a].erase(b); g[b].erase(a);
    cnt[c]++; cnt[d]++;
    g[c].insert(d); g[d].insert(c);
}

int p;
int tot;
void calc(int now, int lim) {
    if (now > lim) {
        tot += g[p].size() == n - 3;
        return;
    }

    rep (a, 1, n) rep (b, 1, n) rep (c, 1, n) rep (d, 1, n) {
        op(a, b, c, d);
        calc(now + 1, lim);
        op(c, d, a, b);
    }
}

void solve() {
    std::cin >> n >> q;
    rep (i, 1, n - 3) {
        int u, v; std::cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        g[u].insert(v);
        g[v].insert(u);
    }

    while (q--) {
        int t; std::cin >> t;
        if (t == 1) {
            int a, b, c, d; std::cin >> a >> b >> c >> d;
            
        } else {
            std::cin >> p;
            std::cout << (n - 3 - cnt[p]) << " ";

            tot = 0;
            calc(0, n - 3 - cnt[p]);
            std::cout << tot << "\n";
        } 
    }
}

bool MemED;
int main() {
	fastread
	// lookMem	

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
