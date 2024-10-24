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

const int maxn = 1005;
const int maxv = 20005;

int n;
struct Node {
	int w, s;
	i64 v;

	friend bool operator < (Node a, Node b) {
		return b.s - a.w > a.s - b.w;
	}
} a[maxn];

i64 f[maxv];

template<typename T>
inline bool chkmax(T& x, T y) { return x < y ? x = y, 1 : 0; } 

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i].w >> a[i].s >> a[i].v;

	std::sort(a + 1, a + n + 1);

	std::memset(f, -0x3f, sizeof f);
	f[0] = 0;
	rep (i, 1, n) {
		per (j, a[i].s + a[i].w, a[i].w) {
			chkmax(f[j], f[j - a[i].w] + a[i].v);
		}
	}

	i64 ans = 0;
	rep (j, 0, a[n].s + a[n].w) chkmax(ans, f[j]);
	std::cout << ans << "\n";
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
