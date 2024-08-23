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

const int maxn = 200005;

int n;
int l[maxn], r[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	

	i64 L = 0, R = 0;

	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> l[i] >> r[i];
		L += l[i]; R += r[i];
	}

	if (L <= 0 and 0 <= R) { std::cout << "Yes\n"; }
	else { std::cout << "No\n"; return 0; }

	rep (i, 1, n) {
		if (R == 0) { break; }
		if (R - (r[i] - l[i]) >= 0) { R -= (r[i] - l[i]); r[i] = l[i];  }
		else { r[i] -= R; R = 0; }
	}

	rep (i, 1, n) { std::cout << r[i] << " "; } std::cout << "\n";

	return 0;
}
