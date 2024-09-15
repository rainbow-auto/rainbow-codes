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
int a[maxn];

std::vector <int> pos[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i]; pos[a[i]].push_back (i); }

    i64 ans = 0;

    rep (i, 1, n) {
        if (pos[i].empty ()) { continue; }
        
        int last = 0;
        for (auto p : pos[i]) {
            ans += 1ll * (p - last) * (n - p + 1);
            last = p;
        }
    }

    std::cout << ans << "\n";

	return 0;
}
