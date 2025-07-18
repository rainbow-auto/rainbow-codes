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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;

int n;
int a[maxn], b[maxn], c[maxn];

int gcd(int a, int b) {
    if (not b) return a;
    return gcd(b, a % b);
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, n) std::cin >> b[i];

    rep (i, 1, n) c[i] = 1ll * a[i] / gcd(a[i], b[i]) * b[i];

    bool res = true;
    int g = 0;
    rep (i, 1, n) {
        g = gcd(g, c[i]);
        res &= (g == a[i]);
    }

    g = 0;
    per (i, n, 1) {
        g = gcd(g, c[i]);
        res &= (g == b[i]);
    }

    if (res) std::cout << "YES\n";
    else std::cout << "NO\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

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
