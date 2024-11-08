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

const int maxn = 2000005;

int to[maxn], pre[maxn], last[maxn], ind[maxn];
int cnt;

inline void addEdge (int u, int v) {
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	ind[v] ++;
	last[u] = cnt;
}

int n, a[maxn];

bool d[maxn];
void topo () {
	memset (d, 0, sizeof(d));
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}

	while (not q.empty()) {
		int u = q.front(); q.pop();

		for (int i = last[u]; i; i = pre[i]) {
			int v = to[i];
			ind[v] --;
			d[v] |= !(d[u]); // 到每个节点的d值中有一个是0, 那个节点就可以是1
			if (ind[v] == 0) {
				q.push(v);
			}
		}
	}
}

int main () {
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> a[i]; }

	for (int i = 1; i <= n; i++) {
		for (int j = i + a[i]; j <= n; j += a[i]) {
			if (a[i] < a[j]) { addEdge (j, i); } // i能到j, j转移到i
		}
		for (int j = i - a[i]; j >= 1; j -= a[i]) {
			if (a[i] < a[j]) { addEdge (j, i); } // 同理反向建边
		}
	}

	topo ();

	for (int i = 1; i <= n; i++) {
		cout << (d[i] ? "A" : "B");
	}
	cout << endl;

	return 0;
}
