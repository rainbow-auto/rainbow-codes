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
constexpr int maxn = 500005;

int n;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];
int last[maxn], cnt;

inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

namespace Task1 {
	i64 f[maxn];
	void dfs(int now, int fa) {
		i64 sum = 0;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now);
			(sum += f[t]) %= mod;
        }
		f[now] = (sum + sum + 1) % mod;
	}

    inline void solve() {
        i64 ans = 0;
        
        rep (now, 1, n) {
            i64 res = 0;
            dfs(now, 0);
            i64 pre = 1;
            for (int i = last[now]; i; i = es[i].pre) {
                int t = es[i].v;
                (res += pre * f[t] % mod) %= mod;
				(pre += f[t]) %= mod;
            }

            ans ^= 1ll * now * res;
        }

        std::cout << ans << "\n";
    }     
}

namespace Task2 {
	i64 f[maxn];
	void dfs(int now, int fa) {
		i64 sum = 0;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now);
			(sum += f[t]) %= mod;
        }
		f[now] = (2ll * sum + 1) % mod;
	}

	i64 ans;
	inline void calc(int now) {
		// db << "calc " << now << "\n";
		// db << "f: "; rep (i, 1, n) db << f[i] << " "; dbendl;

		i64 res = 0;
		i64 pre = 1;
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			(res += pre * f[t] % mod) %= mod;
			(pre += f[t]) %= mod;
		}
		// db << res << "\n";

		ans ^= 1ll * now * res;
	}

	void chrt(int now, int fa) {
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == fa) continue;

			i64 ft = f[t], fnow = f[now];

			(((f[now] -= 2 * f[t] % mod) %= mod) += mod) %= mod;
			(f[t] += 2 * f[now] % mod) %= mod;
			calc(t);

			chrt(t, now);

			f[t] = ft;
			f[now] = fnow;
		}
	}

	inline void solve() {
		dfs(1, 0);
		calc(1);

		chrt(1, 0);

		std::cout << ans << "\n";
	}
}

void solve() {
    std::cin >> n;
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    // Task1::solve();
    Task2::solve();
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

