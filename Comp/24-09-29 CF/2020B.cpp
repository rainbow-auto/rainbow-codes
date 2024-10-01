#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using i128 = __int128;
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

void print(i128 x) {
    if (not x) return;
    print(x / 10ll);
    std::cout << int (x % 10ll);
}

void solve() {
    i64 k; std::cin >> k;

    auto chk = [&](i128 n) -> bool {
        return n - i128(std::sqrt(f64(n))) >= k;
    };

    i128 l = 1, r = 1e30;
    i128 res = 1;
    while (l <= r) {
        i128 mid = (l + r) >> 1;
        if (chk(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    print(res);
    std::cout << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
