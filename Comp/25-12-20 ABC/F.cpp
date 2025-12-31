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

// (x, y) -> (x + y, x - y)
// mathattan distance ->
// chebyshev distance = max(|x1 - x2|, |y1 - y2|) = max(x1 - x2, x2 - x1, y1 -
// y2, y2 - y1)

constexpr int maxn = 200005;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct SegTree {
  struct Node {
    i64 mn, mx;

    friend Node operator+(const Node &a, const Node &b) {
      return Node{std::min(a.mn, b.mn), std::max(a.mx, b.mx)};
    }
  } tr[maxn << 2];

  SegTree() { std::fill(tr, tr + (maxn << 2), Node{-inf, inf}); }

  inline void pushUp(int now) { tr[now] = tr[now << 1] + tr[now << 1 | 1]; }

  void mdf(int now, int l, int r, int pos, i64 v) {
    if (l == r)
      return tr[now] = {v, v}, void();
    int mid = (l + r) >> 1;
    if (pos <= mid)
      mdf(now << 1, l, mid, pos, v);
    else
      mdf(now << 1 | 1, mid + 1, r, pos, v);
    pushUp(now);
  }

  Node qry(int now, int l, int r, int L, int R) {
    if (L <= l and r <= R)
      return tr[now];
    int mid = (l + r) >> 1;
    if (R <= mid)
      return qry(now << 1, l, mid, L, R);
    if (L > mid)
      return qry(now << 1 | 1, mid + 1, r, L, R);
    return qry(now << 1, l, mid, L, R) + qry(now << 1 | 1, mid + 1, r, L, R);
  }
} tr1, tr2;

void solve() {
  int n, q;
  std::cin >> n >> q;
  rep(i, 1, n) {
    i64 x, y;
    std::cin >> x >> y;
    tr1.mdf(1, 1, n, i, x + y);
    tr2.mdf(1, 1, n, i, x - y);
  }
  
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int p; std::cin >> p;
      i64 x, y;
      std::cin >> x >> y;
      tr1.mdf(1, 1, n, p, x + y);
      tr2.mdf(1, 1, n, p, x - y);
    } else {
      int l, r;
      std::cin >> l >> r;

      i64 x0, y0;
      std::cin >> x0 >> y0;
      i64 x = x0 + y0;
      i64 y = x0 - y0;

      auto res1 = tr1.qry(1, 1, n, l, r);
      auto res2 = tr2.qry(1, 1, n, l, r);

      i64 ans = INT_MIN;
      ans = std::max(ans, x - res1.mn);
      ans = std::max(ans, res1.mx - x);
      ans = std::max(ans, y - res2.mn);
      ans = std::max(ans, res2.mx - y);
      std::cout << ans << "\n";
    }
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
