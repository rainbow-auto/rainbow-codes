// not solve by myself

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

int T;

int n;

struct Data {
	int a, b;

	friend bool operator < (Data x, Data y) {
		return x.a < y.a;
	}
};

std::vector<Data> d;

inline void solve () {
	d.clear ();

	std::cin >> n;

	for (int i = 1; i <= n; i++) { int x; std::cin >> x; d.push_back (Data { x, 0 }); }
	for (auto& now : d) { std::cin >> now.b; }

	std::sort (d.begin (), d.end ());

	for (auto now : d) { std::cout << now.a << " "; } std::cout << "\n";
	for (auto now : d) { std::cout << now.b << " "; } std::cout << "\n";
}

int main () {
	fastread
	
	std::cin >> T;
	while (T--) {
		solve ();
	}

	return 0;
}
