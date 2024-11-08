#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

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
bool MemST;

const int maxn = 200005;

int n, m;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int rt;

int siz[maxn];
void getrt (int now, int fa) {
	int mxsiz = 0;

	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
		getrt (t, now);
		siz[now] += siz[t];
		mxsiz = std::max (mxsiz, siz[t]);
	}
	mxsiz = std::max (mxsiz, n - siz[now]);

	if (mxsiz <= (n >> 1)) { rt = now; }
}

std::vector <int> subtree[maxn];
void getSubtree (int now, int fa, int curr) {
	subtree[curr].push_back (now);
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
		getSubtree (t, now, curr);
	}
}

struct Node {
	int id;
	int siz;

	friend bool operator < (Node a, Node b) { 
		if (a.siz != b.siz) { return a.siz > b.siz; }
		else { return a.id < b.id; }
	}
};

std::set <Node> sons;

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v); addEdge (v, u);
	}	

	getrt (1, 0);

	for (int i = last[rt]; i; i = es[i].pre) {
		int t = es[i].v;
		getSubtree (t, rt, t); 
		sons.insert (Node { t, (int) subtree[t].size () });
	}

	for (int i = 1; i <= (n >> 1); i++) {
		Node x = *sons.begin (); sons.erase (x);
		std::cout << subtree[x.id].back () << " ";
		subtree[x.id].pop_back ();

		if (sons.size ()) {
			Node y = *sons.begin (); sons.erase (y);
			std::cout << subtree[y.id].back () << "\n";
			subtree[y.id].pop_back ();

			if (subtree[y.id].size ()) { sons.insert (Node { y.id, (int) subtree[y.id].size () }); }
		} else {
			std::cout << rt << "\n";
		}
		
		if (subtree[x.id].size ()) { sons.insert (Node { x.id, (int) subtree[x.id].size () }); }
	}

	return 0;
}
