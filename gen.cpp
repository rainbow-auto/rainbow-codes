#include <bits/stdc++.h>

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
inline int get(int l, int r) {
  if (l == r) return l;
  return l + rnd() % (r - l + 1);
}

int main() {
  int n = 10, m = 13, q = 30, s = 15;
  printf("%d %d\n", n, m);
  for (int i = 0; i < m; i++) {
    int u = get(1, n), v = get(1, n);
    while (u == v) v = get(1, n);
    int w = get(1, s);
    printf("%d %d %d\n", u, v, w);
  }
  printf("%d\n", q);
  while (q--) {
    int op = get(1, 2);
    if (op == 1) {
      printf("1 %d %d\n", get(1, m), get(1, s));
    } else {
      printf("2 %d %d\n", get(1, n), get(1, s));
    }
  }
  return 0;
}
