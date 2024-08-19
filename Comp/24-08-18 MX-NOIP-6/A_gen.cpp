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
#include <random>
#include <chrono>

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

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

inline i64 getNum (int l, int r) {
	return std::uniform_int_distribution <i64> (l, r) (rng);
}

bool MemED;
int main () {
	fastread
	// lookMem	

	i64 num1 = getNum (1, 1000);
	i64 num2 = getNum (1, 1000);

	std::cout << std::min (num1, num2) << " " << std::max (num1, num2) << "\n";

	return 0;
}
