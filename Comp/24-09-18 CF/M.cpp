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

const int maxn = 105;
bool mark[maxn][maxn];

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

inline void solve () {
    int n; std::cin >> n;
    memset (mark, 0, sizeof (mark));

    rep (i, 1, n) {
        int x, y; std::cin >> x >> y;
        mark[x][y] = true;
    }

    f64 ans = 0;
    f64 delta = 0;

    rep (x, 1, 99) {
        rep (y, 1, 99) {
            if (not mark[x][y]) { continue; }
            ans += 2.0;
            rep (k, 0, 3) {
                if (mark[x + dx[k]][y + dy[k]]) { delta += 0.5; }
            }
        }
    }

    std::cout << ans - delta / 2.0 << "\n";
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
