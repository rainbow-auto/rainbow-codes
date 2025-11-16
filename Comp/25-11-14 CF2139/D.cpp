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

constexpr int maxn = 500005;

int n, q;
int p[maxn], pos[maxn];

int L[maxn], R[maxn];

struct Query {
	int l;
	int id;
};

std::vector<Query> qry[maxn];
std::vector<int> tsk[maxn];

bool ans[maxn];

struct BIT {
	int tr[maxn];
	inline int lowbit(int x) {
		return (x) & (-x);
	}

	inline void mdf(int pos, int x) {
		for (int i = pos; i <= n; i += lowbit(i)) tr[i] += x;
	}

	inline int qry(int pos) {
		if (pos == 0) return 0;
		int res = 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}

	inline int qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}

	inline void clr() {
		rep (i, 1, n) tr[i] = 0; 
	}
} tr;

inline void clr() {
	tr.clr();
	rep (i, 1, n) std::exchange(tsk[i], {});
	rep (i, 1, n) std::exchange(qry[i], {});
	rep (i, 1, n) L[i] = R[i] = 0;
	rep (i, 1, q) ans[i] = false;
}

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) std::cin >> p[i];
	rep (i, 1, n) pos[p[i]] = i;

	std::set<int> s;
	rep (i, 1, n) {
		auto it = s.upper_bound(pos[i]);
		if (it != s.end()) R[i] = (*it);
		s.insert(pos[i]);
	}

	std::exchange(s, {});
	per (i, n, 1) {
		auto it = s.upper_bound(pos[i]);
		if (it != s.begin()) L[i] = (*std::prev(it));
		s.insert(pos[i]);
	}

	rep (id, 1, q) {
		int l, r; std::cin >> l >> r;
		qry[r].push_back({l, id});
	}

	rep (i, 1, n) {
		if (not (L[i] and R[i])) continue;
		tsk[R[i]].push_back(L[i]);
	}

	rep (r, 1, n) {
		for (auto l : tsk[r]) tr.mdf(l, 1);
		for (auto [l, id] : qry[r]) ans[id] |= tr.qry(l, n);
	}

	rep (id, 1, q) {
		if (ans[id]) std::cout << "NO\n";
		else std::cout << "YES\n";
	}

	clr();
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
