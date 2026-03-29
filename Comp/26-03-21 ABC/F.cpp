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

constexpr int maxn = 500005;
constexpr i64 MOD = 998244353;

int n, m;

struct Interval {
  int l, r;
  bool operator<(const Interval &other) const {
    if (l != other.l)
      return l < other.l;
    return r < other.r;
  }
} a[maxn];

i64 sum_tree[maxn << 2], mul_tag[maxn << 2];

void push_up(int node) {
  sum_tree[node] = (sum_tree[node << 1] + sum_tree[node << 1 | 1]) % MOD;
}

void apply_mul(int node, i64 tag) {
  sum_tree[node] = sum_tree[node] * tag % MOD;
  mul_tag[node] = mul_tag[node] * tag % MOD;
}

void push_down(int node) {
  if (mul_tag[node] != 1) {
    apply_mul(node << 1, mul_tag[node]);
    apply_mul(node << 1 | 1, mul_tag[node]);
    mul_tag[node] = 1; // 下传后清空标记
  }
}

void build(int node, int l, int r) {
  mul_tag[node] = 1;
  if (l == r) {
    sum_tree[node] = (l == 1 ? 1 : 0); // dp[0] = 1 对应线段树叶子位置 1
    return;
  }
  int mid = (l + r) >> 1;
  build(node << 1, l, mid);
  build(node << 1 | 1, mid + 1, r);
  push_up(node);
}

void update_add(int node, int l, int r, int pos, i64 val) {
  if (l == r) {
    sum_tree[node] = (sum_tree[node] + val) % MOD;
    return;
  }
  push_down(node);
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update_add(node << 1, l, mid, pos, val);
  else
    update_add(node << 1 | 1, mid + 1, r, pos, val);
  push_up(node);
}

void update_mult(int node, int l, int r, int ql, int qr, i64 val) {
  if (ql > qr)
    return;
  if (ql <= l && r <= qr) {
    apply_mul(node, val);
    return;
  }
  push_down(node);
  int mid = (l + r) >> 1;
  if (ql <= mid)
    update_mult(node << 1, l, mid, ql, qr, val);
  if (qr > mid)
    update_mult(node << 1 | 1, mid + 1, r, ql, qr, val);
  push_up(node);
}

i64 query(int node, int l, int r, int ql, int qr) {
  if (ql > qr)
    return 0;
  if (ql <= l && r <= qr)
    return sum_tree[node];
  push_down(node);
  int mid = (l + r) >> 1;
  i64 res = 0;
  if (ql <= mid)
    res = (res + query(node << 1, l, mid, ql, qr)) % MOD;
  if (qr > mid)
    res = (res + query(node << 1 | 1, mid + 1, r, ql, qr)) % MOD;
  return res;
}

void solve() {
  std::cin >> n >> m;

  rep(i, 1, m) {
    std::cin >> a[i].l >> a[i].r;
    a[i].r--; // 边 X -> Y 等同于覆盖区间 [X, Y-1]
  }

  std::sort(a + 1, a + m + 1);

  build(1, 1, n);

  rep(i, 1, m) {
    int l = a[i].l;
    int r = a[i].r;

    i64 S = query(1, 1, n, l, r + 1);

    if (r < n - 1) {
      update_mult(1, 1, n, r + 2, n, 2);
    }
    update_add(1, 1, n, r + 1, S);
  }

  i64 ans = query(1, 1, n, n, n);

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