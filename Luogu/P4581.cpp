#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

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

constexpr int maxn = 1000005;

int n, m;
std::pair<int, int> a[maxn];

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

f64 w[maxn];
f64 s[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, m + 1, n) std::cin >> a[i].first >> a[i].second;
	
	int V = 1e8;
	int C = 120;
	rep (t, 1, C) {
		rep (i, 1, m) w[i] = 1.0 * (rng() % V) / V;
		rep (i, m + 1, n) w[i] = std::min(w[a[i].first], w[a[i].second]);
		rep (i, m + 1, n) s[i] += 1.0 * w[i] / C;
	}

	rep (i, m + 1, n) std::cout << std::round(1.0 / s[i] - 1) << "\n";
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
