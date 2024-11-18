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

const int maxn = 100005;

int n, q;
int p[maxn], t[maxn], w[maxn];

namespace Task1 {
	inline void solve() {
		while (q--) {
			f64 L; std::cin >> L;
			f64 ans = 1e18;
			rep (S, 0, (1 << n) - 1) {
				i64 sum = 0;
				f64 cur = 0;
				f64 lst = L;
				per (i, n, 0) {
					if (p[i] > L) continue;
					cur += lst - p[i]; lst = p[i];
					if (i == 0) break;
					if (S & (1 << (i - 1))) {
						cur /= w[i];
						sum += t[i];
					}
				}
				ans = std::min(ans, cur + sum);
			}

			std::printf("%.10lf\n", ans);
		}
	}
}

namespace Task2 {
	inline void solve() {
		while (q--) {
			f64 L; std::cin >> L;
			f64 ans = 1e18;
			rep (S, 0, (1 << n) - 1) {
				f64 cur = L;
				f64 v = 1;
				rep (i, 1, n) {
					if (p[i] > L) continue;
					if (S & (1 << (i - 1))) {
						// cur -= (L - p[i]) / v - (L - p[i]) / (v * w[i]);
						// cur += -(L - p[i]) / v + (L - p[i]) / (v * w[i]);
						// cur += t[i];
						cur += -1.0 * (L - p[i]) / v * (w[i] - 1) / w[i] + t[i];
						v *= w[i];
					}
				}
				ans = std::min(ans, cur);
			}

			std::printf("%.10lf\n", ans);
		}
	}
}

namespace Task3 {
	f64 c[maxn];

	f64 pw2[maxn], pw3[maxn];
	inline f64 calc(int i, int u, int v) {
		return -c[i] / pw2[u] / pw3[v] + t[i];
	}

	const f64 eps = 1e-15;

	struct Node {
		f64 c;
		f64 t;
		int w;
		friend bool operator < (Node a, Node b) {
			if (a.t - a.c != b.t - b.c) return a.t - a.c > b.t - b.c;
			return a.w > b.w;
		}
	};

	inline void solve() {
		pw2[0] = 1; rep (i, 1, 50) pw2[i] = pw2[i - 1] * 2.0;
		pw3[0] = 1; rep (i, 1, 40) pw3[i] = pw3[i - 1] * 3.0;

		while (q--) {
			f64 L; std::cin >> L;

			rep (i, 1, n) if (p[i] <= L) c[i] = 1.0 * (L - p[i]) * (w[i] - 1) / w[i];

			f64 ans = L;
			std::priority_queue<Node> q;
			rep (i, 1, n) q.push(Node { c[i], t[i], w[i] });

			while (not q.empty()) {
				auto x = q.top(); q.pop();
				if (x.t - x.c > eps) break;
				ans += x.t - x.c;
				
				db << x.t << " " << x.c << " " << x.w << "\n";

				std::vector<Node> upd;
				while (not q.empty()) upd.push_back(Node { q.top().c / x.w, q.top().t, q.top().w }), q.pop();
				for (auto i : upd) q.push(i);
			}

			std::printf("%.10lf\n", ans);
		}
	}
}

void solve() {
	int _n; std::cin >> _n;
	std::cin >> q;
	rep (i, 1, _n) {
		n++;
		std::cin >> p[n] >> t[n] >> w[n];
		if (w[n] == 1) n--;
	}

	Task2::solve();
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
