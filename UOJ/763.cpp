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

#include <chrono>
#include <random>

using std::cin;
using std::cout;

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef unsigned long long ull;

const int maxn = 1000005;

int n;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
ull mask;

ull shift (ull x) {
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
}

ull hash[maxn];
std::set<ull> tr;

void dfs (int now, int fa) {
	hash[now] = 1;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		dfs (t, now);
		hash[now] += shift (hash[t]);
	}
	
	tr.insert (hash[now]);
}

int main () {
	fastread

	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}

	mask = rnd ();

	dfs (1, 0);

	cout << tr.size () << endl;

	return 0;
}
