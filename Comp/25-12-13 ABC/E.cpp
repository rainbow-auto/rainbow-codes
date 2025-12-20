#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread                                                               \
  std::ios::sync_with_stdio(false);                                            \
  std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n";
#define db std::cerr

#define lookMem                                                                \
  std::cerr << abs(&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double)clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x)                                                                \
  std::freopen(x ".in", "r", stdin);                                           \
  std::freopen(x ".out", "w", stdout);

constexpr int maxn = 300005;

struct DSU {
  std::vector<int> fa, siz;
  int n;
  DSU(int _n) {
    n = _n;
    fa = std::vector<int>(n + 1);
    siz = std::vector<int>(n + 1, 1);
    rep(i, 1, n) fa[i] = i;
  }

  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

  inline void mrg(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (siz[u] < siz[v]) std::swap(u, v);
    fa[v] = u;
    siz[u] += siz[v];
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1);

  rep(i, 1, n) std::cin >> p[i];

  DSU dsu(n);

  i64 ans = 0;
  rep(i, 1, n) { dsu.mrg(i, p[i]); }

  rep(i, 1, n) if (dsu.find(i) == i) {
    ans += 1ll * dsu.siz[i] * (dsu.siz[i] - 1) / 2;
  }

  std::cout << ans << "\n";
}

bool MemED;
int main() {
  fastread
  // lookMem

#ifndef MultiTask
      int _ = 1;
#else
      int _;
  std::cin >> _;
#endif

  while (_--) {
    solve();
  }

  return 0;
}
