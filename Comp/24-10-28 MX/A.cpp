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

const int maxn = 200005;

int n, Q;
i64 L, R;
i64 a[maxn];

struct Op {
	int op;
	i64 x, s, t;
} qs[maxn];

namespace Task1 {
	inline void solve() {
		rep (_, 1, Q) {
			auto qcur = qs[_];
			if (qcur.op == 1) {
				rep (i, 1, n) {
					if (a[i] >= qcur.x) {
						a[i] += qcur.s;
						a[i] *= qcur.t;
					}
				}
			} else {
				rep (i, 1, n) {
					if (a[i] <= qcur.x) {
						a[i] -= qcur.s;
						a[i] /= qcur.t;
					}
				}
			}
		}

		int ans = 0;
		rep (i, 1, n) ans += L <= a[i] and a[i] <= R;
		std::cout << ans << "\n";
	}
}

namespace Task2 {
	struct Tree {
		struct Node {
			i64 sum;
			int tag;
		} tr[maxn << 2];
	};

	inline void solve() {
		
	}
}

void solve() {
	std::cin >> n >> Q >> L >> R;
	rep (i, 1, n) std::cin >> a[i];
	
	bool Task2flg = true;
	rep (i, 1, Q) {
		std::cin >> qs[i].op >> qs[i].x >> qs[i].s >> qs[i].t;
		Task2flg &= qs[i].op == 1;
	}

	if (Task2flg) Task2::solve();
	else Task1::solve();
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
