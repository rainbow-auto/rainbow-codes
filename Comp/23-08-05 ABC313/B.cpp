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

const int maxn = 55;

int n, m;
int otd[maxn];

int main () {
	fastread
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		otd[y]++;
	}

	int cnt = 0, k = 0;
	for (int i = 1; i <= n; i++) {
		if (not otd[i]) {
			cnt++;
			k = i;
		}
	}
	
	if (cnt > 1) { cout << -1 << endl; }
	else { cout << k << endl; }
	
	return 0;
}
