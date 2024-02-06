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

using i64 = unsigned long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

namespace Gen {
		namespace GenHelper
	{
		unsigned z1,z2,z3,z4,b;
		unsigned rand_()
		{
		b=((z1<<6)^z1)>>13;
		z1=((z1&4294967294U)<<18)^b;
		b=((z2<<2)^z2)>>27;
		z2=((z2&4294967288U)<<2)^b;
		b=((z3<<13)^z3)>>21;
		z3=((z3&4294967280U)<<7)^b;
		b=((z4<<3)^z4)>>12;
		z4=((z4&4294967168U)<<13)^b;
		return (z1^z2^z3^z4);
		}
	}
	void srand(unsigned x)
	{using namespace GenHelper;
	z1=x; z2=(~x)^0x233333333U; z3=x^0x1234598766U; z4=(~x)+51;}
	int read()
	{
		using namespace GenHelper;
		int a=rand_()&32767;
		int b=rand_()&32767;
		return a*32768+b;
	}
}

const int maxn = 20000005;

int n, m;
unsigned s;

struct Node {
	int x;
	int pos;

	friend bool operator < (Node a, Node b) {
		return a.x > b.x;
	}
} a[maxn]; 

inline int query (int l, int r) {
	for (int i = 1; i <= n; i++) {
		if (l <= a[i].pos and a[i].pos <= r) { return a[i].x; }
	}
}

int main () {
	fastread
	
	std::cin >> n >> m >> s;

	Gen::srand (s);

	for (int i = 1; i <= n; i++) {
		int now = Gen::read ();
		a[i] = Node { now, i };
	}

	std::sort (a + 1, a + n + 1);

	i64 ans = 0;	

	for (int i = 1; i <= m; i++) {
		int l = Gen::read () % n + 1;
		int r = Gen::read () % n + 1;
		if (l > r) { std::swap (l, r); }

		ans += query (l, r);
	}

	std::cout << ans << "\n";

	return 0;
}
