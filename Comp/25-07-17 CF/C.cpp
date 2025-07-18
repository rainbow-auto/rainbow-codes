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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;

int n, k;
int h[maxn];

void solve() {
	std::cin >> n >> k;

    rep (i, 1, n) std::cin >> h[i];
    int st = h[k];

    std::sort(h + 1, h + n + 1);
    n = std::unique(h + 1, h + n + 1) - h - 1;
    dbg(n);

    int id = 0;
    rep (i, 1, n) if (h[i] < st) id = i;
    id++;

    int cur = 1;
    rep (i, id, n - 1) {
        if (cur + h[i + 1] - h[i] - 1 > st) {
            return std::cout << "NO\n", void(0);
        } else {
            cur += h[i + 1] - h[i];
            st = h[i + 1];
            if (cur > st) return std::cout << "NO\n", void(0);
        }
    }

    std::cout << "YES\n";
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
