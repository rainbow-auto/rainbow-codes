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

constexpr int mod = 1e9 + 7;

int n, q;

namespace Task1 {
    constexpr int maxn = 100005;

    std::vector<int> son[maxn];
    int siz[maxn];
    int fa[maxn];

    bool rmv[maxn];

    inline i64 ksm(i64 a, i64 b) {
        i64 res = 1;
        for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
        return res;
    }

    inline i64 inv(i64 x) {
        return ksm(x, mod - 2);
    }

    i64 fac[maxn], ifac[maxn];
    inline void init() {
        int N = 100000;
        fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod;
        ifac[N] = inv(fac[N]); per (i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }
    
    inline i64 choose(int a, int b) {
        if (a < b or a < 0 or b < 0) return 0;
        return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
    }

    i64 f[maxn];
    inline void upd(int now) {
        std::vector<int> son_now;
        for (auto t : son[now]) if (not rmv[t]) son_now.push_back(t);

        if (not son_now.size()) f[now] = 1;
        if (son_now.size() == 1) f[now] = f[son_now[0]];
        if (son_now.size() == 2) 
            f[now] = f[son_now[0]] * f[son_now[1]] % mod * choose(siz[son_now[0]] + siz[son_now[1]], siz[son_now[0]]) % mod;
    }

    void dfs(int now) {
        siz[now] = 1;
        for (auto t : son[now]) {
            dfs(t);
            siz[now] += siz[t];
        }
        upd(now);
    }

    inline void solve() {
        init();

        int tot = 1;
        rep (i, 1, n) {
            fa[i] = (i >> 1);
            son[fa[i]].push_back(i);
        }

        dfs(1);
        std::cout << f[1] << "\n";

        i64 cur = f[1];

        db << "ok1\n";

        while (q--) {
            int x; std::cin >> x;
            if (rmv[x]) {
                std::cout << cur << "\n";
                continue;
            }
            rmv[x] = true;

            int rt = x;
            while (fa[rt]) rt = fa[rt];

            // dbg(x);
            // dbg(rt);
            
            (cur *= inv(f[rt])) %= mod;
            // dbg(cur);

            (cur *= fac[siz[rt]]) %= mod;
            for (auto t : son[x]) (cur *= ifac[siz[t]]) %= mod;
            (cur *= ifac[siz[rt] - siz[x]]) %= mod;

            (cur *= ifac[n]) %= mod;
            n--;
            (cur *= fac[n]) %= mod; 

            // dbg(cur);

            int dt = siz[x];

            int now = x;
            while (now) {
                siz[now] -= dt;
                upd(now);
                now = fa[now];
            }

            // db << "upded\n";
            
            siz[x] = 0;
            for (auto t : son[x]) fa[t] = 0;

            // rep (i, 1, n) db << f[i] << " "; dbendl;

            if (rt != x) (cur *= f[rt]) %= mod;
            for (auto t : son[x]) if (not rmv[t]) (cur *= f[t]) %= mod;

            std::cout << cur << "\n";
            // dbendl;
        }
    }
}

void solve() {
    std::cin >> n >> q;

    Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("snake")

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
