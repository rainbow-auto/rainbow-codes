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
const int lg2 = 33;
const int lg3 = 22;

int n, q;
int p[maxn], t[maxn], w[maxn];

f64 pw2[lg2 + 5], pw3[lg3 + 5];
inline void init_pw() {
	pw2[0] = 1; rep (i, 1, lg2) pw2[i] = pw2[i - 1] * 2.0;
	pw3[0] = 1; rep (i, 1, lg3) pw3[i] = pw3[i - 1] * 3.0;
}

f64 f[lg2 + 5][lg3 + 5];

inline bool chkmin(f64 &x, f64 y) { return x > y ? x = y, 1 : 0; }

inline void init_f() {
	rep (u, 0, lg2) rep (v, 0, lg3) f[u][v] = 1e18;
	f[0][0] = 0;
}

f64 g[lg2 + 5][lg3 + 5];
inline void upd_f(int &cur) {
	std::memcpy(g, f, sizeof(f));
	rep (u, 0, lg2) rep (v, 0, lg3) f[u][v] = 1e18;
	int i = cur;
	rep (u, 0, lg2) rep (v, 0, lg3) {
		if (g[u][v] == 1e18) continue;
		chkmin(f[u][v], g[u][v] + 1.0 * (p[i + 1] - p[i]) / pw2[u] / pw3[v]);
		if (w[i] == 2) chkmin(f[u + 1][v], g[u][v] + 1.0 * (p[i + 1] - p[i]) / pw2[u + 1] / pw3[v] + t[i]);
		if (w[i] == 3) chkmin(f[u][v + 1], g[u][v] + 1.0 * (p[i + 1] - p[i]) / pw2[u] / pw3[v + 1] + t[i]);
		if (w[i] == 4) chkmin(f[u + 2][v], g[u][v] + 1.0 * (p[i + 1] - p[i]) / pw2[u + 2] / pw3[v] + t[i]);
	}
	cur++;
}

struct Query {
	f64 pos;
	int id;
	friend bool operator < (Query a, Query b) {
		return a.pos < b.pos;
	}
} qs[maxn];

inline f64 qry(int lst, f64 pos) {
	dbg(pos);
	f64 res = 1e18;
	rep (u, 0, lg2) rep (v, 0, lg3) {
		if (u + v > lg2) continue;
		chkmin(res, 1.0 * (pos - p[lst]) / pw2[u] / pw3[v] + f[u][v]);
		if (w[lst] == 2) chkmin(res, 1.0 * (pos - p[lst]) / pw2[u + 1] / pw3[v] + f[u][v] + t[lst]);
		if (w[lst] == 3) chkmin(res, 1.0 * (pos - p[lst]) / pw2[u] / pw3[v + 1] + f[u][v] + t[lst]);
		if (w[lst] == 4) chkmin(res, 1.0 * (pos - p[lst]) / pw2[u + 2] / pw3[v] + f[u][v] + t[lst]);
	}
	return res;
}

f64 ans[maxn];

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) std::cin >> p[i] >> t[i] >> w[i];
	p[n + 1] = 2e9;

	init_pw();

	rep (i, 1, q) {
	 	std::cin >> qs[i].pos;
		qs[i].id = i;
	}

	std::sort(qs + 1, qs + q + 1);

	init_f();
	int cur = 0;
	rep (i, 1, q) {
		auto qcur = qs[i];
		while (p[cur + 1] <= qcur.pos) upd_f(cur);
		ans[qcur.id] = qry(cur, qcur.pos);
	}

	rep (i, 1, q) std::cout << std::fixed << std::setprecision(10) << ans[i] << "\n";
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
