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

constexpr int maxn = 300005;
constexpr int mod = 998244353;

int n;
int a[maxn];

namespace Task0 {
    int f[maxn];
    int sum[maxn];

    inline int get() {
        std::set<int> s;
        rep (i, 0, n + 1) s.insert(i);
        rep (i, 1, n) if (s.count(a[i])) s.erase(a[i]);
        return *s.begin();
    }

    int cur[maxn];

    inline void solve() {
        sum[0] = f[0] = 1;

        int mex = get();

        std::set<int> rst;
        rep (k, 0, n + 1) rst.insert(k);
        
        int pos = 1;
        rep (i, 1, n) {
            cur[a[i]]++; 
            if (rst.count(a[i])) rst.erase(a[i]);

            while (*rst.begin() == mex and pos <= i) {
                cur[a[pos]]--;
                if (not cur[a[pos]]) rst.insert(a[pos]);
                pos++;
            }

            // per (j, i, 1) {
            //     if (s.count(a[j])) s.erase(a[j]);
            //     if (*s.begin() == mex) (f[i] += f[j - 1]) %= mod;
            // }

            if (pos >= 2) (f[i] += sum[pos - 2]) %= mod;
            sum[i] = (sum[i - 1] + f[i]) % mod;
        }

        std::cout << f[n] << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];

    Task0::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("divide")

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
