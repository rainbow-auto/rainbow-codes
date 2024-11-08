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
int a[maxn];


bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	while (true) {
		std::cin >> n;
		if (not n) { break; }
		
		std::map <int, std::vector <int> > t;
		rep (i, 1, n) { std::cin >> a[i]; t[a[i]].push_back (i); }

		std::set <int> s; // 插入过的位置
		s.insert (0); s.insert (n + 1);

		i64 ans = 0;
		for (auto now : t) {
			std::vector <int> pos = now.second;

			for (auto i : pos) {
				auto it = s.upper_bound (i);
				i64 width = ((*it) - 1) - ((*std::prev (it)) + 1) + 1;
				i64 height = now.first;
				
				ans = std::max (ans, width * height);
			}

			for (auto i : pos) { s.insert (i); }
		}

		std::cout << ans << "\n";
	}

	return 0;
}
