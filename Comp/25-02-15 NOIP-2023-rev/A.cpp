#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

const int maxn = 3005;

int n, m;

struct String {
	std::string mn;
	std::string mx;

	int mnp, mxp;
} s[maxn];

std::vector<std::string> ss;

void solve() {
	// file("dict4")

	std::cin >> n >> m;

	if (n == 1) return std::cout << "1\n", void(0);

	rep (i, 1, n) {
		std::cin >> s[i].mn;
		std::sort(s[i].mn.begin(), s[i].mn.end());
		ss.push_back(s[i].mn);

		s[i].mx = s[i].mn;
		std::reverse(s[i].mx.begin(), s[i].mx.end());
		ss.push_back(s[i].mx);
	}

	std::sort(ss.begin(), ss.end());
	ss.erase(std::unique(ss.begin(), ss.end()), ss.end());

	rep (i, 1, n) {
		s[i].mnp = std::lower_bound(ss.begin(), ss.end(), s[i].mn) - ss.begin();
		s[i].mxp = std::lower_bound(ss.begin(), ss.end(), s[i].mx) - ss.begin();
	}

	rep (i, 1, n) {
		int oth = 0x3f3f3f3f;
		rep (j, 1, n) if (j != i) oth = std::min(oth, s[j].mxp);
		if (s[i].mnp < oth) std::cout << "1";
		else std::cout << "0";
	}
	std::cout << "\n";

	lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
