#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxS = (1 << 19) + 5;

const int inf = (1 << 20);

int n, k;
int a[maxS];
int f[maxS], minv[maxS], maxv[maxS]; 

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> k;
	rep (i, 1, n) { std::cin >> a[i]; }

	rep (i, 0, (1 << k) - 1) { f[i] = minv[i] = inf; maxv[i] = -inf; }

	rep (i, 1, n) { minv[a[i]] = maxv[a[i]] = 0; }

	rep (d, 0, k - 1) {
		rep (x, 0, (1 << k) - 1) {
			if (x & (1 << d)) { continue; }
			int y = x | (1 << d);

			f[x] = f[y] = std::min (f[x], f[y]);
			f[x] = std::min (f[x], minv[y] - maxv[x] + (1 << d));
			f[y] = std::min (f[y], minv[x] - maxv[y] + (1 << d));

			int minvx = minv[x], minvy = minv[y];
			int maxvx = maxv[x], maxvy = maxv[y];

			minv[x] = std::min (minvx, minvy + (1 << d));
			maxv[x] = std::max (maxvx, maxvy + (1 << d));

			minv[y] = std::min (minvy, minvx + (1 << d));
			maxv[y] = std::max (maxvy, maxvx + (1 << d));
		}
	}

	rep (i, 0, (1 << k) - 1) { std::cout << f[i] << " "; }

	return 0;
}
