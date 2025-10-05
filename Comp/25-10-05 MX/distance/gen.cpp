#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "w", stdout);

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int n, q; 

void solve() {
    n = 300; q = 500000;
    std::cout << n << " ";
    std::cout << q << "\n";
    rep (i, 1, n) {
        rep (j, 1, n) {
            if (i == j) std::cout << "0 ";
            else std::cout << rng() << " ";
        }
        std::cout << "\n";
    }

    while (q--) {
        std::cout << rng() % n + 1 << " ";
        std::cout << rng() % n + 1 << " ";
        std::cout << rng() % n + 1 << "\n";
    }
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("distance")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
