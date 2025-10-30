#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for (int (_id) = (_st); (_id) <= (_ed); (_id)++)
#define per(_id, _st, _ed) for (int (_id) = (_st); (_id) >= (_ed); (_id)--)
#define db std::cerr
#define dbendl std::cerr << "\n"
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define file(x) std::freopen(x".in", "r", stdin); \
				std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";

typedef long long i64;

constexpr int maxn = 1000005;
constexpr int mod = 1e9 + 7;

int n;
int a[maxn];

namespace Sol {
	inline i64 ksm(i64 a, i64 b) {
		i64 res = 1;
		for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
		return res;
	} 
	
	struct Edge {
		int u, v;
		int pre;
	} es[maxn << 1];
	
	int last[maxn], cnt;
	
	int deg[maxn];
	inline void addEdge(int u, int v){
		es[++cnt] = Edge { u, v, last[u] };
		last[u] = cnt;
		deg[v]++;
	}

	int col[maxn], siz[maxn], tot;
	void dfs(int now) {
		col[now] = tot;
		siz[tot]++;
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (col[t]) continue;
			dfs(t);
		}
	}
	
	bool vis[maxn], visc[maxn];
	int c[maxn]; // 所在环的大小
    
    bool inc[maxn]; // 是否在环上
	
	inline void solve() {
		rep (i, 1, n) addEdge(a[i], i), addEdge(i, a[i]);
		
		rep (i, 1, n) {
			if (not col[i]) {
				tot++;
				dfs(i);
			}
		}

		rep (i, 1, n) {
			if (not visc[col[i]]) {
				visc[col[i]] = true;
				int now = i;
				std::vector<int> stk;
				while (true) {
					stk.push_back(now);
					vis[now] = true;
					if (vis[a[now]]) {
						int lst = -1;
						while (not stk.empty() and lst != a[now]) {
							lst = stk.back();
							c[col[i]]++;		
                            inc[lst] = true;
							stk.pop_back();
						}
						break;	
					}
					now = a[now];
				}
			}
		}
            
		// rep (i, 1, tot) db << siz[i] << " "; dbendl; 
		// rep (i, 1, tot) db << c[i] << " "; dbendl;

		i64 res = 0;
		rep (i, 1, n) {
            if (not inc[i]) {
                // db << "single\n";
                // db << ksm(2ll, n - 1) << "\n";
                (res += ksm(2ll, n - 1)) %= mod;
            } else {
                // db << "inc\n";
                // db << ksm(2ll, n - c[col[i]]) * (ksm(2ll, c[col[i]] - 1) + mod - 1) % mod << "\n";
                (res += ksm(2ll, n - c[col[i]]) * (ksm(2ll, c[col[i]] - 1) + mod - 1) % mod) %= mod;
            }
        }

		rep (i, 1, tot) (res += ksm(2ll, n - c[i])) %= mod;
		std::cout << res << "\n";
	}
}

inline void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	
	Sol::solve();
} 

int main() {
	fastread
	
    file("scc")

	solve();
	
	return 0;
}