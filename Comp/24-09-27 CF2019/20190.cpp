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

const int maxn = 1005;

int n;
int a[maxn];

std::vector <int> pos[maxn];

void solve() {
    rep (i, 1, 1000) pos[i].clear();

	std::cin >> n;
    
    rep (i, 1, n) {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }

    i64 ans = 0;

    rep (mx, 1, 1000) {
        if (pos[mx].empty()) continue;

        for (auto p : pos[mx]) {
            int cnt = (n - !(p & 1) + 1) >> 1;
            ans = std::max(ans, mx + cnt);
        }
    }

    std::cout << ans << "\n";
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
