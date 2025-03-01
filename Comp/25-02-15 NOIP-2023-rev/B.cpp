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

const int maxn = 200005;

int n, m;

struct Node {
	int fa;
	int r; // rev cnt
} a[maxn];

int tot;
int U, T, F;

int val[maxn];

inline void mrg(int now, int v) {
	if (v == -1) val[now] = -1;
	else val[now] = v * ((a[now].r & 1) ^ 1);
}

std::bitset<maxn> vis;

std::bitset<maxn> ins;
std::stack<int> st;
void dfs(int now) {
	if (vis[now]) return;

	st.push(now);
	ins.set(now);
	vis.set(now);
	if (ins[a[now].fa]) {
		int sum = 0;

		int tp;
		do {
			tp = st.top();
			sum += a[tp].r;
			ins.reset(tp);
			st.pop();
		} while (tp != a[now].fa);

		if (sum & 1) val[now] = -1;
		else mrg(now, val[a[now].fa]);
		
		return;
	}

	dfs(a[now].fa);

	mrg(now, val[a[now].fa]);

	if (ins[now]) {
		st.pop();
		ins.reset(now);
	}
}

void solve() {
	std::memset(val, 0, sizeof val);
	std::memset(a, 0, sizeof a);
	vis.reset();
	ins.reset();

	std::cin >> n >> m;
	
	tot = n;
	U = ++tot;
	T = ++tot;
	F = ++tot;
	rep (i, 1, tot) a[i] = Node { i, 0 };

	while (m--) {
		char c; std::cin >> c;
		int u; std::cin >> u;
		if (c == '+') {
			int v; std::cin >> v;
			a[u].fa = a[v].fa;
			a[u].r = a[v].r;
		} else if (c == '-') {
			int v; std::cin >> v;
			a[u].fa = a[v].fa;
			a[u].r = a[v].r + 1;
		} else if (c == 'U') {
			a[u].fa = U;
			a[u].r = 0;
		} else if (c == 'T') {
			a[u].fa = T;
			a[u].r = 0;
		} else if (c == 'F') {
			a[u].fa = F;
			a[u].r = 0;
		}
	}

	// rep (i, 1, n) db << i << " : " << a[i].fa << " rev: " << a[i].r << "\n";

	val[U] = -1;
	val[T] = 1;
	val[F] = 0;
	vis.set(U); vis.set(T); vis.set(F);

	rep (i, 1, n) {
		if (a[i].fa == T) {
			mrg(i, 1); // T : 1 | F : 0
			vis.set(i);
		} else if (a[i].fa == F) {
			mrg(i, 0); // T : 1 | F : 0
			vis.set(i);
		} else if (a[i].fa == U) {
			mrg(i, -1);
			vis.set(i);
		}
	}

	// rep (i, 1, n) db << val[i] << " ";
	// dbendl;

	rep (i, 1, n) {
		if (not vis[i]) dfs(i);
	}

	int ans = 0;
	rep (i, 1, n) ans += (val[i] == -1);
	std::cout << ans << "\n";
} 
	
bool MemED;
int main() {
	fastread
	// lookMem	

	// file("tribool4")

	int c; std::cin >> c;

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

/*
1 1
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/

/*
1 1
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3
*/

/*
1 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
*/