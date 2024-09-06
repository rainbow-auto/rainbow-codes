#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 100005;

int n;
struct Pair {
	int key, val; // val 满足二叉搜索树的性质, key 满足堆的性质

	friend bool operator < (Pair x, Pair y) {
		return x.val < y.val;
	}
} a[maxn];

struct Node {
	int val;
	int ls, rs;
} tr[maxn];

inline int build () {
	std::sort (a + 1, a + n + 1);

	std::stack <int> rChain;
	rep (now, 1, n) {
		int last = 0;
		while (not rChain.empty () and a[rChain.top ()].key > a[now].key) { last = rChain.top (); rChain.pop (); }
		tr[rChain.empty () ? 0 : rChain.top ()].rs = now;
		tr[now].ls = last;
		tr[now].val = a[now].val;
		rChain.push (now);
	}
	return tr[0].rs;
}	

void dfs (int now) {
	if (not now) { return; }
	std::cout << tr[now].val << " ";
	dfs (tr[now].ls); dfs (tr[now].rs);
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, n) { int x; std::cin >> x; a[i] = Pair { i, x }; }

	int root = build ();
	dfs (root);
	
	return 0;
}
