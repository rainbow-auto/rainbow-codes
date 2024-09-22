#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

i64 n;

std::vector <i64> nums;
inline void solve () {
	rep (i, 1, 100000) {
		if (i % 10 == 0) { continue; }
		i64 L = i;

		std::string s = std::to_string (L);
		std::reverse (s.begin (), s.end ());

		rep (mid, 0, 9) {
			i64 curr = L;
			curr *= 10; curr += mid;
			for (auto c : s) {
				curr *= 10; curr += c - '0';				
			}

			nums.push_back (curr);
		}

		i64 curr = L;
		for (auto c : s) {
			curr *= 10; curr += c - '0';
		}
		nums.push_back (curr);
	}

	std::cin >> n;

	std::sort (nums.begin (), nums.end ());
	nums.erase (std::unique (nums.begin (), nums.end ()), nums.end ());

	int ans = 0;
	for (auto x : nums) {
		if (x > n) {
			break;
		}
		
		int y = *std::lower_bound (nums.begin (), nums.end (), n - x);

		if (x + y == n) { ans ++; }
	}	

	std::cout << ans << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("palindrome.in", "r", stdin);
	freopen ("palindrome.out", "w", stdout);

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}
