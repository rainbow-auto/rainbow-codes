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
using ull = unsigned long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 2000005;

const ull base = 233;

int n;
char s[maxn];

std::map <ull, int> cnt;
std::stack <char> stk;

ull power[maxn];

inline void init () {
	power[1] = 1;
	for (int i = 2; i <= n; i++) { power[i] = power[i - 1] * base; }
}

int main () {
	fastread

	std::cin >> n;
	std::cin >> (s + 1);

	init ();

	ull hash_now = 0ull;
	i64 ans = 0;

	cnt[0] = 1;

	for (int i = 1; i <= n; i++) {
		if (not stk.empty () and stk.top () == s[i]) { 
			hash_now -= power[stk.size ()] * s[i];
			stk.pop ();
		}
		else {
			stk.push (s[i]);
			hash_now += power[stk.size ()] * s[i];
		}

		if (cnt.count (hash_now)) { ans += cnt[hash_now]; }
		cnt[hash_now] ++;
	}

	std::cout << ans << "\n";

	return 0;
}
