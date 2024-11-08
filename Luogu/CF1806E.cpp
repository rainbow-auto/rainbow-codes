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

typedef long long ll;

const int maxn = 100005;
const int sqrt_n = 505;

int n, q;

int fa[maxn], dep[maxn], cnt[maxn], id[maxn];
ll a[maxn], pre[maxn], mem[maxn][sqrt_n];

ll dfs (int x, int y) {
	if (x == y) { // 正好跳到lca上
		return pre[x];
	} else if (cnt[dep[y]] <= 500) { // 对于点个数小于 sqrt_n 的点进行记忆化
		if (mem[x][id[y]]) {
			return mem[x][id[y]];
		} else {
			return mem[x][id[y]] = dfs (fa[x], fa[y]) + a[x] * a[y];
		}
	} else {
		return dfs (fa[x], fa[y]) + a[x] * a[y];
	}
}

int main () {
	fastread

	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	pre[1] = a[1] * a[1];
	for (int i = 2; i <= n; i++) {
		cin >> fa[i];

		pre[i] = a[i] * a[i] + pre[fa[i]];
		dep[i] = dep[fa[i]] + 1; 
		id[i] = ++cnt[dep[i]]; // 可能有多个相同深度的点, 这里给他们编号
	}

	while (q--) {
		int x, y; cin >> x >> y;
		cout << dfs (x, y) << endl;
	}

	return 0;
}
