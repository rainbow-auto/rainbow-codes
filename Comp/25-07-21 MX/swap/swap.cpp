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

constexpr int maxn = 100005;
constexpr int maxk = 200005;

int n, k;
int a[maxk], b[maxk];

// namespace Task1 {
//     constexpr int maxn = 5005;

//     int circle[maxn * maxn], tot;

//     int to[maxn * maxn];
//     std::stack<int> st;
//     std::bitset<maxn * maxn> ins;

//     std::set<int> col[maxn * maxn];

//     void find_circle(int now) {
//         if (circle[now]) return;
//         circle[now] = tot;

//         st.push(now); ins.set(now);

//         if (ins[to[now]]) {
//             while (s.top() != t) {
//                 int x = s.top(); s.pop();
//                 col[tot].insert(c[x]);
//             }
//         }

//         find_circle(to[now]);
//     }

//     inline void solve() {
//         dfs(1);
//     }
// }

namespace Task2 {
    int p[maxn];

    std::set<int> to[maxn];

    inline void solve() {
        rep (i, 1, n) p[i] = i;
        rep (i, 1, n) to[i].insert(i);

        rep (i, 1, n * k) {
            int u = a[(i - 1) % k + 1];
            int v = b[(i - 1) % k + 1];
            std::swap(p[u], p[v]);
            to[p[u]].insert(u);
            to[p[v]].insert(v);
        }

        rep (i, 1, n) std::cout << to[i].size() << "\n";
    }
}

void solve() {
	std::cin >> n >> k;
    rep (i, 1, k) std::cin >> a[i] >> b[i];

    Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("swap")

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
