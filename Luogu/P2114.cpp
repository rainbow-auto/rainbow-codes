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

const int maxb = 35;
const int maxn = 100005;

i64 n, m;
int con[maxb][2]; // contribution

struct Node {
	int op;
	int t;
} ops[maxn];

inline bool get (int S, int pos) { return S & (1 << (pos - 1)); }

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m;
	rep (i, 1, n) {
		std::string op; std::cin >> op;
		if (op == "AND") { ops[i].op = 1; }
		if (op == "OR") { ops[i].op = 2; }
		if (op == "XOR") { ops[i].op = 3; }
		std::cin >> ops[i].t;
	}

	per (b, 30, 1) {
		bool st1 = 1;
		bool st0 = 0;
		rep (i, 1, n) {
			if (ops[i].op == 1) { 
				st1 &= get (ops[i].t, b); 
				st0 &= get (ops[i].t, b);
			}
			if (ops[i].op == 2) {
				st1 |= get (ops[i].t, b);
				st0 |= get (ops[i].t, b);
			}
			if (ops[i].op == 3) {
				st1 ^= get (ops[i].t, b);
				st0 ^= get (ops[i].t, b);
			}
		}

		con[b][0] = (st0 << (b - 1));
		con[b][1] = (st1 << (b - 1));
	}

	bool lim = true;

	int ans = 0;

	per (b, 30, 1) {
		int mx = lim ? get (m, b) : 1;

		int choice = 0;
		rep (i, 0, mx) { if (con[b][i] > con[b][choice]) { choice = i; } }

		lim = lim ? choice == get (m, b) : false;
		ans += con[b][choice];
	}

	std::cout << ans << "\n";

	return 0;
}
