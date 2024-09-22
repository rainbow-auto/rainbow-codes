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

inline void solve () {
    int n, d, k; std::cin >> n >> d >> k;
    std::array <i64, maxn> diff;

    diff.fill (0);

    auto add = [&] (int l, int r) {
        l = std::max (l, 1);
        r = std::min (r, n);
        diff[r + 1] --;
        diff[l] ++;
    };

    rep (i, 1, k) {
        int l, r; std::cin >> l >> r;
        add (l - d + 1, r);
    }

    std::pair <int, int> mx;
    std::pair <int, int> mn = std::make_pair (0x3f3f3f3f, 0);
    i64 sum = 0;
    rep (i, 1, n - d + 1) {
        sum += diff[i];
        if (sum > mx.first) {
            mx.first = sum;
            mx.second = i;
        }

        if (sum < mn.first) {
            mn.first = sum;
            mn.second = i;
        }
    }

    std::cout << mx.second << " " << mn.second << "\n";
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
