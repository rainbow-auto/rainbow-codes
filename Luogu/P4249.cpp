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
const int maxm = 10005;

int n;
int a[maxn][maxn];

struct Edge {
	int u, v;
}; 
vector<Edge> es;

inline int initSolution () {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (a[i][j] == 1 and a[j][k] == 1 and a[k][i] == 1) { ans ++; }
				if (a[i][j] == 0 and a[j][k] == 0 and a[k][i] == 0) { ans ++; }
			}
		}
	}
	return ans;
}

inline int calc (Edge edge) {
	int u = edge.u, v = edge.v;
	
	int f0 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[u][v] and a[v][i] == 1 and a[i][u] == 1) { f0 ++; }
		else if (a[u][v] == 0 and a[u][i] == 1 and a[i][v] == 1) { f0++; }
	}

	swap (a[u][v], a[v][u]);	
	int f1 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[u][v] and a[v][i] == 1 and a[i][u] == 1) { f1 ++; }
		else if (not a[u][v] and a[u][i] == 1 and a[i][v] == 1) { f1++; }
	}
	swap (a[u][v], a[v][u]);	

	return f1 - f0;
}

inline double doubleRand () { return (double) rand() / RAND_MAX; }
inline Edge getRandEdge () { return es[rand() % int(es.size())]; }

const double d = 0.9998;
const double eps = 1e-19;

int initSol;

inline void simulateAnneal (int &ans) {
	double temp = 5000;
	int now = initSol;
	while (temp > eps) {
		Edge edge = getRandEdge ();
		int delta = calc (edge);
		
		if (delta > 0) {
			swap (a[edge.u][edge.v], a[edge.v][edge.u]);
			now += delta;
			ans = max (ans, now);
		} else if (exp (delta / temp) > doubleRand ()) {
			swap (a[edge.u][edge.v], a[edge.v][edge.u]);
			now += delta;
		}

		temp *= d;
	}
}

inline void preProcess () {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j] == 2) { es.push_back (Edge { i, j }); a[i][j] = 1; }
		}
		for (int j = 1; j < i; j++) { 
			if (a[i][j] == 2) { a[i][j] = 0; }
		}
	}
}

int main () {
	fastread
	srand (20090402);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	preProcess ();
	initSol = initSolution ();
	int ans = initSol;

	int startTime = clock ();
	while (clock () - startTime < (double) CLOCKS_PER_SEC * 1.5) { simulateAnneal (ans); }
	
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

