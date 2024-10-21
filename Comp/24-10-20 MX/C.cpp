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
// #define MultiTask lovely_fairytale

const int maxn = 300005;

int n, q;
int c1, w1;
int c2, w2;
i64 a[maxn];

namespace TaskA {
	struct BIT {
		i64 tr[maxn];
		inline int lowbit(int x) { return x & -x; }

		inline void add(int pos, i64 val) {
			for (int i = pos; i <= n; i += lowbit(i)) tr[i] += val;
		}

		inline i64 qry(int pos) {
			i64 res = 0;
			for (int i = pos; i; i -= lowbit(i)) res += tr[i];
			return res;
		}

		inline i64 qry(int l, int r) {
			return qry(r) - qry(l - 1);
		}
	} tr;

	inline bool chk(int l, int r) {
		return (c1 >= r - l + 1) and (tr.qry(l, r) < w1);
	}

	inline void solve() {
		rep (i, 1, n) tr.add(i, a[i]);
		
		while (q--) {
			int op; std::cin >> op;
			if (op == 1) {
				int pos, x; std::cin >> pos >> x;
				tr.add(pos, x);

			} else {
				int l, r; std::cin >> l >> r;

				if (chk(l, r)) std::cout << "cont\n";
				else std::cout << "tetris\n";
			}
		}
	}
}


void solve() {
	std::cin >> n >> q >> c1 >> c2 >> w1 >> w2;

	rep (i, 1, n) std::cin >> a[i];

	// if (c2 > n and w1 == 0) TaskA::solve();
	TaskA::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
