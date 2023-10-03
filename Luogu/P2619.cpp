#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 50005;
const int maxm = 200005;

int n, m;
int need;

struct Edge {
	int u, v;
	int w, add;
	int col;

	friend bool operator < (Edge a, Edge b) {
		int a_w = a.add + a.w;
		int b_w = b.add + b.w;

		if (a_w != b_w) { return a_w < b_w; }
		else { return a.col < b.col; }
	}
};

vector<Edge> es;

int fa[maxn];
int find (int x) {
	if (fa[x] == x) { return fa[x]; }
	else { return fa[x] = find (fa[x]); }
}

int mst;
inline bool check (int mid) {
	for (auto &e : es) { e.add = (e.col == 0) ? mid : 0; }	
	for (int i = 1; i <= n; i++) { fa[i] = i; }

	// kruskal
	sort (es.begin (), es.end ());

	mst = 0;

	int tot = 0;
	int whiteCnt = 0;
	for (auto e : es) {
		int u = find (e.u);
		int v = find (e.v);

		if (u == v) { continue; }

		fa[v] = u;
		whiteCnt += e.col == 0;
		mst += e.w + e.add;

		if (++tot == n - 1) { break; }
	}
	
	for (auto &e : es) { e.add = 0; }

	return whiteCnt >= need;
}

void solve () {
	int l = -200, r = 200;

	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;

		if (check (mid)) {
			l = mid + 1;
			// 修改了最后要重新跑一遍kruskal的丑陋写法
			ans = mst - mid * need;
		} else {
			r = mid - 1;
		}
	}

	cout << ans << endl;
}	

int main () {
	fastread
	
	cin >> n >> m >> need;

	for (int i = 1; i <= m; i++) {
		int u, v, w, c; cin >> u >> v >> w >> c;
		es.push_back ( Edge { u + 1, v + 1, w, 0, c } );
	}

	solve ();

	return 0;
}

/*
add: 0 ok mst = 192
add: 100 
add: 50 
add: 25 
add: 12 ok mst = 273
add: 18 ok mst = 301
add: 21 ok mst = 310
add: 23 
add: 22 
mst: 312
res: 21
need: 3
249
*/