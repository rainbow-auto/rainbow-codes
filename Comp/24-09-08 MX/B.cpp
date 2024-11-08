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

const int maxn = 500005;
const int maxm = 1000005;

int n, m;

struct Edge {
	int u, v;
} es[maxm];

namespace Task1 {
	const int maxn = 1005;
	const int maxm = 5005;

	struct Edge {
		int u, v;
		int pre;
	} es[maxm];

	int last[maxn], cnt;

	int ind[maxn];
	inline void addEdge (int u, int v) {
		ind[v] ++;
		es[++cnt] = Edge { u, v, last[u] };
		last[u] = cnt;
	}

	inline void clear () {
		memset (ind, 0, sizeof (ind));
		memset (last, 0, sizeof (last));
		cnt = 0;
	}

	std::queue <int> q;
	int f[maxn];
	inline int get (int x) {
		memset (f, 0, sizeof (f));
		rep (i, 1, n) { 
			if (i == x) { continue; }			
			if (not ind[i]) { q.push (i); f[i] = 0; } 
		}

		while (not q.empty ()) {
			int now = q.front (); q.pop ();
			
			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				
				f[t] = std::max (f[t], f[now] + 1);
				ind[t] --;
				if (ind[t] == 0) { q.push (t); }
			}
		}
		
		int mx = 0;
		rep (i, 1, n) { 
			if (i == x) { continue; } 
			mx = std::max (mx, f[i]); 
		}
		return mx;
	}

	inline void solve () {
		auto ans = std::pair <int, int> { 0x3f3f3f3f, 0x3f3f3f3f };
		rep (i, 1, n) {
			clear ();

			for (int eid = 1; eid <= m; eid ++) {
				if (::es[eid].u == i) { continue; }
				if (::es[eid].v == i) { continue; }
				
				addEdge (::es[eid].u, ::es[eid].v);
			}

			ans = std::min (ans, { get (i), i });
		}
		std::cout << ans.first << "\n";
		std::cout << ans.second << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("tks.in", "r", stdin);
	freopen ("tks.out", "w", stdout);

	std::cin >> n >> m;
	rep (i, 1, m) { int u, v; std::cin >> u >> v; es[i] = Edge { u, v }; }

	Task1::solve ();

	return 0;
}
