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
#define file(x) std::freopen(x".in", "w", stdout);

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

constexpr int maxn = 55;

char a[maxn];
inline void get(int i) {
    int x = rng() % 9;
    if (x == 0) a[i] = '[';
    if (x == 1) a[i] = ']';
    if (x == 2) a[i] = '(';
    if (x == 3) a[i] = ')';
    if (x == 4) a[i] = '<';
    if (x == 5) a[i] = '>';
    if (x == 6) a[i] = '{';
    if (x == 7) a[i] = '}';
    if (x == 8) a[i] = '?';
}

void solve() {
    int n = 20;
    rep (i, 1, n) get(i);

    rep (i, 1, n) std::cout << a[i]; std::cout << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem
    
    file("bracket")

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
