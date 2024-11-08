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

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 55;

int n;
int dp[maxn][maxn][maxn][maxn];

int main () {
	fastread
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char ch; cin >> ch;
			dp[i][j][i][j] = (ch == '#');
		}
	}

	for (int x1 = 1; x1 <= n; x1 ++) {
		for (int y1 = 1; y1 <= n; y1 ++) {
			for (int x2 = x1; x2 <= n; x2 ++) {
				for (int y2 = y1; y2 <= n; y2 ++) {
					if (x1 == x2 and y1 == y2) continue; // 单点的情况要看是否有 #
					dp[x1][y1][x2][y2] = max (x2 - x1 + 1, y2 - y1 + 1);
				}
			}
		}
	}

	for (int lenx = 1; lenx <= n; lenx ++) {
		for (int leny = 1; leny <= n; leny ++) {
			for (int x1 = 1; x1 + lenx - 1 <= n; x1 ++) {
				for (int y1 = 1; y1 + leny - 1 <= n; y1 ++) {
					int x2 = x1 + lenx - 1;
					int y2 = y1 + leny - 1;

					for (int k = x1; k < x2; k ++) {
						dp[x1][y1][x2][y2] = min (dp[x1][y1][x2][y2], dp[x1][y1][k][y2] + dp[k + 1][y1][x2][y2]);
					}	

					for (int k = y1; k < y2; k ++) {
						dp[x1][y1][x2][y2] = min (dp[x1][y1][x2][y2], dp[x1][y1][x2][k] + dp[x1][k + 1][x2][y2]);
					}	
				}
			}
		}
	}	

	cout << dp[1][1][n][n] << endl;

	return 0;
}
