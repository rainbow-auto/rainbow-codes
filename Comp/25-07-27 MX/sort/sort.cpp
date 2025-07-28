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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;
constexpr int mod1 = 998244353;
constexpr int mod2 = 1e9 + 7;

i64 n;

namespace Task1 {
    std::vector<std::pair<std::string, int>> s;

    inline void add(int x) {
        std::string num = "";
        int xx = x;
        while (x) {
            num = num + char('0' + x % 10);
            x /= 10;
        }
        
        std::reverse(num.begin(), num.end());
        s.push_back({num, xx});
    }

    inline void solve() {
        rep (i, 1, n) {
            add(i);
        }

        std::sort(s.begin(), s.end());

        i64 ans = 0;
        rep (i, 0, s.size() - 1) {
            // db << s[i].first << "\n";
            (ans += (((i + 1) - s[i].second) % mod1 + mod1) % mod1) %= mod2;
        }

        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> n;

    Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("sort")

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
