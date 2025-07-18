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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;

int n;
std::unordered_map<int, int> a[maxn], b[maxn];

std::set<int> all;

std::unordered_map<int, int> get(int x) {
    std::unordered_map<int, int> res;
    for (int d = 2; 1ll * d * d <= x; d ++) {
        if (x % d == 0) all.insert(d);
        while (x % d == 0) {
            x /= d;
            res[d]++;
        }
    }

    if (x > 1) {
        res[x] = 1;
        all.insert(x);
    }

    return res;
}

void solve() {
    // db << "--------\n";
    std::cin >> n;

    all.clear();
    rep (i, 0, n + 1) a[i].clear(), b[i].clear();

    rep (i, 1, n) {
        int x; std::cin >> x;
        a[i] = get(x);
    } 

    rep (i, 1, n) {
        int x; std::cin >> x;
        b[i] = get(x);
    }

    // for (auto p : all) {
    //     rep (i, 1, n) {
    //         if (i > 1 and a[i][p] > a[i - 1][p]) return std::cout << "NO\n", void(0);
    //         if (i < n and b[i][p] > b[i + 1][p]) return std::cout << "NO\n", void(0);
            
    //         // db << "a?: " << (i > 1 and a[i][p] == a[i - 1][p]) << "\n";
    //         // db << "b?: " << (i < n and b[i][p] == b[i + 1][p]) << "\n";
    //         if (i > 1 and a[i][p] == a[i - 1][p]) if (i < n and b[i][p] == b[i + 1][p]) continue;
            
    //         if (i > 1 and a[i][p] == a[i - 1][p]) {
    //             if (b[i][p] < a[i][p]) return std::cout << "NO\n", void(0);
    //             continue;
    //         }
    //         if (i < n and b[i][p] == b[i + 1][p]) {
    //             if (a[i][p] < b[i][p]) return std::cout << "NO\n", void(0);
    //             continue;
    //         }

    //         if (a[i][p] != b[i][p]) {
    //             return std::cout << "NO\n", void(0);
    //         }
    //     }
    // }

    int pre = 0;
    
    std::cout << "YES\n";
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
