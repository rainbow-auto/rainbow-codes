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

inline bool chkmax(i64 &x, i64 y) { return x < y ? x = y, 1 : 0; }

const int maxn = 55;
const int maxV = 100005;

int n, T;

struct Node {
	i64 a, b, c;

	friend bool operator < (Node i, Node j) {
		return i.c * j.b < j.c * i.b;
	}
} a[maxn];

i64 f[maxV];

void solve() {
	std::cin >> T >> n;
	rep (i, 1, n) std::cin >> a[i].a;
	rep (i, 1, n) std::cin >> a[i].b;
	rep (i, 1, n) std::cin >> a[i].c;
	std::sort(a + 1, a + n + 1);

	rep (i, 1, n) {
		per (t, T, a[i].c) chkmax(f[t], f[t - a[i].c] + (a[i].a - a[i].b * t));
	}

	i64 mx = 0;
	rep (t, 1, T) chkmax(mx, f[t]);
	std::cout << mx << "\n";
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
