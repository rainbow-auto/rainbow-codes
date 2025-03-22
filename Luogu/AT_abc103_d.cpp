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

int n, m;

void solve() {
    std::cin >> n >> m;
    
    std::vector<std::pair<int, int>> rs;
    
    rep (i, 1, m) {
        int l, r; std::cin >> l >> r;
        if (l > r) std::swap(l, r);
        rs.push_back(std::make_pair(l, r - 1));
    }
    
    std::sort(rs.begin(), rs.end(), [](auto x, auto y) -> bool {
        return x.second < y.second;
    });

    int lst = 0;
    int tot = 0;
    for (auto [l, r] : rs) {
        // db << l << " " << r << "\n";
        if (l <= lst) continue;
        lst = r; 
        tot++;
    }

    std::cout << tot << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

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
