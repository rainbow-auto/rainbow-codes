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

int k, x, n, m;

std::string make (char l, char r, int c, int len) {
	std::string res;
	res += l;

	int rest = c;
	if (c > 0) {
		if (l == 'A') res += 'C';
		else res += "AC";
		rest--;
	}

	rep (i, 1, rest) res += "AC";

	int st = res.length() + 1;
	rep (i, st, len) res += 'B';
	if (res.back() != r) res[res.length() - 1] = r;

	// recheck
	if (res.length() != len) return "";
	if (res.front() != l) return "";
	if (res.back() != r) return "";

	int tot = 0;
	rep (i, 0, (int) res.length() - 2) tot += (res[i] == 'A' and res[i + 1] == 'C');

	if (tot != c) return "";

	return res;
}

bool chk(char l1, char r1, char l2, char r2, i64 c1, i64 c2) {
	if (k == 1) return c1 == x;
	if (k == 2) return c2 == x;

	i64 cur = 0;
	rep (i, 3, k) {
		cur = c1 + c2 + (r1 == 'A' and l2 == 'C');
		char cur_l = l1, cur_r = r2;

		c1 = c2; l1 = l2; r1 = r2;
		c2 = cur; l2 = cur_l; r2 = cur_r;
	}

	return cur == x;
}

void solve() {
	std::cin >> k >> x >> n >> m;

	for (char l1 = 'A'; l1 <= 'C'; l1++) {
	for (char r1 = 'A'; r1 <= 'C'; r1++) {
	for (char l2 = 'A'; l2 <= 'C'; l2++) {
	for (char r2 = 'A'; r2 <= 'C'; r2++) {
		rep (c1, 0, (n >> 1)) {
			rep (c2, 0, (m >> 1)) {
				if (not chk(l1, r1, l2, r2, c1, c2)) continue;
				std::string s1 = make(l1, r1, c1, n);
				std::string s2 = make(l2, r2, c2, m);

				if (s1 == "" or s2 == "") continue;

				// dbg(l1); dbg(r1); dbg(c1);
				// dbg(l2); dbg(r2); dbg(c2);

				std::cout << s1 << "\n";
				std::cout << s2 << "\n";
				return;
			}
		}
	}}}}

	std::cout << "Happy new year!\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
