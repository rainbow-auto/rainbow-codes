#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
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

const int maxn = 35;

int n, m;

char a[maxn][maxn];
char b[maxn][maxn];

int a_new[maxn][maxn];
inline bool chk (int s, int t) {
	rep (i, 0, n - 1) {
		rep (j, 0, m - 1) {
			a_new[(i + s) % n][(j + t) % m] = a[i][j]; 
		}
	}

	rep (i, 0, n - 1) { rep (j, 0, m - 1) { if (a_new[i][j] != b[i][j]) { return false; } } }
	return true;
}

int main () {
	fastread

	std::cin >> n >> m;
	rep (i, 0, n - 1) { rep (j, 0, m - 1) { std::cin >> a[i][j]; } }
	rep (i, 0, n - 1) { rep (j, 0, m - 1) { std::cin >> b[i][j]; } }

	rep (s, 0, n - 1) {
		rep (t, 0, m - 1) {
			if (chk (s, t)) { std::cout << "Yes\n"; return 0; }
		}
	}

	std::cout << "No\n";

	return 0;
}
