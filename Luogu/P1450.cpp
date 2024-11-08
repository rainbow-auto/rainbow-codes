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

inline int popcount (int S) {
	int res = 0; while (S) { res += bool (S & 1); S >>= 1; }
	return res;
}

inline bool get (int S, int pos) { return S & (1 << (pos - 1)); }

const int maxn = 100005;
const int maxc = 10;

int c[maxc];
int d[maxc];

// 完全背包预处理
i64 f[maxn];
inline void init (int R) {
	f[0] = 1;
	rep (i, 1, 4) {
		rep (j, c[i], R) { f[j] += f[j - c[i]]; }
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	

	rep (i, 1, 4) { std::cin >> c[i]; }
	init (1e5);

	int T; std::cin >> T;

	while (T--) {
		rep (i, 1, 4) { std::cin >> d[i]; }
		int s; std::cin >> s;

		i64 ans = f[s]; // 随便选

		rep (S, 1, (1 << 4) - 1) {
			int sum = 0;
			rep (i, 1, 4) {
				if (not get (S, i)) { continue; }
				sum += (d[i] + 1) * c[i]; // 强制选 d[i] + 1 个
			}

			if (s >= sum) { ans += ((popcount (S) & 1) ? -1ll : 1ll) * f[s - sum]; }
		}
		std::cout << ans << "\n";
	}

	return 0;
}
