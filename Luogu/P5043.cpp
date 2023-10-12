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

using std::cin;
using std::cout;

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef unsigned long long ull;

const int maxn = 105;

int n, m;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

inline void clear () {
	memset (last, 0, sizeof (last));
	cnt = 0;
}

const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
inline ull shift (ull x) {
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
}

ull Hash[maxn];

void getHash (int now, int fa) {
	Hash[now] = 1ull;
	
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		getHash (t, now);
		
		Hash[now] += shift (Hash[t]);
	}
}

ull RootHash[maxn];

void changeRoot (int now, int fa) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }

		RootHash[t] = Hash[t] + shift (RootHash[now] - shift (Hash[t]));

		changeRoot (t, now);
	}
}

std::map<ull, int> trees;

int main () {
	fastread
	
	cin >> m;

	for (int id = 1; id <= m; id++) {
		clear ();

		cin >> n;
		for (int i = 1; i <= n; i++) {
			int fa; cin >> fa;

			if (not fa) { continue; }

			addEdge (i, fa);
			addEdge (fa, i);
		}

		getHash (1, 0);
		
		RootHash[1] = Hash[1];
		changeRoot (1, 0);

		ull treeHash = 1ull;
		for (int i = 1; i <= n; i++) {
			treeHash += shift (RootHash[i]);
		}

		if (not trees.count (treeHash)) {
			trees[treeHash] = id;
		}

		cout << trees[treeHash] << endl;
	}

	return 0;
}
