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

const int maxn = 800020;
const int delta = 200005;

int to[maxn], pre[maxn], last[maxn];
int cnt = 1;
inline void _addEdge (int u, int v) {
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

int deg[maxn];
inline void addEdge (int u, int v) {
	_addEdge(u, v); deg[u] ++;
	_addEdge(v, u); deg[v] ++;
}

int n;

int color[maxn];
void dfs (int now) {
	for (int &i = last[now]; i; i = pre[i]) {
		int t = to[i];
		if (color[i >> 1]) { continue; } // 原来的点变成了边, 双向边, 真实的点的编号要除2
		color[i >> 1] = 1 + (now <= delta); // <= delta 的是横坐标
		dfs (t);
	}
}

int main () {
	fastread
	
	cin >> n;

	for (int i = 1; i <= n; i++) { int x, y; cin >> x >> y; addEdge (x, y + delta); }

	for (int i = 1; i <= (delta << 1); i++) {
		if (deg[i] & 1) { addEdge(i, 0); }
	}

	for (int i = 1; i <= delta; i++) { dfs(i); } // 对于每个连通块, 进行dfs

	for (int i = 1; i <= n; i++) { cout << "br"[color[i] - 1]; }  
	cout << endl;

	return 0;
}
