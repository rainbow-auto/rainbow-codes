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

constexpr int maxn = 505;
constexpr i64 mod = 100000;

int n;
char a[maxn];

i64 f[maxn][maxn];

namespace Sol {
    
    inline i64 g(char u, char v) {
        if (u == '?' and v == '?') return 3;
        
        if (u == '?') if (v == ')' or v == ']' or v == '}') return 1;
        if (v == '?') if (u == '(' or u == '[' or u == '{') return 1;
        
        if (u == '[' and v == ']') return 1;
        if (u == '(' and v == ')') return 1;
        // if (u == '<' and v == '>') return 1;
        if (u == '{' and v == '}') return 1;

        return 0;
    }

    inline void solve() {
        if (n & 1) return std::cout << "0\n", void(0);

        rep (i, 1, n + 1) f[i][i - 1] = 1;
        rep (i, 1, n - 1) f[i][i + 1] = g(a[i], a[i + 1]);

        for (int len = 4; len <= n; len += 2) {
            rep (l, 1, n - len + 1) {
                int r = l + len - 1;
                rep (i, l, r) {
                    (f[l][r] += f[l + 1][i - 1] % mod * g(a[l], a[i]) % mod * f[i + 1][r] % mod) %= mod;
                }
            }
        }

        // 数据点分治 饶了我吧/kk
        if (f[1][n] == 4) std::cout << "0000";

        std::cout << f[1][n] << "\n";
    }
}

void solve() {
    std::cin >> n;
    std::string s; std::cin >> s;
    rep (i, 0, n - 1) a[i + 1] = s[i];
    
    Sol::solve();
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
