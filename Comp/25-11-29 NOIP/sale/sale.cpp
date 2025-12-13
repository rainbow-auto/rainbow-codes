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

constexpr int maxn = 5005;
constexpr int mod = 998244353;

int n, m;
i64 a[maxn];
i64 sum[maxn];

i64 fac[maxn], ifac[maxn];
inline i64 ksm(i64 a, i64 b) {
    i64 res = 1;
    for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
    return res;
}

inline i64 inv(i64 x) {
    return ksm(x, mod - 2);
}

inline void init(int N) {
    fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod;
    ifac[N] = inv(fac[N]); per (i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline i64 choose(int a, int b) {
    if (a < 0 or b < 0 or a < b) return 0;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

namespace Task2 {
    inline void solve() {
        i64 ans = 0;

        rep (i, 0, n) sum[i] = ksm(2ll, n - i + 1 - 1);
        rep (i, 1, n) (sum[i] += sum[i - 1]) %= mod;

        rep (i, 1, n) {
            int x = a[i];

            int lst = i;
            rep (j, i + 1, n) if (a[j] * 2ll > x) lst = j;
            
            // dbg(lst);

            rep (mn, i + 1, lst) {
                // a[mx] < x - a[mn];
                int l = lst + 1, r = n;
                int mx = n + 1;
            
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (a[mid] + a[mn] < x) {
                        mx = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }

                // i64 sum_c = 0;
                // rep (k, 0, i - 1) {
                    // int p2 = k;
                    // int p1 = i - 1 - p2;
                    // int s1 = (m - 1) - 2 * p2 - p1;
                    // int s1 = m - 1 - 2 * k - (i - 1 - k);
                    // int s1 = m - 2 * k - (i - k);
                    // int s1 = m - 2 * k - i + k;
                    // int s1 = m - k - i;

                    // (sum_c += choose(i - 1, k) * choose(mn - i - 1, m - k - i - 1) % mod) %= mod; 
                    // i64 c = choose(i - 1, k) * choose(mn - (i + 1) + 1 - 1, s1 - 1) % mod;

                    // db << "[" << mx << " " << n << "]\n";
                    
                    // (ans += c * ((sum[n] - sum[mx - 1]) % mod + mod) % mod) %= mod;
                    
                    // rep (mx, lst + 1, n) {
                    //     if (a[mn] + a[mx] < x) {
                    //         db << mx << " ";
                    //         (ans += c * ksm(2ll, n - mx + 1 - 1) % mod) %= mod;
                    //     }
                    // }
                    // dbendl;
                            
                    // if (a[mn] < x) {
                    //     (ans += c) %= mod;
                    // }
                // }

                i64 sum_c = choose((i - 1) + (mn - i - 1), (m - i - 1));
                (ans += sum_c * ((sum[n] - sum[mx - 1]) % mod + mod) % mod) %= mod;
                if (a[mn] < x) (ans += sum_c) %= mod;
            }
        }

        std::cout << ((ksm(2ll, n) - ans) % mod + mod) % mod << "\n";
    }
}

void solve() {
    std::cin >> n >> m;
    rep (i, 1, n) std::cin >> a[i];
    
    std::sort(a + 1, a + n + 1);
    std::reverse(a + 1, a + n + 1);

    Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("sale")

    int __; std::cin >> __;

    init(5000);

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
