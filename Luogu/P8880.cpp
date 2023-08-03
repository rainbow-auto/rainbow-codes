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
int a[maxn], b[maxn], c[maxn];

int main () {
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> c[i]; }

	if (n % 2 == 0) { cout << -1 << endl; return 0; }

	for (int i = 1; i <= n; i++) {
		if (c[i] % 2 == 0) { a[i] = b[i] = c[i] / 2; }
		else { a[i] = b[i] = (c[i] + n) / 2; }
	}

	for (int i = 1; i <= n; i++) { cout << a[i] << " "; } cout << endl;
	for (int i = 1; i <= n; i++) { cout << b[i] << " "; } cout << endl;

	return 0;
}
