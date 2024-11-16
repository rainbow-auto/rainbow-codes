#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

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

const int maxn = 100005;

int n;
struct Node {
	i64 k, d, a;
	int id;

	inline i64 calc() {
		if (k - d >= 10) return k * (k - d) + a;
		if (k >= d) return (k - d + 1) * 3 + a;
		return a * 2;
	}

	friend bool operator < (Node a, Node b) {
		return a.calc() > b.calc();
	}
} a[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> a[i].k;
		char _; std::cin >> _;
		std::cin >> a[i].d;
		char __; std::cin >> __;
		std::cin >> a[i].a;
		a[i].id = i;
	}

	std::sort(a + 1, a + n + 1);

	std::cout << a[1].id << "\n";
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
