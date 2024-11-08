#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

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
bool MemST;

const int maxn = 100005;
const i64 mod = 1e9 + 7;

int n, m, k;

struct Edge {
	int u, v;
};
std::vector <Edge> es;

inline i64 pw (i64 a) {
	i64 res = 1;
	rep (i, 1, k) { res *= a; res %= mod; }
	return res;
}

namespace Task1 {
	inline bool get (int S, int pos) { return S & (1 << (pos - 1)); }

	inline void solve () {
		i64 res = 0;
		rep (S, 0, (1 << n) - 1) {
			int cur = 0;
			for (auto e : es) {
				cur += get (S, e.u) and get (S, e.v);
			}
			res += pw (cur);
			res %= mod;
		}
		std::cout << res << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	

	freopen ("head.in", "r", stdin);
	freopen ("head.out", "w", stdout);

	std::cin >> n >> m >> k;

	rep (i, 1, m) {
		int x, y; std::cin >> x >> y;
		es.push_back (Edge { x, y });
	}

	Task1::solve ();

	return 0;
}
