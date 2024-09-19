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

int n, m;

const int maxn = 10;

std::array <std::array <char, maxn>, maxn> curr, ans;
i64 ans_val = 1e18;

i64 stk[maxn], spos;
inline i64 calc (std::string s) {
	s += '#';

	spos = 0;
	bool mul = false;
	i64 num = 0;
	for (auto c : s) {
		if (isdigit (c)) { num *= 10; num += c - '0'; continue; }

		if (mul) { stk[spos] *= num; num = 0; mul = false; }
		else { stk[++spos] = num; num = 0; }

		if (c == '+') { continue; }
		if (c == '*') { mul = true; continue; }
	}

	i64 res = 0;
	rep (i, 1, spos) { res += stk[i]; }
	return res;
}

void dfs (int x, int y, i64 val, int cnt) {
	if (val > ans_val) { return; }
	if (cnt > 5) { return; }

	if (x == n + 1) {
		i64 res = val;

		rep (j, 1, m) {
			std::string s;
			rep (i, 1, n) {
				s += curr[i][j];
			}
			res += calc (s);
		}

		if (ans_val > res) {
			ans_val = res;
			ans = curr;
		} 

		return;
	}

	auto nxt = [&](char c) -> void {
		curr[x][y] = c;
		if (y == m) {
			std::string s;
			rep (j, 1, m) { s += curr[x][j]; }
			dfs (x + 1, 1, val + calc (s), cnt + (c == '+'));
		} else {
			dfs (x, y + 1, val, cnt + (c == '+'));
		}
	};

	if (x != 1 and y != 1 and x != n and y != m and curr[x - 1][y] == '1' and curr[x][y - 1] == '1') {
		nxt ('+');
		nxt ('*');
	} else {
		nxt ('1');
	}
}

inline void solve () {
	std::cin >> n >> m;

	dfs (1, 1, 0, 0);
	
	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cout << ans[i][j];
		}
		std::cout << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	while (_--) {
		solve ();
	}

	return 0;
}
