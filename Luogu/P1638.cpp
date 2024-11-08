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

const int maxn = 1000005;

int n, m;
int a[maxn];

int cnt[maxn];

struct Ans {
	int val;

	int l, r;

	friend bool operator < (Ans a, Ans b) {
		if (a.val != b.val) { return a.val < b.val; }
		else { return a.l < b.l; }
	}
};

#define update if (cntnow == m) { ans = std::min (ans, Ans { r - l + 1, l, r }); } 

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	Ans ans = Ans { 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f };
	
	int l = 1, r = 1;
	cnt[a[r]] = 1;
	int cntnow = 1;

	while (l <= r and r <= n) {
		if (cntnow == m) {
			update
			
			cnt[a[l]] --;
			if (cnt[a[l]] == 0) { cntnow --; }
			l ++;
		} else {
			r++;
			if (cnt[a[r]] == 0) { cntnow ++; }
			cnt[a[r]] ++;
			
			update
		}

	}

	std::cout << ans.l << " " << ans.r << "\n";

	return 0;
}
