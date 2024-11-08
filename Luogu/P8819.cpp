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
#include <random>
#include <chrono>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 500005;

#define int unsigned long long

int n, m, q;

int r[maxn], w[maxn];
int s[maxn];

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

signed main () {
	fastread

	cin >> n >> m;

	int sum = 0;	
	for (int i = 1; i <= n; i++) {
		w[i] = rnd();
	}

	int now = 0; // 当前的总和
	while (m --) {
		int u, v; cin >> u >> v;
		r[v] += w[u];
		s[v] += w[u];
	}

	for (int i = 1; i <= n; i++) { sum += w[i]; }
	for (int i = 1; i <= n; i++) { now += r[i]; }

	cin >> q;
	while (q--) {
		int op; cin >> op;

		switch(op) {
			case 1: {
				int u, v; cin >> u >> v;
				r[v] -= w[u];
				now -= w[u];
				break;
			}
			case 2: {
				int v; cin >> v;
				now -= r[v];
				r[v] -= r[v]; // r[v] = 0;
				break;
			}
			case 3: {
				int u, v; cin >> u >> v;
				r[v] += w[u];
				now += w[u];
				break;
			}
			case 4: {
				int v; cin >> v;
				now += s[v] - r[v];
				r[v] += s[v] - r[v]; // r[v] = g[v];
				break;
			}
		}

		if (now == sum) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}

	return 0;
}
