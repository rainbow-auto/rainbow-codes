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

#define int long long

const int maxn = 505;
const int maxm = 130050; // 255 * 255

int n, m, k;
int a[maxn][maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxm];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}


bool vis[maxn];
int match[maxn];
int find (int now) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (vis[t]) { continue; }
		vis[t] = true;

		if (not match[t] or find (match[t])) { match[t] = now; return 1; }
	}

	return 0;
}

inline void clear () {
	memset (last, 0, sizeof(last));
	memset (match, 0, sizeof(match));
	cnt = 0;
}

int Hungrey () {
	int res = 0;
	for (int i = 1; i <= n; i++) { memset (vis, 0, sizeof (vis)); res += find(i); }
	return res;
}

inline void buildGraph (int mid) {
	clear ();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] <= mid) { addEdge (i, j + n); }		
		}
	}
}

inline bool check (int mid) {
	buildGraph (mid);	
	return Hungrey () > n - k;
}

signed main () {
	fastread
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int l = 0, r = 1e9;
	int ans = -1;

	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check (mid)) { ans = mid; r = mid - 1; }
		else { l = mid + 1; }
	}

	cout << ans << endl;

	return 0;
}
