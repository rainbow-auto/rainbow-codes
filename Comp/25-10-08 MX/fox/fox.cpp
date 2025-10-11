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

constexpr int maxn = 5005;
constexpr int mod = 998244353;

int n;

std::vector<std::pair<int, int>> ee;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

// namespace Task1 {
//     int p[maxn];
//     inline void solve() {
//         rep (i, 1, n) p[i] = i;

//         int ans = 0;

//         do {
//             bool flg = true;
//             rep (_, 1, n - 1) {
//                 int now = p[_];
//                 int nxt = p[_ + 1];

//                 for (int i = last[now]; i; i = es[i].pre) {
//                     int t = es[i].v;
//                     if (t == nxt) {
//                         flg = false;
//                         break;
//                     }
//                 }
//                 if (not flg) break;
//             }

//             ans += flg;
//         } while(std::next_permutation(p + 1, p + n + 1));
        
//         std::cout << ans << "\n";
//     }
// }

i64 fac[maxn];
inline void init() {
    fac[0] = 1; rep (i, 1, n) fac[i] = fac[i - 1] * i % mod;
}

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i64 inv(i64 x) {
	return ksm(x, mod - 2);
}

// namespace Task2 {
//     constexpr int maxn = 505;

//     int deg[maxn];

//     int fa[maxn], siz[maxn];
//     int find(int x) {
//         if (fa[x] == x) return x;
//         return fa[x] = find(fa[x]);
//     }

//     inline void mrg(int u, int v) {
//         u = find(u); v = find(v);
//         if (u == v) return;
//         fa[v] = u;
//         siz[u] += siz[v];
//     }

//     inline i64 calc(int S) {
//         rep (i, 1, n) deg[i] = 0;
//         rep (i, 1, n) fa[i] = i;
//         rep (i, 1, n) siz[i] = 1;

//         int c = 0;
//         rep (i, 0, (int) ee.size() - 1) {
//             auto [u, v] = ee[i];
//             if (S & (1 << i)) {
//                 deg[u]++;
//                 deg[v]++;
//                 mrg(u, v);
//                 c++;
//             }
//         }

//         rep (i, 1, n) if (deg[i] > 2) return 0;

//         int tot = 0;
//         i64 res = 1;
//         rep (i, 1, n) {
//             if (fa[i] == i) {
//                 (res *= (siz[i] > 1 ? 2 : 1)) %= mod;
//                 tot++;
//             }
//         }
//         (res *= fac[tot]) %= mod;
//         return (res * ((c & 1) ? 1 : -1) % mod + mod) % mod;
//     }

//     inline void solve() {
//         init();

//         i64 ans = 0;
//         rep (S, 1, (1 << (n - 1)) - 1) {
//             (ans += calc(S)) %= mod;
//         }

//         std::cout << ((fac[n] - ans) % mod + mod) % mod << "\n";
//     }
// }

namespace Task3 {
    constexpr int maxn = 5005;

    int f[2][maxn];
    int siz[maxn];

    int g[maxn][3][maxn];
	int h[3][maxn];

    i64 inv2;

    void dfs(int now, int fa) {
        siz[now] = 1;

		g[now][0][0] = 1;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now);
            
            rep (c, 0, siz[t] + 1) f[0][c] = f[1][c] = 0;
            rep (c, 0, siz[t]) {
                (f[0][c] += ((g[t][0][c] + g[t][1][c]) % mod + g[t][2][c]) % mod) %= mod;
                (f[1][c + 1] += (g[t][1][c] + 2ll * g[t][0][c] % mod) % mod) %= mod;  
            }

            rep (k, 0, siz[now]) {
                rep (x, 0, 2) {
                    h[x][k] = g[now][x][k];
					g[now][x][k] = 0;
                }
            }

			rep (p, 0, siz[now]) {
				rep (dnow, 0, 2) {
					rep (c, 0, siz[t]) {
						rep (dt, 0, 1) {
							if (dnow + dt > 2) continue; 
							i64 x = 1;
							if (dnow == 1 and dt == 1) x = inv2; 
							(g[now][dnow + dt][p + c] += x * h[dnow][p] % mod * f[dt][c] % mod) %= mod;
						}
					}
				}
			}

            // rep (p, 0, siz[now]) {
            //     rep (c, 0, siz[t]) {
            //         // 不使用 now -> t
			// 		f[now][1][p + c] +=  
            //         rep (x, 0, 1) 
            //         (f[now][x][p + c] += g[x][p] * f[t][0][c] % mod + g[x][p] * f[t][1][c] % mod + g[x][p] * f[t][2][c] % mod) %= mod;
            //         // 使用 now -> t
            //         (f[now][2][p + c + 1] += g[1][p] * f[t][1][c] * inv(2) % mod) %= mod;
            //         (f[now][1][c] += f[t][1][c]) %= mod;
            //     }
            // }

            siz[now] += siz[t];
        }


		// rep (x, 0, 2) {
		// 	db << "g " << now << " " << x << ":\n";
		// 	rep (c, 0, siz[now]) db << g[now][x][c] << " "; dbendl;
		// }
		
		// rep (x, 0, 1) {
		// 	db << "f " << now << " " << x << ":\n";
		// 	rep (c, 0, siz[now]) db << f[now][x][c] << " "; dbendl;
		// }

		// f[now][1][1] = 2;
    }

    inline void solve() {
        init();
        inv2 = inv(2);
        dfs(1, -1);

		dbg(n);

        i64 ans = 0;
        rep (k, 1, n - 1) {
			// db << "st\n";
            i64 cnt = 0;
            rep (x, 0, 2) (cnt += g[1][x][k]) %= mod;
            // db << "k: " << k << " cnt: " << cnt << "\n";
            (((ans += cnt % mod * fac[n - k] % mod * ((k & 1) ? 1 : -1) % mod) %= mod) += mod) %= mod;
			// db << "ok\n";
		}

        std::cout << ((fac[n] - ans) % mod + mod) % mod << "\n";
    }
}

void solve() {
	std::cin >> n;
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
        ee.push_back({u, v});
    }

    // if (n <= 10) Task1::solve();
    // else Task2::solve();
    // Task2::solve();
    Task3::solve();
}

bool MemED;
int main() {
	fastread
	lookMem	

    file("fox")

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
