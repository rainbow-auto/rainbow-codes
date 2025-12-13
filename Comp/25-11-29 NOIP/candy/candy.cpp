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

constexpr int maxn = 100005;

int n;
i64 m;
std::pair<i64, i64> a[maxn];

void solve() {
    std::cin >> n >> m;
    rep (i, 1, n) std::cin >> a[i].first >> a[i].second;
    std::sort(a + 1, a + n + 1);
    
    i64 mn = 1e18;
    rep (i, 1, n) mn = std::min(mn, a[i].first + a[i].second);

    i64 ans = (m / mn) * 2ll;
    i64 rst = m;

    rep (i, 1, n) {
        rst -= a[i].first;
        if (rst < 0) break;
        ans = std::max(ans, i + (rst / mn) * 2ll);
    }

    std::cout << ans << "\n";
}   

bool MemED;
int main() {
	fastread
	// lookMem	

    file("candy")

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
