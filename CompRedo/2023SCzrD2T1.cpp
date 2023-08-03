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

const int maxn = 1500;

#define int unsigned long long

int T;
int k, l, r;

inline int check (int x, int ff) {
	int f = 0;
	while (x) { f += (x % 10) * (x % 10); x /= 10; }
	return f == ff;
}

signed main () {
	fastread
	
	cin >> T;
	while (T--) {
		cin >> k >> l >> r;
		
		int ans = 0;
		for (int f = (l - 1) / k + 1; f <= maxn and f * k <= r; f++) {
			ans += check(f * k, f); // 因为我们枚举的是f, 那么就需要把f * k (这个应该等于x) 再套到f中再跟f(x) (就是我们枚举的f)比较 
		}

		cout << ans << endl;
	}

	return 0;
}
