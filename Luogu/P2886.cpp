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

const int maxn = 210;

int num[1010], tot;
struct Matrix {
	int a[maxn][maxn];		
	Matrix() {
		memset (a, 0x3f, sizeof(a));
	}
	
	inline void addEdge(int u, int v, int w) {
		if (not num[u]) {
			num[u] = ++tot;
		}
		if (not num[v]) {
			num[v] = ++tot;
		}
		a[num[u]][num[v]] = w;
	}
	
};
Matrix operator * (Matrix x, Matrix y) {
	Matrix res;
	for (int k = 1; k <= tot; k++) {
	    for (int i = 1; i <= tot; i++) {
		    for (int j = 1; j <= tot; j++) {
				res.a[i][j] = min(res.a[i][j], x.a[i][k] + y.a[k][j]);
			}
		}
	}
	return res;
}
Matrix ksm (Matrix a, int x) {
	Matrix res;
    res=a;
	while (x) {
		if (x & 1) {
			res = res * a;
		}
		x >>= 1;
		a = a * a;
	}
	return res;
}

Matrix g;

int n, m, s, t;

int main () {
	fastread

	cin >> n >> m >> s >> t;
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> w >> u >> v;
		g.addEdge (u, v, w);
		g.addEdge (v, u, w);
	}
	
	Matrix res;
	res = ksm(g , (n-1));
	
	cout << res.a[num[s]][num[t]] << endl;

	return 0;
}
