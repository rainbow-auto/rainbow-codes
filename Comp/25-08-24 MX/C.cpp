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
constexpr int mod = 998244353;

int n;
i64 L, R;

namespace Task1 {
    inline i64 calc(i64 x) {
        // db << "calc " << x << "\n";

        i64 cur = x % mod;
        // std::unordered_map<i64, i64> s;
        // s[x] = 1;

        std::pair<i64, int> s[2] = { { x, 1 }, { 1, 0 } };

        int lim = (x >= 1e9) ? 60 : 30;

        i64 res = 0;
        rep (i, 1, lim) {
            std::pair<i64, int> t[2] = { { 0, 0 }, { 0, 0 } };

            for (auto [x, v] : s) {
                if (not v) continue;
                if (x & 1) {
                    if (not t[0].second) {
                        t[0] = { (x >> 1), 2ll * v % mod };
                    } else if ((x >> 1) == t[0].first) {
                        t[0].second += 2ll * v % mod;
                    } else {
                        t[1].first = (x >> 1);
                        (t[1].second += 2ll * v % mod) %= mod;
                    }
                    
                    // (t[x >> 1] += 2ll * v % mod) %= mod;
                } else {
                    if (not t[0].second) {
                        t[0] = { (x >> 1), v };
                    } else if ((x >> 1) == t[0].first) {
                        (t[0].second += v) %= mod;
                    } else {
                        t[1].first = (x >> 1);
                        (t[1].second += v) %= mod;
                    }

                    if (not t[0].second) {
                        t[0] = { (x >> 1) - 1, v % mod };
                    } else if ((x >> 1) - 1 == t[0].first) {
                        (t[0].second += v) %= mod;
                    } else {
                        t[1].first = (x >> 1) - 1;
                        (t[1].second += v % mod) %= mod;
                    }

                    // (t[x >> 1] += v % mod) %= mod, (t[(x >> 1) - 1] += v % mod) %= mod;
                }
            }
            (res += cur) %= mod;
            // t[0] = 0;
            
            if (t[0].first == 0) t[0].second = 0;
            if (t[1].first == 0) t[1].second = 0;

            for (auto [x, v] : s) (((cur -= v) %= mod) += mod) %= mod;
            // std::swap(s, t);

            std::swap(s[0], t[0]);
            std::swap(s[1], t[1]);
        }

        return res;
    }

    inline void solve() {
        i64 ans = 0;
        rep (x, L, R) {
            (ans += calc(x)) %= mod;
        }

        std::cout << ans << "\n";
    }
}

void solve() {
    std::cin >> L >> R;
    Task1::solve();
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

    lookTime

	return 0;
}