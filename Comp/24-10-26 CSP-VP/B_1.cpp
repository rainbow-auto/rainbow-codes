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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale

const int maxn = 100005;

int n, m, L;
i64 V;
i64 p[maxn];

struct Node {
	int st;
	i64 v, a;
} a[maxn];

inline i64 calc(int id, i64 S) {
	if (S < 0) return -1e18;
	i64 x = 1ll * a[id].v * a[id].v + 2ll * a[id].a * S; 
	if (x < 0) return -1e18;
	return x;
}

inline int getR(int id, int st) {
	int l = st, r = m;
	int res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (calc(id, p[mid] - a[id].st) > V) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}
	return res;
}

inline int getL(int id, int ed) {
	int l = 1, r = ed;
	int res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (calc(id, p[mid] - a[id].st) > V) {
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

void solve() {

	std::cin >> n >> m >> L >> V;
	V *= V;
	rep (i, 1, n) std::cin >> a[i].st >> a[i].v >> a[i].a;
	rep (i, 1, m) std::cin >> p[i];

	std::vector<std::pair<int, int>> rgs;

	rep (i, 1, n) {
		if (a[i].a >= 0) {
			int ed = m;
			if (not (calc(i, p[ed] - a[i].st) > V)) continue;
			int st = getL(i, ed);
			if (not ~st) continue;
			rgs.push_back(std::make_pair(st, ed));
			// db << "i: " << i << " | " << st << " " << ed << "\n";
		} else {
			int st = std::lower_bound(p + 1, p + m + 1, a[i].st) - p;
			if (not (calc(i, p[st] - a[i].st) > V)) continue;
			int ed = getR(i, st);
			if (not ~ed) continue;
			rgs.push_back(std::make_pair(st, ed));
			// db << "i: " << i << " | " << st << " " << ed << "\n";
		}
	}

	std::sort(rgs.begin(), rgs.end(), [](std::pair<int, int> x, std::pair<int, int> y) -> bool {
		if (x.second != y.second) return x.second < y.second;
		return x.first < y.first;
	});

	int lst = -1;
	int ans = 0;

	for (auto rg : rgs) {
		int l, r; std::tie(l, r) = rg;
		if (l <= lst and lst <= r) continue;
		ans++; lst = r;
	}

	std::cout << rgs.size() << " " << m - ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();
	
	// std::freopen("detect5.in", "r", stdin);
	// std::freopen("detect.out", "w", stdout);

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
