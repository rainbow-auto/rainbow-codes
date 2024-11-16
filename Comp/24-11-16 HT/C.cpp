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

unsigned seed, A, B, C;

inline unsigned rnd() {
	seed = A * seed * seed + B * seed + C;
	seed = seed ^ (seed << 27);
	seed = seed ^ (seed >> 19);
	return seed;
}

inline std::pair<int, int> gen() {
	int l, r;
	do {
		l = rnd() % n + 1;
		r = rnd() % n + 1;
	} while (abs(l - r) < 2);
	if (l > r) {
		std::swap(l, r);
	}
	return std::make_pair(l, r);
}

const int maxn = 100005;

inline int calc(std::vector<int> a) {
	int res = 0;
	rep (i, 1, ((int) a.size() - 1) - 2) {
		// a[i] a[i + 1] a[i + 2]
		std::vector<int> x;
		x.push_back(a[i]); x.push_back(a[i + 1]); x.push_back(a[i + 2]); std::sort(x.begin(), x.end());
		a.erase(i);
		res = std::min(res, calc(a));
		a.insert(i - 1, x[1]);
	}
}

int n, m;
int a[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n)
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
