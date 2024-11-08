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

bool MemED;
int main () {
	fastread
	// lookMem	

	i64 ax, ay; std::cin >> ax >> ay;
	i64 bx, by; std::cin >> bx >> by;
	i64 cx, cy; std::cin >> cx >> cy;

	i64 a = (ax - bx) * (ax - bx) + (ay - by) * (ay - by); 
	i64 b = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy); 
	i64 c = (cx - bx) * (cx - bx) + (cy - by) * (cy - by); 

	if (a + b == c or a + c == b or b + c == a) { std::cout << "Yes\n"; }
	else { std::cout << "No\n"; }

	return 0;
}
