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

const int maxn = 100005;

int n;

struct Line {
	int x1, x2;
	int y1, y2;

	f64 k, b;

	inline void norm() {
		if (x1 > x2) std::swap(x1, x2), std::swap(y1, y2);
	}

	inline void init() {
		norm();
		k = f64 { 1.0 * (y2 - y1) / (x2 - x1) };
		b = f64 { 1.0 * y1 - k * x1 };
	}

	inline f64 get(f64 x) {
		return k * x + b;
	}
} a[maxn];

double X, Y;

const f64 inf = 2e9;

void solve() {
	std::cin >> n >> X;
	rep (i, 1, n) std::cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;

	rep (i, 1, n) a[i].init();

	Y = inf;
	while (true) {
		std::pair<f64, int> mx = std::make_pair(-inf, 0);

		rep (i, 1, n) {
			if ((a[i].x1 < X and X < a[i].x2) and Y >= a[i].get(X)) mx = std::max(mx, std::make_pair(a[i].get(X), int{i}));
		}

		if (mx.first == -inf) break;

		int id = mx.second;
		if (a[id].y1 > a[id].y2) X = a[id].x2, Y = a[id].y2;
		else X = a[id].x1, Y = a[id].y1;
	}

	std::cout << int { X } << "\n";
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
