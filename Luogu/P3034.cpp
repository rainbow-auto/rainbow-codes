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

#include <unordered_map>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 100005;

int n;
int a[5][maxn];

std::unordered_map <int, int> pos[5];

inline bool comp (int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		cnt += pos[i][x] < pos[i][y];	
	}	
	return cnt >= 3;
}

int main () {
	fastread
	
	std::cin >> n;

	for (int t = 0; t < 5; t++) {
		for (int i = 1; i <= n; i++) {
			std::cin >> a[t][i];			
			pos[t][a[t][i]] = i;
		}
	}

	std::sort (a[0] + 1, a[0] + n + 1, comp);

	for (int i = 1; i <= n; i++) {
		std::cout << a[0][i] << '\n';
	}

	return 0;
}
