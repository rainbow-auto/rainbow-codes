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

const int maxn = 10005;

int n;
int a[maxn];

struct List {
	struct Node {
		int pre, nxt;
		int val;
	} a[maxn];

	int tot, head, tail;
	int pos[maxn];

	inline void clear() {
		rep (i, 1, tot) a[i] = Node { 0, 0, 0 };
		tot = 0;
		head = 0, tail = n + 1;
	}

	inline void ins(int val) {
		int lst = tot;
		a[++tot] = Node { lst, tail, val };
		pos[val] = tot;
	}

	int mid;
	int midL, midR;
	inline void initMid() {
		mid = 0;
		
		int cur = 0;
		do {
			cur++;
			if (cur == ((tot + 1) >> 1)) break;
			mid = a[mid].nxt;
		} while (mid);

		midL = cur - 1;
		midR = tot - cur;
	}

	inline int getMid() { return a[mid].val; }

	inline void del(int x) {
		int p = pos[x];
		a[a[p].pre].nxt = a[p].nxt;
		a[a[p].nxt].pre = a[p].pre;
		
		// adjust mid
		
	}
} p;

int pos[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n) pos[a[i]] = i;

	rep (l, 1, n) {
		p.clear();
		rep (v, 1, n) if (pos[v] >= l) p.ins(v);

		
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
