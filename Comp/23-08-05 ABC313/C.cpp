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

#define int long long

const int maxn = 200005;

int n;
int a[maxn];

signed main () {
	fastread

	int avr = 0;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		avr += a[i];
	}
	
	avr /= n;
	
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > avr + 1) { ans1 += a[i] - (avr + 1); }
		else { ans2 += avr - a[i]; }
	}
	
	cout << max (ans1, ans2) << endl;
	
	return 0;
}
