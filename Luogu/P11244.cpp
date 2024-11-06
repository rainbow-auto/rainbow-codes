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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

namespace FastIO {
	char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p1 = buf, p2 = (p1 + fread(buf, 1, 1 << 21, stdin))) == p1 ? EOF : *p1++)
	template <typename T> inline T read() { T x = 0, w = 0; char ch = getchar(); while (ch < '0' || ch > '9') w |= (ch == '-'), ch = getchar(); while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar(); return w ? -x : x; }
	template <typename T> inline void write(T x) { if (!x) return; write<T>(x / 10), putchar((x % 10) ^ '0'); }
	template <typename T> inline void print(T x) { if (x > 0) write<T>(x); else if (x < 0) putchar('-'), write<T>(-x); else putchar('0'); }
	template <typename T> inline void print(T x, char en) { print<T>(x), putchar(en); }
}; using namespace FastIO;

const int maxn = 2000005;
const int maxm = 23;

int n, m, q;
int a[maxm][maxn];
int p[maxm];

int t[maxn << 1];

std::bitset<maxm> srtd; // sorted

void solve() {
	// std::cin >> n >> m >> q;
	n = read<int>();
	m = read<int>();
	q = read<int>();

	rep (i, 1, m) {
		// rep (j, 1, n) std::cin >> a[i][j];
		rep (j, 1, n) a[i][j] = read<int>();
		p[i] = i; srtd[i] = false;
	}

	while (q--) {
		// int op; std::cin >> op;
		int op = read<int>();
		if (op == 1) {
			// int u, v; std::cin >> u >> v;
			int u = read<int>();
			int v = read<int>();
			int x = p[u]; int y = p[v];

			if (srtd[x] and srtd[y]) {
				if (a[y][1] >= a[x][n]) continue;
				if (a[x][1] >= a[y][n]) { std::swap(p[u], p[v]); continue; } 
			}

			rep (i, 1, n) t[i] = a[x][i];
			rep (i, 1, n) t[i + n] = a[y][i];

			std::sort(t + 1, t + (n << 1) + 1);

			rep (i, 1, n) a[x][i] = t[i];
			rep (i, 1, n) a[y][i] = t[i + n];

			srtd.set(x); srtd.set(y);
		} else {
			int i = read<int>();
			int j = read<int>();
			// std::cout << a[p[i]][j] << "\n";
			print(a[p[i]][j], '\n');
		}
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
