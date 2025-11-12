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

constexpr int maxn = 3000005;

int n, q;
int L[maxn], R[maxn];

inline int query(int l, int r) {
	std::cout << "? " << l << " " << r << std::endl;
	int x; std::cin >> x;
	return x;
}

void solve() {
	std::cin >> n >> q;

	rep (i, 1, n) R[i] = 0;
	
	rep (t, 1, q) {
	 	int l, r; std::cin >> l >> r;
		R[l] = std::max(R[l], r);
	}
	
	std::vector<std::pair<int, int>> qry;
	int lst = 0;
	rep (i, 1, n) {
		if (R[i] > lst) {
			lst = R[i];
			qry.push_back({i, R[i]});
		}
	}

	// for (auto [l, r] : qry) db << l << ' ' << r << "\n"; dbendl;

	int l = 0, r = qry.size() - 1;
	int pos = qry.size() - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		auto [ql, qr] = qry[mid];
		int pre = query(ql, n);
		int suf = query(1, qr);

		if (pre < suf) {
			r = mid - 1;
			pos = mid;
		} else {
			l = mid + 1;
		}
	}

	dbg(pos);

	int ans = 0;
	if (pos < qry.size()) {
		ans = std::max(ans, query(qry[pos].first, qry[pos].second));
	}

	if (pos > 0) {
		ans = std::max(ans, query(qry[pos - 1].first, qry[pos - 1].second));
	}

	std::cout << "! " << ans << std::endl;
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
