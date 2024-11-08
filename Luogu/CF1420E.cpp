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

const int maxn = 85;

int n, m;
int a[maxn];

int dp[maxn][maxn][maxn * maxn];

int suma[maxn];

inline int calc (int x) { return x * (x - 1) / 2; }

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;

	int m = 1; // 段数
	int sum = 0; // 0 的数量
	rep (i, 1, n) { 
		int now; std::cin >> now;
		if (now == 0) { a[m] ++; sum ++; }
		else { m ++; } // 留出可能会新插入的段的位置
 	}

	rep (i, 1, m) { suma[i] = suma[i - 1] + a[i]; }

	memset (dp, 0x3f, sizeof (dp)); dp[0][0][0] = 0;

	rep (i, 0, m - 1) {
		rep (pre, 0, sum) { // 枚举 b 前面填了什么
			rep (step, 0, calc (n)) {
				if (dp[i][pre][step] == 0x3f3f3f3f) { continue; }
				rep (now, pre, sum) { // b 的新前缀和
					int stepnow = step + abs (suma[i + 1] - now);
					if (stepnow > calc (n)) { continue; }
					dp[i + 1][now][stepnow] = std::min (dp[i + 1][now][stepnow], dp[i][pre][step] + calc (now - pre));
				}
			}
		}
	}

	int curr = 0x3f3f3f3f;
	rep (i, 0, calc (n)) { 
		curr = std::min (curr, dp[m][sum][i]);
		std::cout << calc (sum) - curr << " "; 
	}
 
	return 0;
}
