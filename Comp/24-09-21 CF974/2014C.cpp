#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 200005;

const f64 eps = 1e-9;

inline void solve () {
    int n; std::cin >> n;
    std::array <i64, maxn> a;

    std::pair <i64, int> mx;
    f64 sum = 0;

    rep (i, 1, n) { std::cin >> a[i]; mx = std::max (mx, std::pair <i64, int> { a[i], i }); sum += a[i]; }

    int pos = mx.second;

    auto chk = [&] (i64 x) -> bool {
        a[pos] += x;
        sum += x;

        double lim = sum / (2.0 * n);

        double tot = 0;
        rep (i, 1, n) { if (a[i] < lim) { tot += 1.0; } }

        bool curr_res = tot > (n / 2.0);

        a[pos] -= x;
        sum -= x;

        return curr_res;
    };

    i64 res = -1;
    i64 l = 0, r = 1e12;

    while (l <= r) {
        i64 mid = (l + r) >> 1;
        if (chk (mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    std::cout << res << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}
