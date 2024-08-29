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
bool MemST;

const int maxn = 1005;

int n, m;
std::string s[maxn];

std::bitset <maxn> compared;

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> m;
	rep (j, 1, m) { s[j] = " "; }
	rep (i, 1, n) {
		rep (j, 1, m) {
			char c; std::cin >> c;
			s[j] += c;
		}
	}

	int ans = 0;

	rep (j, 1, m) {
		bool flag = false;
		rep (i, 1, n) {
			if (compared[i]) { continue; }
			if (s[j][i] < s[j][i - 1]) { flag = true; break; }
		}

		if (flag) { ans ++; continue; }

		rep (i, 1, n) {
			if (s[j][i] > s[j][i - 1]) { compared.set (i); }
		}
	}

	std::cout << ans << "\n";

	return 0;
}
