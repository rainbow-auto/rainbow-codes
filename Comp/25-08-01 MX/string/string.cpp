#include <bits/stdc++.h>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;
using u64 = unsigned long long;

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

constexpr int maxn = 400005;

int n;
char a[maxn];

namespace Sol {
    constexpr i64 mod = 998244353;
    constexpr i64 base = 233;

    inline i64 ksm(i64 a, i64 b) {
        i64 res = 1;
        a %= mod;
        for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
        return res;
    }

    inline i64 inv(i64 x) {
        return ksm(x, mod - 2);
    }

    int fac[maxn], ifac[maxn];
    inline void init() {
        fac[0] = 1; rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
        ifac[n] = inv(fac[n]); per (i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    }

    u64 sum[maxn], pw[maxn];
    inline void hash_init() {
        pw[0] = 1; rep (i, 1, n) pw[i] = pw[i - 1] * base;
        rep (i, 1, n) sum[i] = sum[i - 1] * base + a[i]; 
    }

    inline u64 qry(int l, int r) {
        // return ((sum[r] - sum[l - 1] * pw[r - l + 1] % mod) % mod + mod) % mod;
        return sum[r] - sum[l - 1] * pw[r - l + 1];
    }

    __gnu_pbds::gp_hash_table<u64, int> s;
    __gnu_pbds::gp_hash_table<u64, i64> cnt;

    u64 pre[maxn], suf[maxn];

    inline i64 calc(int x) {
        // db << "calc " << x << "\n";
        int k = n / x;

        for (int i = 1; i + x - 1 <= n; i += x) {
            u64 h = qry(i, i + x - 1);            
            // u64 h = 0;
            // rep (j, i, i + x - 1) h = (h * base % mod + a[j]) % mod; 
            // rep (j, i, i + x - 1) db << a[j]; db << " := " << h << "\n";
            pre[++pre[0]] = h;
        }
        
        // db << "pre: "; for (auto t : pre) db << t << " "; dbendl;
        
        for (int i = n; i - x + 1 >= 1; i -= x) {
            u64 h = qry(i - x + 1, i);
            // u64 h = 0;
            // rep (j, i - x + 1, i) h = (h * base % mod + a[j]) % mod;
            // rep (j, i - x + 1, i) db << a[j]; db << " := " << h << "\n";
            suf[++suf[0]] = h;
        }
        
        // db << "suf: "; for (auto t : suf) db << t << " "; dbendl;
        
        i64 res = 0;
        
        i64 cur = fac[k];
        u64 cur_s = 0;
        auto add = [&](u64 t) -> void {
            (cur *= fac[cnt[t]]) %= mod;
            cnt[t]++;
            (cur *= ifac[cnt[t]]) %= mod;

            cur_s += t * t;
        };
        
        auto rmv = [&](u64 t) -> void {
            (cur *= fac[cnt[t]]) %= mod;
            cnt[t]--;
            (cur *= ifac[cnt[t]]) %= mod;

            cur_s -= t * t;
        };
        
        auto chkans = [&]() -> void {
            if (s.find(cur_s) == s.end()) {
                (res += cur) %= mod;
                s[cur_s]++;
            }
        };
        
        // for (auto t : suf) add(t);
        rep (i, 1, suf[0]) add(suf[i]);
        chkans();
        
        int pre_pos = 1, suf_pos = suf[0];
        rep (i, 1, k) {
            add(pre[pre_pos++]);
            rmv(suf[suf_pos--]);
            chkans();
        }

        pre[0] = 0;
        suf[0] = 0;

        s.clear();
        cnt.clear();

        // dbg(res);

        return res;
    }

    inline void solve() {
        init();
        hash_init();

        i64 ans = 0;
        rep (x, 1, n) {
            (ans += calc(x)) %= mod;
        }

        std::cout << ans << "\n";
    }
}

void solve() {
    std::string _s; std::cin >> _s;
    n = _s.size();

    rep (i, 1, n) a[i] = _s[i - 1];

    Sol::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("string")

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
