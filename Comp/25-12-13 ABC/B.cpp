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
  int n; std::cin >> n;
  std::vector<std::vector<int>> a(n, std::vector<int>(n));

  int r = 0, c = (n - 1) / 2;
  a[r][c] = 1;
  rep (k, 2, (n * n)) {
    if (not a[((r - 1) % n + n) % n][((c + 1) % n + n) % n]) {
      (((r -= 1) %= n) += n) %= n;
      (((c += 1) %= n) += n) %= n;
    } else {
      (((r += 1) %= n) += n) %= n;
    }
    a[r][c] = k;
  }

  rep (i, 0, n - 1) rep (j, 0, n - 1) std::cout << a[i][j] << " \n"[j == n - 1];
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
