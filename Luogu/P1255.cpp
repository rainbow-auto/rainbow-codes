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

using i64 = __int128;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 5005;

struct BigInt {
	std::vector<int> num;

	BigInt () {
		num.clear ();
	}

	BigInt (int x) {
		num.clear ();
		num.push_back (x);
	}

	friend BigInt operator + (BigInt a, BigInt b) {
		if (a.num.size () < b.num.size ()) { std::swap (a, b); }
		while (b.num.size () < a.num.size ()) { b.num.push_back (0); }

		BigInt c;

		int x = 0;
		for (int i = 0; i < a.num.size (); i++) {
			int now = a.num[i] + b.num[i] + x;
			c.num.push_back (now % 10);
			x = now / 10;
		}
		
		if (x) { c.num.push_back (x); }

		return c;
	}

	inline void output () {
		std::reverse (num.begin (), num.end ());
		for (auto x : num) { std::cout << x; } std::cout << "\n";
		std::reverse (num.begin (), num.end ());
	}
};

int n;

int main () {
	fastread
	
	std::cin >> n;

	if (n == 1) { std::cout << "1\n"; return 0; }
	if (n == 2) { std::cout << "2\n"; return 0; }

	BigInt f1 (1);
	BigInt f2 (2);

	BigInt f3;

	for (int i = 3; i <= n; i++) {
		f3 = f1 + f2;

		f1 = f2;
		f2 = f3;		
	}

	f3.output ();

	return 0;
}
