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

const int maxn = 3005;

int n, m;
std::string s, t;

int dp[maxn][maxn];

struct Node {
	int x, y;
} pre[maxn][maxn];

std::stack<char> ans;
void print (int i, int j) {
	if (not i or not j) { return; }
	
	if (s[i] == t[j]) { ans.push (s[i]); }

	print (i + pre[i][j].x, j + pre[i][j].y);
}	

int main () {
	fastread
	
	std::cin >> s >> t;
	
	n = s.size (); m = t.size ();
	s = " " + s; t = " " + t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i] == t[j]) { 
				dp[i][j] = dp[i - 1][j - 1] + 1; pre[i][j] = Node { -1, -1 };
			} else if (dp[i - 1][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j]; pre[i][j] = Node { -1, 0 }; 
			} else {
				dp[i][j] = dp[i][j - 1]; pre[i][j] = Node { 0, -1 }; 
			}
		}
	}

	print (n, m);
	while (not ans.empty()) { std::cout << ans.top (); ans.pop (); }

	return 0;
}
