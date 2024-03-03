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

int n;
char s[maxn];

char ans[maxn];
int tot;

int main () {
	fastread
	
	std::cin >> s;
	n = strlen (s);

	int lpos = 0, rpos = n - 1;
	while (rpos - lpos + 1 >= 4) {
		if (s[lpos] == s[rpos]) {
			ans[++tot] = s[lpos];			
		} else if (s[lpos + 1] == s[rpos]) {
			ans[++tot] = s[lpos + 1];			
		} else if (s[lpos] == s[rpos - 1]) {
			ans[++tot] = s[lpos];			
		} else if (s[lpos + 1] == s[rpos - 1]) {
			ans[++tot] = s[lpos + 1];			
		}

		lpos += 2;
		rpos -= 2;
	}

	for (int i = 1; i <= tot; i++) { std::cout << ans[i]; }
	if (lpos < rpos) { std::cout << s[lpos]; }
	for (int i = tot; i >= 1; i--) { std::cout << ans[i]; }

	return 0;
}
