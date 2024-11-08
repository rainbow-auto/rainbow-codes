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
int ind[maxn], otd[maxn];

vector<int> g[maxn];
inline void addEdge (int u, int v) {
	g[u].push_back(v);
	ind[v] ++;
	otd[u] ++;
}

int s = 1;
inline bool check () {
	bool flag = true;
	int ind_cnt = 0, otd_cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (ind[i] != otd[i]) {
			if (otd[i] - ind[i] == 1) { otd_cnt ++; s = i; }
			else if (ind[i] - otd[i] == 1) { ind_cnt ++; }
			else { return false; }
		}
	}
	if (flag) { return true; }
	if (ind_cnt == 1 and otd_cnt == 1) { return true; }
	return false;
}

stack<int> ans;
void dfs (int now) {
	for (int &i = hd[now]; i < g[now].size(); ) {
		dfs (g[now][i++]);
	}
	ans.push (now);
}

int main () {
	fastread
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		addEdge(u, v);
	}

	if (not check()) { cout << "No" << endl; return 0; }

	for (int i = 1; i <= n; i++) { sort(g[i].begin(), g[i].end()); }

	memset(hd, 0, sizeof(hd));
	dfs (s);

	while (not ans.empty()) { cout << ans.top() << " "; ans.pop(); }
	cout << endl;

	return 0;
}
