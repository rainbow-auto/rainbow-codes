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

namespace MilkDragon {
	constexpr int maxn = 100005;
	
	int n, m, q;
	
	struct ST {
		struct Node {
			int mn, mx;
			Node() {
				mn = 0x3f3f3f3f;
				mx = -0x3f3f3f3f;
			}
		} tr[maxn << 2]; 

		inline void pushUp(int now) {
			tr[now].mn = std::min(tr[now << 1].mn, tr[now << 1 | 1].mn);
			tr[now].mx = std::max(tr[now << 1].mx, tr[now << 1 | 1].mx);
		}

		void ins(int now, int l, int r, int pos, int v) {
			if (l == r) return tr[now].mn = std::min(tr[now].mn, v), tr[now].mx = std::max(tr[now].mx, v), void(0);
			int mid = (l + r) >> 1;
			if (pos <= mid) ins(now << 1, l, mid, pos, v);
			if (pos > mid) ins(now << 1 | 1, mid + 1, r, pos, v);
			pushUp(now);
		}
	
		i64 qrymn(int now, int l, int r, int L, int R) {
			if (L <= l and r <= R) return tr[now].mn;
			int mid = (l + r) >> 1;
			if (R <= mid) return qrymn(now << 1, l, mid, L, R);
			if (L > mid) return qrymn(now << 1 | 1, mid + 1, r, L, R);
			return std::min(qrymn(now << 1, l, mid, L, R), qrymn(now << 1 | 1, mid + 1, r, L, R));
		}

		i64 qrymx(int now, int l, int r, int L, int R) {
			if (L <= l and r <= R) return tr[now].mx;
			int mid = (l + r) >> 1;
			if (R <= mid) return qrymx(now << 1, l, mid, L, R);
			if (L > mid) return qrymx(now << 1 | 1, mid + 1, r, L, R);
			return std::max(qrymx(now << 1, l, mid, L, R), qrymx(now << 1 | 1, mid + 1, r, L, R));
		}
	} ta[2], tb[2];
	
	void solve() {
		std::cin >> n >> m >> q;
		rep (i, 1, n) {
			int x; std::cin >> x;
			if (x < 0) {
				ta[0].ins(1, 1, n, i, x);
			} else {
				ta[1].ins(1, 1, n, i, x);
			}
		}

		rep (i, 1, m) {
			int x; std::cin >> x;
			if (x < 0) {
				tb[0].ins(1, 1, m, i, x);
			} else {
				tb[1].ins(1, 1, m, i, x);
			}
		}

		while (q--) {
			int l1, r1; std::cin >> l1 >> r1;
			int l2, r2; std::cin >> l2 >> r2;
	
			std::vector<i64> a;
			a.push_back(ta[0].qrymn(1, 1, n, l1, r1)); a.push_back(ta[0].qrymx(1, 1, n, l1, r1));
			a.push_back(ta[1].qrymn(1, 1, n, l1, r1)); a.push_back(ta[1].qrymx(1, 1, n, l1, r1));
			std::vector<i64> b;
			b.push_back(tb[0].qrymn(1, 1, m, l2, r2)); b.push_back(tb[0].qrymx(1, 1, m, l2, r2));
			b.push_back(tb[1].qrymn(1, 1, m, l2, r2)); b.push_back(tb[1].qrymx(1, 1, m, l2, r2));
			
			// for (auto x : a) db << x << " "; dbendl;
			// for (auto x : b) db << x << " "; dbendl;

			i64 res = -1e18;
			for (auto x : a) {
				if (x == 0x3f3f3f3f or x == -0x3f3f3f3f) continue;
				i64 t = 1e18;
				for (auto y : b) {
					if (y == 0x3f3f3f3f or y == -0x3f3f3f3f) continue;
					t = std::min(t, x * y);
				}
				res = std::max(res, t);
			}

			std::cout << res << "\n";
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
		MilkDragon::solve();
	}

	return 0;
}
