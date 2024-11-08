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

const int maxn = 2005;
int n, m, k;

int cnt[maxn][maxn];

int main () {
	fastread

	// int T; std::cin >> T;

	// while (T--) {
		// std::cin >> n >> m;

		std::cin >> n >> m >> k;

		rep (i, 1, n - k + 1) {
			rep (j, 1, m - k + 1) {
				rep (a, i, i + k - 1) {
					rep (b, j, j + k - 1) {
						cnt[a][b] ++;
					}
				}
			}
		}

		int cnt9 = 0;
		rep (i, 1, n) { 
			rep (j, 1, m) { 
				std::cout << cnt[i][j] << "\t"; 
				if (cnt[i][j] == 9) { cnt9 ++; }
			} 
			std::cout << "\n"; 
		}
		std::cerr << cnt9 << "\n";
	// }

	return 0;
}

/*
1	2	3	4	5	5	5	5	5	5	5	5	5	5	5	5	4	3	2	1	
2	4	6	8	10	10	10	10	10	10	10	10	10	10	10	10	8	6	4	2	
3	6	9	12	15	15	15	15	15	15	15	15	15	15	15	15	12	9	6	3	
4	8	12	16	20	20	20	20	20	20	20	20	20	20	20	20	16	12	8	4	
5	10	15	20	25	25	25	25	25	25	25	25	25	25	25	25	20	15	10	5	
5	10	15	20	25	25	25	25	25	25	25	25	25	25	25	25	20	15	10	5	
4	8	12	16	20	20	20	20	20	20	20	20	20	20	20	20	16	12	8	4	
3	6	9	12	15	15	15	15	15	15	15	15	15	15	15	15	12	9	6	3	
2	4	6	8	10	10	10	10	10	10	10	10	10	10	10	10	8	6	4	2	
1	2	3	4	5	5	5	5	5	5	5	5	5	5	5	5	4	3	2	1	
*/
