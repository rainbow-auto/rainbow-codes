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

#define int unsigned long long

int gcd (int a, int b) {
	if (not b) { return a; }
	else { return gcd (b, a % b); }
}

inline int lcm (int a, int b) {
	return a / gcd(a, b) * b;
}

inline bool merge (int &m1, int &a1, int m2, int a2) {
	if (m1 < m2) { swap(m1, m2); swap(a1, a2); }

	int tot = 0;
	while (a1 % m2 != a2) {
		if (++tot > m2 + 1) { return false; }
		a1 += m1;
	}
	m1 = lcm (m1, m2);
	return true;
}

int n;

signed main () {
	fastread

	int m = 1, a = 0; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int m_now, a_now; cin >> m_now >> a_now;
		if (not merge (m, a, m_now, a_now)) { cout << "答辩" << endl; return 0; }
	}

	cout << a << endl;

	return 0;
}
