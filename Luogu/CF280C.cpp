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

const int maxn = 200005;

int n;

int to[maxn], pre[maxn], last[maxn];
int cnt;
inline void addEdge (int u, int v) {
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

long double dep[maxn];
void dfs (int now) {
	for (int i = last[now]; i; i = pre[i]) {
		int t = to[i];
		if (dep[t]) { continue; }
		dep[t] = dep[now] + 1;
		dfs (t);
	}
}

int main () {
	fastread

	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int a, b; cin >> a >> b;
		addEdge (a, b);
		addEdge (b, a);
	}

	dep[1] = 1;
	dfs (1);	


	long double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (1.0f / dep[i]);
	}

	printf ("%.20Lf\n", ans);

	return 0;
}
