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

void solve() {
  int h, w;
  std::cin >> h >> w;

  auto getID = [w](int r, int c) { return (r - 1) * w + c; };

  int tot = getID(h, w);
  std::vector<std::vector<std::pair<int, int>>> g(tot + 256);

  std::vector<std::vector<char>> a(h + 2, std::vector<char>(w + 2, '#'));

  rep(i, 1, h) rep(j, 1, w) { std::cin >> a[i][j]; }

  std::vector<int> dx = {-1, 1, 0, 0};
  std::vector<int> dy = {0, 0, -1, 1};

  rep(i, 1, h) rep(j, 1, w) {
    if (a[i][j] == '#')
      continue;

    rep(k, 0, 3) {
      int tx = i + dx[k];
      int ty = j + dy[k];
      if (a[tx][ty] != '#') {
        g[getID(i, j)].push_back({getID(tx, ty), 1});
      }
    }

    if (a[i][j] == '.')
      continue;

    g[tot + (a[i][j] - 'a') + 1].push_back({getID(i, j), 0});
    g[getID(i, j)].push_back({tot + (a[i][j] - 'a') + 1, 1});
  }

  auto dij = [&](int st, int ed) -> int {
    std::vector<int> dis(tot + 256, 0x3f3f3f3f);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    pq.push({0, st});
    dis[st] = 0;

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dis[u])
        continue;
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          pq.push({dis[v], v});
        }
      }
    }
    return dis[ed];
  };

  int d = dij(getID(1, 1), getID(h, w));
  if (d == 0x3f3f3f3f) {
    std::cout << -1 << "\n";
  } else {
    std::cout << d << "\n";
  }
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
