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

#define int long long

const int maxn = 15;

int l, r;
int a[maxn];
int mem[maxn][10];

int len;

inline void get_num (int x) {
	while (x) {
		a[++len] = x % 10;
		x /= 10;
	}
}

int dfs (int now, int pre, bool limit, bool zero) {
	if (now > len) { return 1; } // 搜完了 (既然搜过来了, 上一种搜索方式一定是合法的, 因此给答案加一)
	if (not limit and mem[now][pre] != -1) { return mem[now][pre]; }

	int res = 0;
	int mx = limit ? a[len - now + 1] : 9;
	for (int i = 0; i <= mx; i++) {
		if ( abs(i - pre) < 2) { continue; } // 不符合题意 (差至少是2)

		if (zero and i == 0) { res += dfs (now + 1, -2, limit and i == mx, true); } // 因为前导0, 所以下一位可以随便选, 要保证这一点, 首先就需要前一位是 -2, 这样无论怎么选都行
		else { res += dfs (now + 1, i, limit and i == mx, false); }
	}

	if (not limit and not zero) { mem[now][pre] = res; }

	return res;
}

inline int solve (int x) {
	memset (mem, -1, sizeof (mem));
	memset (a, 0, sizeof (a)); len = 0;
	get_num (x);
	return dfs (1, -2, true, true);
}	

signed main () {
	fastread

	cin >> l >> r;

	cout << solve (r) - solve(l - 1) << endl;

	return 0;
}
