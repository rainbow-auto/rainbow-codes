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

const i64 mod = 1e9 + 7;

i64 l, r;
std::bitset <100000005> mark;

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> l >> r;

	rep (i, 0, 10000) { mark[i * i] = true; }

	i64 ans = 0;
	rep (i, l, r) {
		int num1 = i;
		while (not mark[num1]) { num1 --; }

		int num2 = i;
		while (not mark[num2]) { num2 ++; }


		int num;
		if (num2 - i < i - num1) {
			num = num2;
		} else {
			num = num1;
		}

		if (num & 1) { ans += i; }
		else { ans -= i; }
	}

	std::cout << (ans + mod) % mod << "\n";

	return 0;
}
