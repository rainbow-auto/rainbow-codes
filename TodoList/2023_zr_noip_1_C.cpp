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

int n;
int a[maxn];

struct Segment {
	int xorSum;
	int nums[maxn], last = 1;
	inline void push_back (int x) {
		xorSum ^= x;
		nums[++last] = x;
	}

	inline void remove (int x) {
		xorSum ^= nums[x];
		swap (nums[last], nums[x]); last --;
	}

	inline int& operator [] (int i) { return nums[i]; }
};

Segment l, r;

inline int calc (int u, int v) {
	r.push_back (l[u]);
	l.remove (u);

	l.push_back (r[v]);
	r.remove (v);

	return (l.xorSum + 1) ^ r.xorSum;
}

const double eps = 1e-19;
const double d = 0.9998;

inline void simulateAnneal (int &ans) {
	double temp = 5000;

	while (temp > eps) {
		int u = rand () % l.last;
		int v = rand () % r.last;
		
		int delta = clac (u, v);

		if (delta > 0) {
			now += delta;
		}
	}
}

int main () {
	fastread
	
	cin >> n;

	for (int i = 1; i <= n; i++) { cin >> a[i]; }

	for (int i = 1; i <= (n >> 1); i++) { l.push_back (a[i]); }
	for (int i = (n >> 1) + 1; i <= n; i++) { r.push_back (a[i]); }

	int startTime = clock ();
	while (clock () - startTime < (double) CLOCKS_PER_SEC * 0.8) { simulateAnneal (); }



	return 0;
}
