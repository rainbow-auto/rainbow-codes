#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 100005;

int n;
int b[maxn];

namespace Solution {
	std::string op;
	i64 f (int x) { // 拼出一个 x
		if (not x) { return 0; }
		if (x == 1) { op += "1"; return 0; }

		i64 res = 0;
		if (x & 1) {
			res += f (x >> 1);
			op += "c";
			op += "+"; res ++;
			f (1);
			op += "+"; res ++;
		} else {
			res += f (x >> 1);
			op += "c";
			op += "+"; res ++;
		}
		return res;
	}

	inline void solve () {
		std::vector <std::string> ans;
		i64 sub = 0;  
		per (i, n, 1) {
			op = "";
			sub += f (b[i] + sub);
			ans.push_back (op);
		}

		std::reverse (ans.begin (), ans.end ());

		for (auto now : ans) { std::cout << now; }
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("polaris.in", "r", stdin);
	freopen ("polaris.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) { std::cin >> b[i]; }

	Solution::solve ();

	return 0;
}
