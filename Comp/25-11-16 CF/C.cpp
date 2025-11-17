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

constexpr int maxn = 400005;
constexpr int inf = 0x3f3f3f3f;

int n;
int a[maxn];
int pre[maxn], nxt[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> a[i];
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}	
	pre[1] = n;
	nxt[n] = 1;
	
	auto f = [&](int i) {
		int c = inf;
		if (a[i] <= a[nxt[i]]) c = std::min(c, a[nxt[i]]);
		if (a[i] <= a[pre[i]]) c = std::min(c, a[pre[i]]);
		return c;
	};

	i64 ans = 0;
	std::set<std::pair<int, int>> s;
	rep (i, 1, n) {
		s.insert({f(i), i});
	}

	int tot = n;
	while (tot > 1) {
		int x = (*s.begin()).second; s.erase(s.begin());
		// dbg(x);

		ans += f(x);
		tot--;

		if (tot == 1) break;

		int l = pre[x];
		int r = nxt[x];
		s.erase({f(l), l});
		s.erase({f(r), r});

		nxt[l] = r;
		pre[r] = l;

		s.insert({f(l), l});
		s.insert({f(r), r});
	}

	std::cout << ans << "\n";

	// db << "--------\n";
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
