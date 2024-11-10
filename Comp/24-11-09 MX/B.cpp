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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 1000005;

int n, m;
struct Goods {
	int a, b;
} a[maxn];

struct Ticket {
	int w, v;
} c[maxn];

// namespace Task0 {
// 	i64 dt[maxn];

// 	inline void solve() {
// 		i64 sum = 0;
// 		rep (i, 1, n) sum += b[i];
// 		std::sort(c + 1, c + m + 1, [](Node a, Node b) {return a.v > b.v;});
// 		rep (i, 1, n) dt[i] = -b[i] + a[i];
// 		std::sort(dt + 1, dt + n + 1);

// 		i64 mn = sum;
// 		rep (i, 1, n) {
// 			sum = sum + dt[i] - c[i].v;
// 			mn = std::min(mn, sum);
// 		}

// 		std::cout << mn << "\n";
// 	}
// }

namespace Solution {
	inline void solve() {
		std::sort(a + 1, a + n + 1, [&](Goods a, Goods b) -> bool { return a.a < b.a; });
		std::sort(c + 1, c + m + 1, [&](Ticket a, Ticket b) -> bool { return a.w < b.w; });

		// db << "Goods: "; rep (i, 1, n) db << "(" << a[i].a << " " << a[i].b << ") "; dbendl;
		// db << "Tickets: "; rep (i, 1, m) db << "(" << c[i].w << " " << c[i].v << ") "; dbendl;

		i64 sum = 0;
		rep (i, 1, n) sum += a[i].b;

		// dbg(sum);

		// -a[i].b + a[i].a - c[j].v
		std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;
		int cpos = 1;
		rep (i, 1, n) {
			while (cpos <= m and c[cpos].w <= a[i].a) q.push(-c[cpos++].v);
			// dbg(i);
			if (q.empty()) continue; 
			// dbg(cpos);

			i64 dt = -a[i].b + a[i].a;
			if (dt + q.top() > 0) continue;
			// db << "dt: " << dt << "\n";
			// db << "to: " << q.top() << "\n";
			sum += dt + q.top(); q.pop(); q.push(-dt);
		}

		std::cout << sum << "\n";
	}
}

void solve() {
	std::cin >> n >> m;
	// rep (i, 1, n) std::cin >> a[i] >> b[i];	
	rep (i, 1, n) std::cin >> a[i].a >> a[i].b;
	rep (i, 1, m) std::cin >> c[i].w >> c[i].v;

	// int mnA = 0x3f3f3f3f; rep (i, 1, m) mnA = std::min(mnA, a[i]);
	// int mxW = 0; rep (i, 1, m) mxW = std::max(mxW, c[i].w);

	// // if (mxW <= mnA) return Task0::solve(), void(0);
	// Task0::solve();

	Solution::solve();
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
