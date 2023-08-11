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

const int maxn = 100005;
int n, m;

int hd[maxn];
int ind[maxn], otd[maxn]; // 入度, 出度
vector<int> g[maxn];

inline void addEdge (int u, int v) {
	g[u].push_back(v);
	otd[u] ++;
	ind[v] ++;
}

int s = 1;

bool check () {
	int ot_cnt = 0, in_cnt = 0;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (ind[i] != otd[i]) {
			flag = false;
			if (ind[i] - otd[i] == 1) { in_cnt ++; }
			else if (otd[i] - ind[i] == 1) { ot_cnt ++; s = i; } // 出度比入度多的这个点要作为起点
			else { return false; }
		}			
	}
	if (flag) { return true; } // 欧拉回路
	if (ot_cnt == 1 and in_cnt == 1) { return true; } // 欧拉路径
	return false;
}

stack<int> st;
void dfs (int now) {
	// cout << "vis " << now << endl;
	for (int &i = hd[now]; i < g[now].size(); ) {
		dfs (g[now][i++]);
	}
	st.push(now);
}

int main () {
	fastread

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		addEdge (u, v);
	}

	if (not check()) { cout << "No" << endl; return 0; }

	for (int i = 1; i <= n; i++) { sort(g[i].begin(), g[i].end()); }

	memset(hd, 0, sizeof(hd));
	dfs(s);

	while (not st.empty()) { cout << st.top() << " "; st.pop(); }
	cout << endl;

	return 0;
}
