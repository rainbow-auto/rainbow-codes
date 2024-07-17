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

const int maxn = 2005;
const int mod = 1e9 + 7;

std::string s, t;

int m, d;

int a[maxn];

inline int add (int r, int x) {
	return ((((10 % m) * (r % m)) % m) + x % m) % m;
}

int mem[maxn][maxn];

int len;
int dp (int now, bool lim, int r) {
	if (now > len) { return r == 0; }
	if (not lim and mem[now][r] != -1) { return mem[now][r]; }

	int mx = (lim ? a[now] : 9);

	int res = 0;
	if (not (now & 1)) {
		if (d <= mx) { res = dp (now + 1, (lim and d == mx), add (r, d)); }	
	} else {
		for (int i = 0; i <= mx; i++) {
			if (i == d) { continue; }
			res = (res + dp (now + 1, (lim and i == mx), add (r, i))) % mod;
		}
	}

	if (not lim) { mem[now][r] = res; }

	return res;
}

inline bool chk () { 
	int r = 0;
	for (int i = 1; i <= len; i++) {
		if (not (i & 1) and a[i] != d) { return false; }
		if ((i & 1) and a[i] == d) { return false; }
		
		r = add (r, a[i]);
	}

	return r == 0;
}

int l[maxn], r[maxn];

inline void solve () {
	memset (mem, -1, sizeof (mem));
	memcpy (a, r, sizeof (r));
	len = t.size ();
	int ans = dp (1, true, 0);	

	memset (mem, -1, sizeof (mem));
	memcpy (a, l, sizeof (l));
	len = s.size ();
	ans = (ans - dp (1, true, 0) + mod) % mod;
	
	memcpy (a, l, sizeof (l));
	ans += chk ();

	std::cout << ans << "\n";
}

int main () {
	fastread

	std::cin >> m >> d;

	std::cin >> s;
	std::cin >> t;

	for (int i = 0; i < s.size (); i++) { l[i + 1] = s[i] - '0'; }
	for (int i = 0; i < t.size (); i++) { r[i + 1] = t[i] - '0'; }

	solve ();

	return 0;
}

/*
Input：
123 0
24356787968574635245467890796857463524567
98765437654345678765432345678765434567876

Output：
428323666
*/