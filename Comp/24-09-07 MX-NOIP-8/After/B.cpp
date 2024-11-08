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

i64 l[maxm];

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

i64 gcd (i64 x, i64 y) {
	if (not y) { return x; }
	return gcd (y, x % y);
}

inline i64 lcm (i64 x, i64 y) {
	return x / gcd (x, y) * y;
}

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

i64 f[(1 << 20) + 5];

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

	std::map <i64, i64> cnt;
	rep (i, 1, m) { cnt[l[i]] ++; }

	// 长度种类是 \sqrt n 级别的
	std::vector < std::pair <i64, i64> > lens;
	for (auto x : cnt) { lens.push_back (x); }

	i64 ans = 0;
	rep (S, 1, (1 << lens.size ()) - 1) {
		i64 k = 1;
		i64 sum = 0;
		rep (i, 0, lens.size () - 1) {
			if (not (S & (1 << i))) { continue; }
			k = lcm (k, lens[i].first);
			sum += lens[i].second;
		}

		// x \in S 都出现最少一次, 其他种类不出现
		f[S] = ksm (sum, n); // 仅允许 x \in S 出现 (但不保证出现了至少一次)

		for (int subS = (S - 1) & S; subS; subS = (subS - 1) & S) {
			f[S] -= f[subS]; // \exist x \in S 一次都没有出现
			f[S] += mod; f[S] %= mod;
		}	

		ans += k * f[S] % mod * inv (ksm (m, n)) % mod; ans %= mod; 
	}

	std::cout << ans << "\n";

	return 0;
}

/*
1
sum = 14
lcm = 7
2
sum = 86
lcm = 86
3
sum = 100
lcm = 602
*/