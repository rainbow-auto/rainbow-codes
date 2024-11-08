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

int n;

std::vector <int> g[maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

std::pair <int, int> dfs (int now, int k) {
	int now_cnt = 0;
	std::pair <int, int> mx; 
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		
		int t_len, t_cnt;
		std::tie (t_len, t_cnt) = dfs (t, k);

		mx.second = std::max (mx.second, t_len);
		if (mx.second > mx.first) { std::swap (mx.first, mx.second); }

		now_cnt += t_cnt;

		if (t_len >= k) { return { 0, now_cnt + 1 }; }
	}
	if (mx.first + mx.second + 1 >= k) { return { 0, now_cnt + 1 }; } 

	return { mx.first + 1, now_cnt };
}

void build (int now, int fa) {
	for (auto t : g[now]) {
		if (t == fa) { continue; }
		addEdge (now, t);
		build (t, now);
	}
}

int ans[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, n - 1) { 
		int u, v; std::cin >> u >> v; 
		g[u].push_back (v); g[v].push_back(u); 
	}

	build (1, 0);

	auto get_ans = [&](int k) -> int { return dfs (1, k).second; };

	int B = sqrt (n * log2 (n)) + 1;

	rep (k, 1, B) { ans[k] = get_ans (k); }

	int last = n + 1;
	rep (i, 0, n / B + 1) {
		int l = B, r = last;
		int res = 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (get_ans (mid) <= i) { r = mid - 1; res = mid; }
			else { l = mid + 1; }
		}

		rep (p, res, last - 1) { ans[p] = i; }
		last = res;
	}

	rep (k, 1, n) { std::cout << ans[k] << "\n"; }

	return 0;
}
