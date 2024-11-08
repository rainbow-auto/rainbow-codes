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

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = (1 << 22) + 5;

int n;

int a[maxn];

int sum[maxn];

int main () {
	fastread

	memset (sum, -1, sizeof (sum));
	
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum[a[i]] = a[i];
	}

	for (int i = 0; i < 22; i++) {
		for (int S = 0; S < (1 << 22); S++) {
			if (S & (1 << i)) { sum[S] = std::max (sum[S], sum[S ^ (1 << i)]); }
		}
	}	

	int mask = (1 << 22) - 1;

	for (int i = 1; i <= n; i++) {
		std::cout << sum[a[i] ^ mask] << " ";
	}

	std::cout << "\n";

	return 0;
}
