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

typedef unsigned long long ll;

namespace Basis {
	ll a[64];
	inline void insert (ll x) {
		for (int i = 63; i >= 0; i--) {
			if (not (x & (1ll << i))) { continue; }

			if (a[i]) { x ^= a[i]; } 
			else { a[i] = x; return; }
		}		
	}

	inline ll query (ll x) {
		for (int i = 63; i >= 0; i--) {
			if ((x ^ a[i]) > x) { x ^= a[i]; }
		}
		return x;
	}
}

int n;

signed main () {
	fastread

	cin >> n;

	for (int i = 1; i <= n; i++) {
		ll now; cin >> now;
		Basis::insert(now);
	}

	cout << Basis::query(0) << endl;

	return 0;
}
