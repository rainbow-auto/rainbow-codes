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

const int maxn = 5005;

int n;
int a[maxn][maxn];

bool vis[maxn];

void dfs (int u, int fa) {
	if (vis[u]) { return; }
	vis[u] = true;

	for (int v = 1; v <= n; v++) {
		if (a[u][v]) {
			if (a[v][fa]) { cout << fa << " " << u << " " << v << endl; exit (0); }
			dfs (v, u);
		}	
	}
}

int main () {
	fastread
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			a[i][j] = c == '1';
		}
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) { continue; }
		dfs (i, 0);
	}
	
	cout << -1 << endl;

	return 0;
}
