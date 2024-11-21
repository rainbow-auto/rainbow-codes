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

const int maxn = 2005;

int n, H;
struct Node {
	int a, b;
	friend bool operator < (Node a, Node b) {
		if (a.a + a.b != b.a + b.b) return a.a + a.b < b.a + b.b;
		return a.a < b.a;
	}
} a[maxn];

i64 f[maxn];

void solve() { 
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i].a >> a[i].b;
	std::cin >> H;

	std::sort(a + 1, a + n + 1);

	std::memset(f, -0x3f, sizeof f);
	f[0] = 0;
	rep (i, 1, n) f[0] += a[i].a;

	rep (i, 1, n) {
		per (j, i, 1) {
			if (f[j - 1] + a[i].b >= H) {
				f[j] = std::max(f[j], f[j - 1] - a[i].a);
			}
		}
	}

	per (j, n, 0) {
		if (f[j] >= 0) {
			std::cout << j << "\n";
			break;
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
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
