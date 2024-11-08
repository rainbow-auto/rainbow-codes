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

#include <ctime>
#include <random>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 105;

struct Edge {
	int u, v;
};
vector <Edge> es;

int n, m;
int a[maxn][maxn];

inline double getDoubleRand () { return (double) rand () / RAND_MAX; }
inline Edge getRandomEdge () { return es[rand () % es.size ()]; }

inline void init () {
	for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) { a[i][j] = i == j ? 0 : 2; } }
}

inline void preProcess () {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i][j] == 2) { a[i][j] = 0; }
		}
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j] == 2) { a[i][j] = 1; es.push_back (Edge { i, j }); }
		}
	}
}

int baseSolution;
inline void getBaseSolution () {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (a[i][j] and a[j][k] and a[k][i]) { baseSolution ++; }
			}
		}
	}
}

inline int calc (Edge edge) {
	int f0 = 0; // 以前的状态
	for (int i = 1; i <= n; i++) {
		if (a[edge.u][edge.v] and a[edge.v][i] and a[i][edge.u]) { f0 ++; }
		if (a[edge.v][edge.u] and a[edge.u][i] and a[i][edge.v]) { f0 ++; }
	}

	int f1 = 0;
	swap (a[edge.u][edge.v], a[edge.v][edge.u]);
	for (int i = 1; i <= n; i++) {
		if (a[edge.u][edge.v] and a[edge.v][i] and a[i][edge.u]) { f1 ++; }
		if (a[edge.v][edge.u] and a[edge.u][i] and a[i][edge.v]) { f1 ++; }
	}
	swap (a[edge.u][edge.v], a[edge.v][edge.u]);

	return f1 - f0;
}

const double d = 0.9998;
const double eps = 1e-20;

inline void simulateAneal (int &ans) {
	double temp = 114514;
	int now = baseSolution;

	while (temp > eps) {
		Edge edge = getRandomEdge ();
		int delta = calc (edge);

		if (delta > 0) {
			swap (a[edge.u][edge.v], a[edge.v][edge.u]);
			now += delta;
			ans = max (ans, now);
		} else if (exp (delta / temp) > getDoubleRand ()) {
			swap (a[edge.u][edge.v], a[edge.v][edge.u]);
			now += delta;
		}
		
		temp *= d;
	}
}

int main () {
	fastread
	
	srand (time (0));

	cin >> n >> m;
	
	init ();
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 0;
	}

	preProcess ();
	
	if (es.size () == 0) { 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;
	}

	getBaseSolution ();
	int ans = baseSolution;

	int startTime = clock ();
	while (clock () - startTime < (double) CLOCKS_PER_SEC * 0.8) { simulateAneal (ans); }

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}
