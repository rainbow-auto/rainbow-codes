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

struct Trie {
  struct Node {
    std::map<int, int> ch;
    std::vector<int> ed;
  };

  std::vector<Node> tr;

  Trie() { tr.push_back({}); }

  int mdf(int p, int c, int id) {
    // db << "mdf " << p << " " << c << " " << id << "\n";
    if (tr[p].ch.count(c)) {
      tr[tr[p].ch[c]].ed.push_back(id);
    } else {
      // db << "new " << tr.size() << "\n";
      tr[p].ch[c] = tr.size();
      tr.push_back({{}, {id}});
    }
    return tr[p].ch[c];
  }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> id(n + 1);
  Trie tr;
  rep(i, 1, n) {
    int x, y;
    std::cin >> x >> y;
    id[i] = tr.mdf(id[x], y, i);
    // db << "finish " << i << "\n";
  }

  std::vector<std::pair<int, int>> ans;

  int dpos = 0;
  auto dfs = [&](int now, auto &&dfs) -> void {
    dpos++;
    for (auto id : tr.tr[now].ed) {
      ans.push_back({dpos, id});
    }
    for (auto &p : tr.tr[now].ch) {
      int v = p.second;
      dfs(v, dfs);
    }
  };

  dfs(0, dfs);

  std::sort(ans.begin(), ans.end());
  for (auto [_, id] : ans) {
    std::cout << id << " ";
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
