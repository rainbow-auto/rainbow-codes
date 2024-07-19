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

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cout << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxS = (1 << 21) + 5;
const int maxn = 100005;

int n, m, d;

int sum[maxS]; // 高维前缀和

int id[maxn];
int cnt[maxn];

std::vector <int> s;

inline int popcount (int S) {
	int res = 0;
	while (S) { res += (S & 1); S >>= 1; }
	return res;
}

int main () {
	fastread
	
	std::cin >> n >> m >> d;

	int mask = (1 << m) - 1;

	for (int i = 0; i < m; i++) {
		int siz; std::cin >> siz;

		while (siz--) {
			int x; std::cin >> x;
			id[x] = i;
		}
	}

	int curr = 0;
	for (int i = 1; i <= n; i++) {
		cnt[id[i]] ++;
		curr |= (1 << id[i]);
		if (i < d) { continue; }

		sum[curr ^ mask] = 1; // 取反后, 加入前缀和中

		cnt[id[i - d + 1]]--;
		if (cnt[id[i - d + 1]] == 0) { curr ^= (1 << id[i - d + 1]); }
	}

	for (int i = 0; i < m; i++) {
		for (int S = 0; S < (1 << m); S++) {
			if (not (S & (1 << i))) { sum[S] += sum[S ^ (1 << i)]; }
		}
	}

	int ans = 0x3f3f3f3f;
	for (int S = 1; S < (1 << m); S++) { // 不能为空 (因此从一开始枚举)
		if (sum[S]) { continue; }
		ans = std::min (ans, popcount (S));
	}

	std::cout << ans << "\n";

	return 0;
}
