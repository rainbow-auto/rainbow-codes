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

int n;
int a[2][maxn];

using info = std::pair<int, int>;
info pre[maxn], suf[maxn];

info operator + (info a, info b) {
	return info {std::min(a.first, b.first), std::max(a.second, b.second)};
}

std::vector<int> L[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[0][i];
	rep (i, 1, n) std::cin >> a[1][i];	

	pre[0] = {0x3f3f3f3f, 0};
	rep (i, 1, n) pre[i] = pre[i - 1] + info {a[0][i], a[0][i]};
	suf[n + 1] = {0x3f3f3f3f, 0};
	per (i, n, 1) suf[i] = suf[i + 1] + info {a[1][i], a[1][i]};

	rep (i, 1, n) {
		info cur = pre[i] + suf[i];
		L[cur.second].push_back(cur.first);
	}

	i64 ans = 0;
	std::set<int> ls;
	rep (r, 1, (n << 1)) {
		for (auto l : L[r]) {
			ls.insert(l);		
		}
		if (not ls.empty()) ans += *ls.rbegin();
	} 

	std::cout << ans << "\n";

	rep (i, 1, (n << 1)) std::exchange(L[i], {});
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
