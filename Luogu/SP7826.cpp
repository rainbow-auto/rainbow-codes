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

const int maxn = 100005;

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

inline void clear () {
	cnt = 0;
	memset (last, 0, sizeof (last));
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

		RootHash[t] = Hash[t] + shift ( RootHash[now] - shift (Hash[t]) );
		changeRoot (t, now);
	}
}

inline ull getTreeHash () {
	clear ();
	
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}

	int rt = 1;
	getHash (rt, 0);
	RootHash[rt] = Hash[rt];
	changeRoot (rt, 0);
	
	ull TreeHash = 1ull;
	for (int i = 1; i <= n; i++) {
		TreeHash += shift (RootHash[i]);
	}

	return TreeHash;
}

int main () {
	fastread
	
	int T; cin >> T;

	while (T--) {
		cin >> n;
		
		int Hash1 = getTreeHash ();
		int Hash2 = getTreeHash ();
	
		if (Hash1 == Hash2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
