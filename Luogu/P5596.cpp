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

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

i64 a, b;

int main () {
	fastread
	
	std::cin >> a >> b;
	if (a * a == 4ll * b) { std::cout << "inf\n"; return 0; }

	i64 k = 1;	
	i64 ans = 0;

	if ((i64 (sqrt (b))) * (i64 (sqrt (b))) == b) { ans ++; }

	while (true) {
		i64 up = b - k * k;
		i64 dw = 2ll * k - a;	
		
		if (((up > 0 and dw > 0) or (up < 0 and dw < 0)) and up % dw == 0) { ans ++; }
		if (up < 0 and dw > 0) { break; }
		k++;
	}

	std::cout << ans << "\n";

	return 0;
}
