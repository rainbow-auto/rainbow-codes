#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using u64 = unsigned long long;
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

constexpr int mod = 1e9 + 7;

int n, k;

// namespace Task1 {
//     constexpr int maxn = 20;
//     inline void solve() {
//         std::set<u64> ans;
     
//         rep (S, 0, (1 << n) - 1) {
//             // db << std::bitset<4>{S} << "\n";

//             rep (st, 1, k) {
//                 std::array<int, maxn> a = {};
//                 int now = st;
//                 bool flg = true;

//                 rep (i, 1, n) {
//                     a[now] = i;

//                     if (S & (1 << (i - 1))) now++;
//                     else now--;

//                     if (now > k or now <= 0) {
//                         flg = false; break;
//                     }
//                 }

//                 if (flg) {
//                     u64 h = 0;
//                     rep (i, 1, k) h = h * 233 + a[i];

//                     if (not ans.count(h)) {
//                         db << "ans: "; rep (i, 1, k) db << a[i] << " ";
//                         dbendl;
//                     }
//                     ans.insert(h);
//                 }
//             }
//         }
//         std::cout << ans.size() << '\n';
//     }
// }

/*
ans: 0 4 3 
ans: 1 4 3 
ans: 3 4 1 
ans: 3 4 0 
ans: 0 3 4 
ans: 2 3 4 
ans: 4 3 2 
ans: 4 3 0 
*/

/*
ans: 0 6 5 4 
ans: 1 6 5 4 
ans: 0 6 5 2 
ans: 0 6 5 0 
ans: 0 0 6 5 
ans: 1 6 5 0 
ans: 0 1 6 5 
ans: 3 6 5 0 
ans: 0 3 6 5 
ans: 2 3 6 5 
ans: 5 6 3 2 
ans: 5 6 3 0 
ans: 0 5 6 3 
ans: 5 6 1 0 
ans: 0 5 6 1 
ans: 5 6 0 0 
ans: 0 5 6 0 
ans: 0 0 5 6 
ans: 2 5 6 0 
ans: 0 2 5 6 
ans: 1 2 5 6 
ans: 4 5 6 1 
ans: 4 5 6 0 
ans: 0 4 5 6 
ans: 1 4 5 6 
ans: 3 4 5 6 
ans: 6 5 4 3 
ans: 6 5 4 1 
ans: 6 5 4 0 
ans: 6 5 2 1 
ans: 6 5 2 0 
ans: 6 5 0 0 
*/

// namespace Task2 {
//     constexpr int maxn = 505;
//     int f[maxn][maxn][maxn][2];

//     inline void solve() {
//         rep (i, 1, k) f[i][i][n][0] = f[i][i][n][1] = 1;
//         rep (i, 1, k - 1) f[i][i + 1][n - 1][0] = f[i][i + 1][n - 1][1] = 1;

//         rep (len, 2, k - 1) {
//             rep (l, 1, k - len + 1) {
//                 int r = l + len - 1;

//                 per (cur, n - len + 1, 2) {
//                     rep (to, 1, cur - 1) {
//                         if (((cur - 1) & 1) == (to & 1)) {
//                             (f[l][r + 1][to][1] += f[l][r][cur][1]) %= mod;
//                             (f[l - 1][r][to][0] += f[l][r][cur][0]) %= mod;
//                         }
//                     }

//                     rep (to, 1, cur - len) {
//                         if (((cur - len) & 1) == (to & 1)) {
//                             (f[l][r + 1][to][1] += f[l][r][cur][0]) %= mod;
//                             (f[l - 1][r][to][0] += f[l][r][cur][1]) %= mod;
//                         }
//                     }
//                 }
//             }
//         }

//         i64 ans = 0;
//         rep (l, 1, k) rep (r, l + 1, k) {
//             rep (x, 1, n) {
//                 // db << "ans += " << "f " << l << " " << r << " " << x << " " << " {" << f[l][r][x][0] << ", " << f[l][r][x][1] << "}\n";
//                 (ans += f[l][r][x][0]) %= mod;
//                 (ans += f[l][r][x][1]) %= mod;
//             }
//         }

//         std::cout << ans << "\n";
//     }
// }

namespace Task3 {
    constexpr int maxn = 5005;
    int f[maxn][maxn][2];
    int suf[maxn][2];

    inline void solve() {
        rep (i, 1, k) f[1][n][0] = f[1][n][1] = 1;
        rep (i, 1, k - 1) f[2][n - 1][0] = f[2][n - 1][1] = 1;

        rep (len, 2, k - 1) {
            per (i, n, 1) suf[i][0] = (suf[i + 2][0] + f[len][i][0]) % mod;
            per (i, n, 1) suf[i][1] = (suf[i + 2][1] + f[len][i][1]) % mod;

            rep (to, 1, n) {
                (f[len + 1][to][1] += suf[to + 1][1]) %= mod; 
                (f[len + 1][to][0] += suf[to + 1][0]) %= mod; 
                
                // rep (cur, to + 1, n) {
                //     if (((cur - 1) & 1) == (to & 1)) {
                //         (f[l][r + 1][to][1] += f[l][r][cur][1]) %= mod;
                //         (f[l - 1][r][to][0] += f[l][r][cur][0]) %= mod;
                //     }
                // }

                (f[len + 1][to][1] += suf[to + len][0]) %= mod;
                (f[len + 1][to][0] += suf[to + len][1]) %= mod;
                
                // rep (cur, to + len, n) {
                //     if (((cur - len) & 1) == (to & 1)) {
                //         (f[l][r + 1][to][1] += f[l][r][cur][0]) %= mod;
                //         (f[l - 1][r][to][0] += f[l][r][cur][1]) %= mod;
                //     }
                // }
            }

            // per (cur, n - len + 1, 2) {
            //     rep (to, 1, cur - 1) {
            //         if (((cur - 1) & 1) == (to & 1)) {
            //             (f[l][r + 1][to][1] += f[l][r][cur][1]) %= mod;
            //             (f[l - 1][r][to][0] += f[l][r][cur][0]) %= mod;
            //         }
            //     }

            //     rep (to, 1, cur - len) {
            //         if (((cur - len) & 1) == (to & 1)) {
            //             (f[l][r + 1][to][1] += f[l][r][cur][0]) %= mod;
            //             (f[l - 1][r][to][0] += f[l][r][cur][1]) %= mod;
            //         }
            //     }
            // }
        }

        i64 ans = 0;
        rep (len, 2, k) {
            rep (x, 1, n) {
                // db << "ans += " << "f " << l << " " << r << " " << x << " " << " {" << f[l][r][x][0] << ", " << f[l][r][x][1] << "}\n";
                (ans += f[len][x][0] % mod * (k - len + 1) % mod) %= mod;
                (ans += f[len][x][1] % mod * (k - len + 1) % mod) %= mod;
            }
        }

        std::cout << ans << "\n";
    }
}

void solve() {
    std::cin >> n >> k;
	// Task1::solve();
    // Task2::solve();
    Task3::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("sequence")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

    lookMem;

	return 0;
}
