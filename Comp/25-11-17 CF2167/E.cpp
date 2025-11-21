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

constexpr int maxn = 200005;

int n, k, x;
i64 a[maxn];

inline bool chk(i64 len) {
	int cur = k;
	// [0, a[1] - len]
	cur -= std::max(0ll, a[1] - len + 1);
	rep (i, 2, n) {
		// [a[i - 1] + len, a[i] - len]
		cur -= std::max(0ll, a[i] - len - (a[i - 1] + len) + 1);
		if (cur <= 0) return true;
	}
	// [a[n] + len, x]
	cur -= std::max(0ll, x - (a[n] + len) + 1);
	if (cur <= 0) return true;
	return false;
}

std::set<i64> ans;
inline void output(i64 len) {
	std::exchange(ans, {});
	int cur = k;
	rep (j, 0, a[1] - len) {
		ans.insert(j);
		if (ans.size() >= k) return; 
	}
	
	rep (i, 2, n) {
		rep (j, a[i - 1] + len, a[i] - len) {
			ans.insert(j);
			if (ans.size() >= k) return; 
		}
	}
	
	rep (j, a[n] + len, x) {
		ans.insert(j);
		if (ans.size() >= k) return; 
	}

	assert(0);
}

void solve() {
	std::cin >> n >> k >> x;
	rep (i, 1, n) std::cin >> a[i];

	std::sort(a + 1, a + n + 1);

	i64 l = 0, r = x;
	i64 res = -1;

	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (chk(mid)) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}

	output(res);
	for (auto t : ans) std::cout << t << " "; 

	std::cout << "\n";
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
