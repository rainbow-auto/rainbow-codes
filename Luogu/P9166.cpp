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

const int maxn = 200005;

int n, m, x;

struct Range {
	int l, r;

	friend bool operator < (Range a, Range b) {
		if (a.l != b.l) { return a.l < b.l; }
		else { return a.r < b.r; }
	}
};

std::vector <Range> a;

namespace Subtask1 {

	inline bool check (int pos, Range rg) {
		return rg.l <= pos and pos <= rg.r;
	}

	inline void solve () {
		std::sort (a.begin (), a.end ());
		
		std::set <int> ans;

		int L = 0x3f3f3f3f, R = 0;
		for (int i = 0; i < a.size (); i++) {
			if (check (x, a[i])) {
				L = std::min (L, a[i].l);
				R = std::max (R, a[i].r);
				
				ans.insert (a[i].l);
				ans.insert (a[i].r);
			} 
		}

		if (L == 0x3f3f3f3f) { return; }

		int l, r;

		l = L; r = R;
		for (int i = 0; i < a.size (); i++) {
			if (a[i].l >= x) {
				if (check (a[i].l, Range { l, r }) or check (a[i].r, Range { l, r }) or (a[i].l <= l and r <= a[i].r)) { 
					r = std::max (r, a[i].r); 
					l = std::min (l, a[i].l);
					ans.insert (a[i].r); 
				}
			}
		}

		l = L; r = R;
		for (int i = a.size () - 1; i >= 0; i--) {
			if (a[i].r <= x) {
				if (check (a[i].l, Range { l, r }) or check (a[i].r, Range { l, r }) or (a[i].l <= l and r <= a[i].r)) {
					r = std::max (r, a[i].r); 
					l = std::min (l, a[i].l); 
					ans.insert (a[i].l);
				}
			}
		}

		for (auto now : ans) { 
			if (now == x) { continue; }
			std::cout << now << ' '; 
		}
	}
}

int main () {
	fastread

	std::cin >> n >> m >> x;

	for (int i = 1; i <= m; i++) { int l, r; std::cin >> l >> r; a.push_back (Range { l, r }); }

	Subtask1::solve ();

	return 0;
}
