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
int a[maxn];

struct Range {
    int l, r;
    int x;

    friend bool operator < (Range a, Range b) {
        return a.x < b.x;
    }
} rs[maxn];

void solve() {
    std::cin >> n >> k;
    rep (i, 1, n) {
        int l, r; std::cin >> l >> r;
        int x; std::cin >> x;
        rs[i] = Range { l, r, x };
    }

    std::sort(rs + 1, rs + n + 1);

    int cur = k;
    rep (i, 1, n) {
        if (rs[i].l <= cur and cur <= rs[i].r) {
            cur = std::max(cur, rs[i].x);
        }
    }

    std::cout << cur << "\n";
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
