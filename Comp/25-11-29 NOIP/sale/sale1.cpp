#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".ans", "w", stdout);

constexpr int maxn = 5005;
constexpr int mod = 998244353;

int n, m;
i64 a[maxn];

inline bool chk(int S) {
    std::vector<int> f(m + 1);

    auto add = [&](std::vector<int> &f, int w, int v) -> void {
        per (i, m - w, 0) f[i + w] = std::max(f[i + w], f[i] + v);
    };

    rep (i, 1, n) {
        if (S & (1 << (i - 1))) {
            add(f, 2, a[i]);
        } else {
            add(f, 1, a[i]);
        }
    }

    std::vector<std::pair<std::pair<int, int>, int>> b;
    rep (i, 1, n) {
        if (S & (1 << (i - 1))) b.push_back({{ -a[i], -a[i] }, 2});
        else b.push_back({{ -a[i] * 2, -a[i] }, 1});
    }

    std::sort(b.begin(), b.end());

    int rst = m;
    i64 res = 0;
    for (auto [v, w] : b) {
        if (rst >= w) {
            rst -= w;
            res += (-v.second);
        }
    }

    return res == f[m];
}

void solve() {
    std::cin >> n >> m;
    rep (i, 1, n) std::cin >> a[i];
    
    std::sort(a + 1, a + n + 1);
    std::reverse(a + 1, a + n + 1);

    int ans = 0;
    rep (S, 0, (1 << n) - 1) {
        if (chk(S)) {
            ans++;
        }
    }

    std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("sale")

    int __; std::cin >> __;

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
