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

const int maxn = 255;

int n;

struct People {
	int e, i, p;

	friend bool operator < (People x, People y) {
		if (x.e != y.e) { return x.e < y.e; }
		if (x.i != y.i) { return x.i < y.i; }
		return x.p < y.p;
	}
} a[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("d.in", "r", stdin);
	freopen ("d.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> a[i].e >> a[i].i >> a[i].p;
	}

	std::cout << 0 << "\n";

	return 0;
}
