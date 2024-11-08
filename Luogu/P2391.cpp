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

const int maxn = 10000005;

int n, m;
int p, q;
int a[maxn];

int fa[maxn];
inline void init () { 
	for (int i = 1; i <= n; i++) { fa[i] = i; }
}

int find (int x) {
	if (x == fa[x]) { return fa[x]; }
	else { return fa[x] = find (fa[x]); }
}

int main () {
	fastread
	
	cin >> n >> m >> p >> q;

	init ();

	for (int i = m; i >= 1; i--) { // 倒序
		int l = (i * p + q) % n + 1;
		int r = (i * q + p) % n + 1;

		if (l > r) { swap (l, r); }

		int pos = r;
		while (pos >= l) { 
			if (find(pos) == pos) { a[pos] = i; fa[pos] = find (pos - 1); } // 未被染过色 
			pos = fa[pos];
		}
	}

	for (int i = 1; i <= n; i++) { cout << a[i] << endl; }

	return 0;
}
