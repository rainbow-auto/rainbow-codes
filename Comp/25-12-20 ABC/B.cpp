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
  int h, w; std::cin >> h >> w;
  int n; std::cin >> n;
  std::vector<std::vector<int>> a(h + 1, std::vector<int>(w + 1));
  rep (i, 1, h) rep (j, 1, w) std::cin >> a[i][j];

  std::set<int> b;
  rep (i, 1, n) {
    int x; std::cin >> x;
    b.insert(x);
  }

  int ans = 0;
  rep (i, 1, h) {
    int cnt = 0;
    rep (j, 1, w) cnt += b.count(a[i][j]);
    ans = std::max(ans, cnt);
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
