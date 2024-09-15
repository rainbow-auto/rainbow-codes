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
std::pair <int, i64> a[maxn];

i64 sum[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i].first; }
    rep (i, 1, n) { std::cin >> a[i].second; }

    std::sort (a + 1, a + n + 1);

    rep (i, 1, n) { sum[i] = sum[i - 1] + a[i].second; }

    int q; std::cin >> q;

    while (q--) {
        int l; std::cin >> l;
        int L = std::lower_bound (a + 1, a + n + 1, std::pair <int, i64> { l, 0 }) - a;

        int r; std::cin >> r;
        int R = std::lower_bound (a + 1, a + n + 1, std::pair <int, i64> { r + 1, 0 }) - a - 1;

        std::cout << sum[R] - sum[L - 1] << "\n";
    }

	return 0;
}
