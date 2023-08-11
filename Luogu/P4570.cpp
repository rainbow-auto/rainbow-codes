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
	
	inline bool insert (ll x) {
		for (int i = 63; i >= 0; i--) { 
			if (not (x & (1ll << i))) { continue; }	
			if (a[i]) { x ^= a[i]; }
			else { a[i] = x; return true; }
		}
		return false;
	}
}

const int maxn = 100005;
int n;

struct Node {
	ll id, val;
	friend bool operator < (Node a, Node b) {
		return a.val > b.val;
	}
} a[maxn];

int main () {
	fastread

	cin >> n;

	for (int i = 1; i <= n; i++) { cin >> a[i].id >> a[i].val; }

	sort (a + 1, a + n + 1);
	
	ll res = 0;
	for (int i = 1; i <= n; i++) { 
		if (Basis::insert(a[i].id)) {
			res += a[i].val;
		}
	}

	cout << res << endl;

	return 0;
}
