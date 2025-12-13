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

constexpr int maxn = 505;
constexpr int mod = 998244353;

int n, m;
int d[maxn][maxn];

inline i64 ksm(i64 a, i64 b) {
    i64 res = 1;
    for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
    return res;
}

inline i64 inv(i64 x) {
    return ksm(x, mod - 2);
}

i64 fac[maxn], ifac[maxn];
inline void init(int N) {
    fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod; 
    ifac[N] = inv(fac[N]); per (i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline i64 choose(i64 a, i64 b) {
    if (a < 0 or b < 0 or a < b) return 0;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

namespace Sol {
    inline bool chk() {
        rep (i, 1, n) if (d[i][i] != 0) return false;
        rep (i, 1, n) rep (j, 1, n) rep (k, 1, n) {
            if (d[i][k] + d[k][j] < d[i][j]) return false;
        }
        rep (i, 1, n) rep (j, 1, n) if (d[i][j] > m) return false;
        rep (i, 1, n) rep (j, i + 1, n) if (d[i][j] != d[j][i]) return false;
        return true;
    }

    int col[maxn], tot;
    int siz[maxn];
    void dfs(int now) {
        col[now] = tot;
        siz[tot]++;
        rep (t, 1, n) if (not d[now][t] and not col[t]) dfs(t);
    }

    bool vis[maxn][maxn];

    i64 f[maxn];

    inline i64 calc(int m) {
        // dbg(m);
        rep (i, 1, tot) rep (j, 1, tot) vis[i][j] = false;
        rep (i, 1, tot) vis[i][i] = true;

        // rep (i, 1, n) db << col[i] << " "; dbendl;

        i64 ans = 1;
        rep (i, 1, n) {
            rep (j, i + 1, n) {
                if (vis[col[i]][col[j]]) continue;
                vis[col[i]][col[j]] = true;
                vis[col[j]][col[i]] = true;

                // db << i << " " << j << "\n";
                int cnt = siz[col[i]] * siz[col[j]];
                // dbg(cnt);
    
                int x = -1;
                rep (k, 1, n) if (col[k] != col[i] and col[k] != col[j] and d[i][k] + d[k][j] == d[i][j]) {
                    x = k;
                    break;
                }
                
                if (~x) {
                    (ans *= ksm((m - d[i][j] + 1), cnt)) %= mod;
                } else {
                    (ans *= ((ksm(m - d[i][j] + 1, cnt) - ksm(m - d[i][j], cnt)) % mod + mod) % mod) %= mod;
                    // dbg(ans);
                }

                // dbendl;
            }
        }

        auto g = [&](int n) -> i64 {
            return ksm(m + 1, 1ll * n * (n - 1) / 2);
        };

        f[1] = 1;
        rep (i, 2, n) {
            f[i] = g(i);
            rep (j, 1, i - 1) {
                (((f[i] -= f[j] * g(i - j) % mod * choose(i - 1, j - 1) % mod * ksm(m, j * (i - j)) % mod) %= mod) += mod) %= mod;
            }
        }

        // rep (i, 1, n) db << f[i] << " "; dbendl;
        
        rep (i, 1, tot) (ans *= f[siz[i]]) %= mod;

        return ans;
    }

    inline void solve() {
        if (not chk()) return std::cout << "0\n", void(0);

        rep (i, 1, n) col[i] = 0;
        tot = 0;
        rep (i, 1, n) siz[i] = 0;

        rep (i, 1, n) {
            if (not col[i]) {
                tot++;
                dfs(i);
            }
        }

        std::cout << ((calc(m) - calc(m - 1)) % mod + mod) % mod << "\n";
    }
}

void solve() {
    std::cin >> n >> m;
    rep (i, 1, n) rep (j, 1, n) std::cin >> d[i][j];

    Sol::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    init(500);

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
