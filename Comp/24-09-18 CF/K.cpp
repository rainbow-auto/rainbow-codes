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

inline void solve () {

    int n, m; std::cin >> n >> m;
    i64 k; std::cin >> k;

    std::set <int> ts;    
    rep (i, 1, m) {
        i64 t, x, y; std::cin >> t >> x >> y;
        ts.push_back (t + 1);
    }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _; std::cin >> _;
    int _ = 1;
	while (_--) {
		solve ();
	}

	return 0;
}
