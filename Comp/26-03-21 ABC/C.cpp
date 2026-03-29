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

constexpr int maxn = 1005;

int n, m;
int a[maxn][maxn];
int col[maxn][maxn];

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int c) {
  col[x][y] = c;
  rep(k, 0, 3) {
    int ty = y + dy[k], tx = x + dx[k];
    if (ty < 1 or ty > m or tx < 1 or tx > n)
      continue;
    if (not a[tx][ty] or col[tx][ty])
      continue;
    dfs(tx, ty, c);
  }
}

void solve() {
  std::cin >> n >> m;

  rep(i, 1, n) rep(j, 1, m) {
    char c;
    std::cin >> c;
    a[i][j] = c != '#';
  }

  int t = 0;
  rep (i, 1, n) if (a[i][1] and not col[i][1]) dfs(i, 1, ++t);
  rep (j, 1, m) if (a[1][j] and not col[1][j]) dfs(1, j, ++t);
  rep (i, 1, n) if (a[i][m] and not col[i][m]) dfs(i, m, ++t);
  rep (j, 1, m) if (a[n][j] and not col[n][j]) dfs(n, j, ++t);

  int t0 = t;
  rep (i, 2, n - 1) rep (j, 2, m - 1) if (a[i][j] and not col[i][j]) dfs(i, j, ++t);

  std::cout << t - t0 << "\n";
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
