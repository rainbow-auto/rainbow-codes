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
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 11;
constexpr int mod = 998244353;

int n, m;

int a[maxn];
int p[maxn], pp[maxn];

void solve() {
	std::cin >> n >> m;
    while (m--) {
        int x, y; std::cin >> x >> y;
        a[x] = y;
    }

    rep (i, 1, n) p[i] = i;
    p[n + 1] = 0x3f3f3f3f;

    int ans = 0;
    do {
        bool flg = true;
        rep (i, 1, n) {
            if (a[i] and p[i] != a[i]) {
                flg = false; break;
            }
        }
        if (not flg) continue;

        std::memcpy(pp, p, sizeof p);
        int S = 0;
        while (true) {
            int mn = 0;
            rep (i, 1, n - 1) {
                if (p[i] > mn and p[i] > p[i + 1]) S++;

                if (i == 1) mn = p[1];
                mn = std::min(mn, p[i]);
            }

            rep (i, 1, n - 1) {
                if (p[i] > p[i + 1]) std::swap(p[i], p[i + 1]);
            }

            bool up = true;
            rep (i, 1, n) up &= (p[i] == i);
            if (up) {
                (ans += S) %= mod;
                break;
            }
        }

        std::memcpy(p, pp, sizeof pp);
    } while (std::next_permutation(p + 1, p + n + 1));

    std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem
    
    file("permutation")

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
