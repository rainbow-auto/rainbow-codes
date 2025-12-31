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
#define MultiTask lovely_fairytale
#define file(x)                                                                \
  std::freopen(x ".in", "r", stdin);                                           \
  std::freopen(x ".out", "w", stdout);

void solve() {
  int n;
  std::cin >> n;

  // tsum = pcur - wcur >= 0
  // 1: + p
  // 2: - w, +1
  // all: + p
  // mdf: - p - w, +1

  i64 tsum = 0, cnt = 0;

  std::vector<i64> a;
  rep(i, 0, n - 1) {
    int w, p;
    std::cin >> w >> p;
    i64 t = p + w;
    a.push_back(t);
    tsum += p;
  }

  std::sort(a.begin(), a.end());
  for (auto t : a) {
    if (tsum >= t) {
      tsum -= t;
      cnt++;
    } else {
      break;
    }
  }

  std::cout << cnt << "\n";
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
