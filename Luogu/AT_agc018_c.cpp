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

#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 100005;

int n;
int x, y, z;

struct Node {
	int e, f;
	friend bool operator < (Node a, Node b) {
		return a.e + b.f > a.f + b.e;
	}
} t[maxn];

i64 pre[maxn], suf[maxn];

void solve() {
	std::cin >> x >> y >> z;
	n = x + y + z;
	i64 sum = 0;
	rep (i, 1, n) {
		int a, b, c; std::cin >> a >> b >> c;
		t[i] = Node { b - a, c - a };
		sum += a;
	}

	std::sort(t + 1, t + n + 1);

	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	rep (i, 1, n) {
		pre[i] = pre[i - 1] + t[i].e;
		q.push(t[i].e);
	
		if (q.size() > y) {
			pre[i] -= q.top(); q.pop();
		} 
	}

	while (not q.empty()) q.pop();

	per (i, n, 1) {
		suf[i] = suf[i + 1] + t[i].f;
		q.push(t[i].f);
		if (q.size() > z) {
			suf[i] -= q.top(); q.pop();
		}
	}

	i64 ans = -0x3f3f3f3f3f3f3f3f;
	rep (i, y, n - z) ans = std::max(ans, pre[i] + suf[i + 1]);
	std::cout << sum + ans << "\n";
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
