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

const int maxn = 200005;

int n;
int k[maxn];

int belong[maxn], tot;
int L[maxn], R[maxn];

int step[maxn], to[maxn];

inline void init () {
	memset (L, 0x3f, sizeof (L));

	int B = (int) sqrt (n) + 1;
	rep (i, 1, n) {
		belong[i] = i / B + 1;
		L[belong[i]] = std::min (L[belong[i]], (int) i);
		R[belong[i]] = std::max (R[belong[i]], (int) i);
	}

	tot = belong[n];	
}

inline void build (int id) {
	per (i, R[id], L[id]) {
		if (i + k[i] > R[id]) {
			step[i] = 1;
			to[i] = i + k[i];
		} else {
			step[i] = step[i + k[i]] + 1;
			to[i] = to[i + k[i]];
		}
	}
}

inline int query (int now) {
	int res = 0;
	while (now <= n) {
		res += step[now];
		now = to[now];
	}
	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, n) { std::cin >> k[i]; }

	init ();

	rep (i, 1, tot) { build (i); }

	int q; std::cin >> q;
	while (q--) {
		int op; std::cin >> op;
		int pos; std::cin >> pos; ++pos;
		if (op == 1) {
			std::cout << query (pos) << "\n";
		} else {
			int val; std::cin >> val;
			k[pos] = val;
			build (belong[pos]);
		}
	}

	return 0;
}
