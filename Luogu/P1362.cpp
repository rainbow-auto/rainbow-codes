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

const int maxn = 100005;

int n;

int L, R;

inline i64 S (i64 x) {
	i64 res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main () {
	fastread

	std::cin >> L >> R;

	int ans = 0;

	for (int s1 = 0; s1 <= 3; s1 ++) 
	for (int s2 = 0; s2 <= 3; s2 ++) 
	for (int s3 = 0; s3 <= 3; s3 ++) 
	for (int s4 = 0; s4 <= 3; s4 ++) 
	for (int s5 = 0; s5 <= 3; s5 ++) 
	for (int s6 = 0; s6 <= 3; s6 ++) 
	for (int s7 = 0; s7 <= 3; s7 ++) 
	for (int s8 = 0; s8 <= 3; s8 ++) 
	for (int s9 = 0; s9 <= 3; s9 ++) 
	for (int s10 = 0; s10 <= 3; s10 ++) {
		i64 now = s1 + s2 * 10 + s3 * 1e2 + s4 * 1e3 + s5 * 1e4 + s6 * 1e5 + s7 * 1e6 + s8 * 1e7 + s9 * 1e8 + s10 * 1e9;
		if (L <= now and now <= R) {
			if (S (now) * S (now) == S (now * now)) { ans ++; }
		}
	}

	std::cout << ans << "\n";

	return 0;
}
