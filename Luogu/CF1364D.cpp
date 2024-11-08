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

const int maxn = 500005;

int n, m, k;

int to[maxn], pre[maxn], last[maxn];
int cnt;

inline void addEdge (int u, int v) {
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

int dfn[maxn];
vector<int> stk;

int S, T, mn; // 最小环

void find_circle (int now) {
	stk.push_back(now);
	dfn[now] = stk.size();

	int nowcnt = 0;
	for (int i = last[now]; i; i = pre[i]) {
		int t = to[i];

		if (not dfn[t]) { find_circle(t); }	
		else if (dfn[t] == dfn[now] - 1) { nowcnt ++; } // 二元环

		if (dfn[t] < dfn[now] - 1 or nowcnt == 2) { 
			int len = dfn[now] - dfn[t] + 1;

			if (len <= k and len > 0) {
				cout << 2 << endl;
				cout << len << endl;

				for (int x = dfn[t] - 1; x <= dfn[now] - 1; x ++) {
					cout << stk[x] << " ";
				}
				cout << endl;

				exit(0); // 直接结束程序
			} else if (mn >= len) { // 找最小环
				mn = len;
				S = now, T = t;
			}
		}
	}

	stk.pop_back();
}

bool vis[maxn];
void output (int now) {
	stk.push_back (now);
	vis[now] = true;
	
	if (now == T) { // 到达终点
		cout << 1 << endl;
		for (int i = 0; i < k; i += 2) {
			cout << stk[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = last[now]; i; i = pre[i]) {
		int t = to[i];
		if (now == S and t == T) { continue; } // 特判掉
		if (vis[t]) { continue; }
		output (t);		
	}

	stk.pop_back();
}

bool col[maxn];
void color (int now, int fa, bool x) {
	col[now] = x;
	for (int i = last[now]; i; i = pre[i]) {
		int t = to[i];
		if (t == fa) { continue; } 
		color (t, now, x ^ 1);
	}
}

int main () {
	fastread

	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}
	memset (dfn, 0, sizeof(dfn));
	mn = n;
	find_circle(1);

	if (S) { // 有环 (不是树)
		memset (vis, 0, sizeof(vis));
		stk.clear();
		output (S);
	} else { // 没有环 (是树)
		color (1, -1, 1); // 直接染色求最大独立集

		vector<int> res0, res1;
		for (int i = 1; i <= n; i++) { 
			if (col[i] == 0) { res0.push_back(i); } 
			else { res1.push_back(i); }
		}

		int tot = 0;
		if (res0.size() >= (k + 1) / 2) {
			cout << 1 << endl;
			for (int i = 0; i < (k + 1) / 2; i++) { cout << res0[i] << " "; }
		} else {
			cout << 1 << endl;
			for (int i = 0; i < (k + 1) / 2; i++) { cout << res1[i] << " "; }
		}
	}

	return 0;
}
