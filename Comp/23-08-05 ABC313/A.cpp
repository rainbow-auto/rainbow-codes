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

const int maxn = 100005;

int n;
int a[maxn];

int main () {
	fastread

	
	cin >> n;
	
	
	for (int i = 1; i <= n; i++) { 
		cin >> a[i];
	}

	int mx = 0;
	for (int i = 2; i <= n; i++) {
		mx = max (mx, a[i]);
	}
	
	for (int i = 0; i <= 105; i++) {
		if (i + a[1] > mx) { cout << i << endl; return 0; }
	}
	
	return 0;
}
