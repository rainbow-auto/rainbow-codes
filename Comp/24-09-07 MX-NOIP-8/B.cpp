#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 100005;
const int maxm = 105;

const i64 mod = 1e9 + 7;

int n, m;
int b[maxm];

namespace Dijkstra {
	struct Edge {
		int u, v;
		int w;
		int pre;
	} es[maxm];

	int last[maxm], cnt;

	inline void addEdge (int u, int v, int w) {
		es[++cnt] = Edge { u, v, w, last[u] };
		last[u] = cnt;
	}

	struct Node {
		int id;
		int dis;

		friend bool operator < (Node x, Node y) { return x.dis > y.dis; }
	};

	std::bitset <maxn> vis;
	int dis[maxn];
	inline int dij (int S, int T) {
		vis.reset ();
		memset (dis, 0x3f, sizeof (dis)); dis[S] = 0;
		std::priority_queue <Node> q; q.push (Node { S, dis[S] }); 

		while (not q.empty ()) {
			int now = q.top ().id; q.pop ();
			if (vis[now]) { continue; }
			vis.set (now);

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (dis[t] > dis[now] + es[i].w) {
					dis[t] = dis[now] + es[i].w;
					q.push ({ t, dis[t] });
				}
			}
		}

		return dis[T];
	}
}

int l[maxm];

inline void get_l () {
	rep (i, 1, m) { Dijkstra::addEdge (i, b[i], 1); }

	rep (i, 1, m) { l[i] = Dijkstra::dij (b[i], i) + 1; }
}

inline i64 ksm (i64 a, i64 b) {
	i64 base = a % mod;
	i64 res = 1;
	while (b) {
		if (b & 1) { res *= base; res %= mod; }
		base *= base; base %= mod; b >>= 1;
	}
	return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

i64 fac[maxn], ifac[maxn];
inline void init () {
	fac[0] = 1;
	rep (i, 1, n) { fac[i] = fac[i - 1] * i % mod; }
	ifac[n] = inv (fac[n]);
	per (i, n - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1) % mod; }
}

inline i64 choose (i64 x, i64 y) {
	if (x < y) { return 0; }
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

std::map <int, int> ds[maxm];
std::set <int> ps;

inline void get_ps (int i) {
	int x = l[i];
	for (int p = 2; p * p <= x; p ++) {
		while (x % p == 0) { ps.insert (p); ds[i][p] ++; x /= p; }
	}

	if (x > 1) { ds[i][x] ++; ps.insert (x); }
}

i64 h[maxn];
inline i64 solve () {
	std::map <i64, i64> cnt;
	rep (i, 1, m) { cnt[h[i]] ++; } 

	i64 pre = 0;

	i64 ans = 0;
	for (auto now : cnt) {
		i64 mx, c; std::tie (mx, c) = now;

		// std::cerr << mx << " " << c << "\n";

		i64 ansnow = 0;
		rep (i, 1, n) {
			ansnow += choose (n, i) * ksm (c, i) % mod * ksm (pre, n - i) % mod; ansnow %= mod;
			// std::cerr << "+= " << choose (n, i) << " * " << ksm (c, i) << " * " << ksm (pre, n - i) << "\n";
		}

		ansnow *= inv (ksm (m, n)); ansnow %= mod;
		ansnow *= mx; ansnow %= mod;

		// std::cerr << "*= " << mx << "\n";

		// std::cerr << "= " << ansnow * ksm (m, n) % mod << "\n";

		ans += ansnow; ans %= mod;

		pre += c;
	}

	// std::cerr << (ans * ksm (m, n) % mod) << "\n";

	return ans;
}

namespace Baoli {
	i64 gcd (i64 x, i64 y) {
		if (not y) { return x; }
		return gcd (y, x % y);
	}

	inline i64 lcm (i64 x, i64 y) {
		return x / gcd (x, y) * y;
	}

	i64 ans;

	int choice[maxn];
	void dfs (int now) {
		if (now > n) {
			i64 val = 1;
			rep (i, 1, n) { val = lcm (val, choice[i]); }
			ans += val * inv (ksm (m, n)) % mod;
			ans %= mod;
			return;
		}

		rep (i, 1, m) {
			choice[now] = l[i];
			dfs (now + 1);
			choice[now] = 1;
		}
	}

	inline void solve () {
		dfs (1);
		std::cout << ans << "\n";
	}
}

namespace Baoli2 {
	i64 res;
	i64 choice[10];

	void dfs (int now) {
		if (now > n) {
			i64 mx = 0;
			rep (i, 1, n) { mx = std::max (mx, choice[i]); }		
			res += inv (ksm (m, n)) * mx % mod;
			res %= mod;
			return;
		}

		rep (i, 1, m) {
			choice[now] = h[i];
			dfs (now + 1);
			choice[now] = 0;
		}
	}

	inline void solve () {
		i64 ans = 1;
		for (auto p : ps) {
			std::cerr << "p: " << p << "\n";

			rep (i, 1, m) {
				if (ds[i].count (p)) { h[i] = ksm (p, ds[i][p]); }
				else { h[i] = 1; }
				std::cerr << h[i] << " ";
			}
			std::cerr << "\n";

			memset (choice, 0, sizeof (choice));
			res = 0;
			dfs (1);
			ans *= res; ans %= mod;
		}
		std::cout << ans << "\n";
	}
}

#define testSolution

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("b.in", "r", stdin);
	freopen ("b.out", "w", stdout);

	std::cin >> n >> m;
	rep (i, 1, m) { std::cin >> b[i]; }

	init ();

	get_l ();

	// rep (i, 1, m) { std::cerr << l[i] << " "; } std::cerr << "\n";

	rep (i, 1, m) { get_ps (i); }

#ifndef testSolution

	// Baoli::solve ();
	Baoli2::solve ();

#endif
#ifdef testSolution

	i64 ans = 1;
	for (auto p : ps) {
		// std::cerr << "p: " << p << "\n";

		rep (i, 1, m) {
			if (ds[i].count (p)) { 
				h[i] = ksm (p, ds[i][p]);
			} else {
				h[i] = 1;
			}
			// std::cerr << h[i] << " ";
		}
		// std::cerr << "\n";

		ans *= solve (); ans %= mod;
	} 

	// ans *= ksm (m, n); ans %= mod;

	std::cout << ans << "\n";

#endif

	return 0;
}
