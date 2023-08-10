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

typedef unsigned long long ll;

int to[maxn], pre[maxn], last[maxn];
int cnt;
ll w[maxn];

inline void addEdge (int u, int v, ll ww) {
	cnt ++;
	to[cnt] = v;
	w[cnt] = ww;
	pre[cnt] = last[u]; 
	last[u] = cnt;
}

namespace Basis {
	ll a[maxn];

	inline void insert (ll x) {
		for (int i = 63; i >= 0; i--) {
			if (not (x & (1ll << i))) { continue; }
			if (a[i]) { x ^= a[i]; }
			else { a[i] = x; return; }
		}
	}

	inline ll query (ll x) {
		for (int i = 63; i >= 0; i--) {
			if ((x ^ a[i]) > x) { x ^= a[i]; }
		}
		return x;
	}
};

bool vis[maxn];
ll dis[maxn];
void dfs (int now, ll s) {
	dis[now] = s;
	vis[now] = true;
	for (int i = last[now]; i; i = pre[i]) {
		int t = to[i];
		if (not vis[t]) { dfs(t, s ^ w[i]); }
		else { Basis::insert(s ^ dis[t] ^ w[i]); }
	}
}

int main () {
	fastread
	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; ll ww;
		cin >> u >> v >> ww;
		addEdge(u, v, ww); addEdge(v, u, ww);
	}

	dfs(1, 0);

	cout << Basis::query(dis[n]) << endl;

	return 0;
}
