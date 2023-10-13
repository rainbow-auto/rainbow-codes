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

using std::cin;
using std::cout;

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

const int maxn = 100005;
const int maxm = 100005;

typedef unsigned long long ull;

const ull mod = 10007;

int n, m;
ull num[maxn], col[maxn];

// (x + z) * (a[x] + a[z])
// = z * a[z] + x * a[x] + a[x] * z + a[z] * x

ull val1[maxm][2]; // cnt
ull val2[maxm][2]; // x * a[x]
ull val3[maxn][2]; // a[x]
ull val4[maxn][2]; // x

int main () {
	fastread
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) { cin >> num[i]; }

	for (int i = 1; i <= n; i++) { cin >> col[i]; }

	ull ans = 0;

	for (int i = 1; i <= n; i++) {
		( ans += i * num[i] * val1[col[i]][i % 2] ) %= mod; // z * a[z] * len
		( ans += val2[col[i]][i % 2] ) %= mod; // x * a[x]
		( ans += i * val3[col[i]][i % 2] ) %= mod; // z * a[x]
		( ans += num[i] * val4[col[i]][i % 2] ) %= mod; // a[z] * x

		( val1[col[i]][i % 2] += 1 ) %= mod;
		( val2[col[i]][i % 2] += i * num[i] ) %= mod;
		( val3[col[i]][i % 2] += num[i] ) %= mod;
		( val4[col[i]][i % 2] += i ) %= mod;
	}

	cout << ans << endl;

	return 0;
}