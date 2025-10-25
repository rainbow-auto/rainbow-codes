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

constexpr int maxn = 200005;

int n, m;

struct Edge {
    int u, v;
    int w;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

int d[maxn];
inline void addEdge(int u, int v, int w) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
}

namespace Task1 {
    constexpr int maxn = 2005;

    std::vector<int> f[maxn];
    bool operator < (const std::vector<int> &a, const std::vector<int> &b) { 
        if (a.size() != b.size()) return a.size() > b.size();
        int siz = a.size();
        per (i, siz - 1, 0) if (a[i] != b[i]) return a[i] < b[i];
        return false;
    }

    inline void solve() {
        std::queue<int> q;
        rep (i, 1, n) if (not d[i]) q.push(i);
        
        while (not q.empty()) {
            int now = q.front(); q.pop();
            for (int i = last[now]; i; i = es[i].pre) {
                int t = es[i].v;

                d[t]--;
                auto ft = f[now];
                ft.push_back(es[i].w);

                if (ft < f[t]) f[t] = ft;
                if (not d[t]) q.push(t);
            } 
        }

        rep (i, 1, n) {
            std::cout << f[i].size() << " ";
            i64 sum = 0;
            for (auto x : f[i]) sum += x;
            std::cout << sum << "\n";
        }
    }
}

namespace Task2 {
    i64 f[maxn];
    
    inline void solve(i64 w) {
        std::queue<int> q;
        rep (i, 1, n) if (not d[i]) q.push(i);
        
        while (not q.empty()) {
            int now = q.front(); q.pop();
            for (int i = last[now]; i; i = es[i].pre) {
                int t = es[i].v;
                
                d[t]--;
                f[t] = std::max(f[t], f[now] + 1);
                
                if (not d[t]) q.push(t);
            } 
        }
        
        rep (i, 1, n) {
            std::cout << f[i] << " ";
            std::cout << 1ll * w * f[i] << "\n";
        }
    }
}

namespace Task3 {
    std::tuple<int, int, i64> f[maxn];

    inline void solve() {
        rep (i, 1, n) f[i] = { 0, -0x3f3f3f3f, 0 };
        
        std::queue<int> q;
        rep (i, 1, n) if (not d[i]) q.push(i);
        
        while (not q.empty()) {
            int now = q.front(); q.pop();

            for (int i = last[now]; i; i = es[i].pre) {
                int t = es[i].v;
                d[t]--;
                auto ft = f[now];
                ft = {std::get<0>(ft) + 1, -es[i].w, std::get<2>(ft) + es[i].w};
                
                if (ft > f[t]) f[t] = ft;
                if (not d[t]) q.push(t);
            } 
        }

        rep (i, 1, n) {
            std::cout << std::get<0>(f[i]) << " ";
            std::cout << std::get<2>(f[i]) << "\n";
        }
    }
}

void solve() {
    std::cin >> n >> m;

    std::set<int> ws;
    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        int w; std::cin >> w;

        ws.insert(w);

        addEdge(v, u, w);
        d[u]++;
    }

    if (ws.size() == 1) return Task2::solve(*ws.begin()), void(0);
    if (ws.size() == m) return Task3::solve(), void(0);

    Task1::solve();
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
