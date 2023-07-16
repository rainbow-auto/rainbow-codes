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

const int maxn = 1005;


struct Matrix {
	int a[maxn][maxn], n, m;
	int num[maxn], tot;
		
	Matrix() {
		memset (a, 0, sizeof(a));
		memset (num, 0, sizeof(num));
		tot = 0;
	}

	Matrix (int siz) {
		siz = tot;
	}
	
	inline void indentity() {
		for (int i = 1; i <= tot; i++) {
			a[i][i] = tot;
		}
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
	
	int* operator [] (int i) {
		return a[i];	
	}	
	
	friend Matrix operator * (Matrix x, Matrix y) {
		Matrix res;
		int tot =  x.tot;
		for (int i = 1; i <= tot; i++) {
			for (int j = 1; j <= tot; j++) {
				for (int k = 1; k <= tot; k++) {
					res[i][j] = min(res[i][j], x[i][k] + y[k][j]);
				}
			}
		}
		return res;
	}
	
	friend Matrix operator ^ (Matrix a, int x) {
		Matrix res(a.tot); res.indentity();
		Matrix base = x;

		while (x) {
			if (x & 1) {
				res *= base;
			}
			x >>= 1;
			base *= base;
		}
	}
};

int main () {
	fastread
	
	return 0;
}
