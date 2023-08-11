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

namespace Basis {
	typedef unsigned long long ll;
	
	ll a[64];
	inline void insert (ll x) {
		for (unsigned long long i = 63; i >= 0; i--) {
			if (not (x & (1ll << i))) { continue; }
			if (a[i]) { x ^= a[i]; }
			else { a[i] = x; return; }
		}
	}

	inline ll query (ll x = 0) {
		for (int i = 63; i >= 0; i--) {
			if ((x ^ a[i]) > x) { x ^= a[i]; }
		}
		return x;
	}
}

int main () {
	fastread
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		unsigned long long now; cin >> now;
		Basis::insert(now);	
	}

	cout << Basis::query(0) << endl;

	return 0;
}
