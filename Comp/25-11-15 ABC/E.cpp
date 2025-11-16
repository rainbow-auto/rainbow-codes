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

constexpr int maxn = 500005;

int n, q; 
int a[maxn];

int N = 500000;
struct Tree {
	i64 tr[maxn];
	inline int lowbit(int x) {
		return x & (-x);
	}

	inline void mdf(int pos, i64 x) {
		pos++;
		for (int i = pos; i <= N + 1; i += lowbit(i)) tr[i] += x;
	}

	inline i64 qry(int pos) {
		i64 res = 0;
		pos++;
		if (not pos) return 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}

	inline i64 qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}
} tr1, tr2;

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n) {
		tr1.mdf(a[i], a[i]);
		tr2.mdf(a[i], 1);
	}
	
	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int x, y; std::cin >> x >> y;
			tr1.mdf(a[x], -a[x]);
			tr2.mdf(a[x], -1);
			a[x] = y;
			tr1.mdf(a[x], a[x]);
			tr2.mdf(a[x], 1);
		} else {
			i64 l, r; std::cin >> l >> r;
			if (l <= r) {
				i64 res = 0;
				res += tr2.qry(0, l - 1) * l;
				res += tr2.qry(r + 1, N) * r;
				res += tr1.qry(l, r);
				std::cout << res << "\n";
			} else {
				std::cout << 1ll * l * n << "\n";
			}
		}
	}
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
