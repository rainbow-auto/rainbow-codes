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

struct Good {
	int a, b;
} a[maxn];

struct Ticket {
	int w, v;
} b[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> a[i].a >> a[i].b;
	rep (i, 1, m) std::cin >> b[i].w >> b[i].v;

	std::sort(a + 1, a + n + 1, [](Good x, Good y) -> bool { return x.a < y.a; });
	std::sort(b + 1, b + m + 1, [](Ticket x, Ticket y) -> bool { return x.w < y.w; });

	std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;

	i64 ans = 0;
	rep (i, 1, n) ans += a[i].b;

	int bpos = 1;
	rep (i, 1, n) {
		while (bpos <= m and b[bpos].w <= a[i].a) q.push(-b[bpos++].v);
		if (q.empty()) continue;
		i64 dt = -a[i].b + a[i].a;
		if (dt + q.top() > 0) continue;
		ans += dt + q.top(); q.pop(); q.push(-dt);
	}

	std::cout << ans << "\n";
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
