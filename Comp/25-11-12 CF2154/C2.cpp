#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
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

constexpr int maxn = 200005;

int n;

struct Node {
	int a;
	i64 b;
} a[maxn];

std::vector<int> ps[maxn];
inline void sieve(int N) {
	rep (i, 2, N) {
		if (not ps[i].empty()) continue;
		for (int j = i; j <= N; j += i) ps[j].push_back(i);
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i].a;
	rep (i, 1, n) std::cin >> a[i].b;

	std::sort(a + 1, a + n + 1, [](Node i, Node j) -> bool {
		return i.b < j.b;
	});

	i64 ans = 1e18;
	std::array<std::map<int, i64>, 2> f = {};
	rep (i, 1, n) {
		int x = a[i].a;
		rep (t, 0, 1) {
			for (auto p : ps[x]) {
				if (f[t].count(p)) ans = std::min(ans, f[t][p] * t);
			}
		}
	
		rep (t, 0, 1) {
			for (auto p : ps[x + 1]) {
				if (f[t].count(p)) ans = std::min(ans, a[i].b + f[t][p] * t);
			}
		}

		for (auto p : ps[x]) {
			if (not f[0].count(p)) f[0][p] = a[i].b;
		}
		for (auto p : ps[x + 1]) {
			if (not f[1].count(p)) f[1][p] = a[i].b;
		}
	}

	rep (i, 2, n) for (auto p : ps[a[i].a]) {
		ans = std::min(ans, a[1].b * ((p - a[1].a % p) % p));
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

	sieve(200001);

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
