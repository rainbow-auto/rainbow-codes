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

const int maxn = 1000005;

int n, m;
i64 k;
i64 a[maxn];

bool chk(int l, int r, int p) {
	if (r + p > n) return false;

	std::vector<i64> b;
	rep (i, r + 1, r + p) b.push_back(a[i]);
	std::sort(b.begin(), b.end());

	std::vector<i64> c;
	std::merge(a + l, a + r + 1, b.begin(), b.end(), std::back_inserter(c));

	int lpos = 0, rpos = c.size() - 1;
	i64 sum = 0;
	rep (i, 1, m) {
		if (lpos >= rpos) break;

		i64 x = c[lpos++];
		i64 y = c[rpos--];

		sum += (y - x) * (y - x);
	}

	if (sum > k) return false;

	int cpos = 0;
	rep (i, l, r + p) a[i] = c[cpos++];

	return true;
}

// bool chk(int l, int r, int p) {
// 	if (r + p > n) return false;

// 	std::vector<i64> b;
// 	rep (i, l, r + p) b.push_back(a[i]);

// 	std::sort(b.begin(), b.end());

// 	int lpos = 0, rpos = (int) b.size() - 1;
// 	i64 sum = 0;
// 	rep (i, 1, m) {
// 		if (lpos >= rpos) break;
// 		i64 x = b[lpos++];
// 		i64 y = b[rpos--];
// 		sum += (y - x) * (y - x);
// 	}

// 	return sum <= k;
// }

void solve() {
	std::cin >> n >> m >> k;
	rep (i, 1, n) std::cin >> a[i];

	int l = 1, r = 1;

	int tot = 0;
	while (r <= n) {
		int p = 1;
		while (p) {
			if (r > n) break;
			if (chk(l, r, p)) {
				r += p;
				p <<= 1;
			} else {
				p >>= 1;
			}
		}
		tot ++;
		l = r + 1; r = l;
	} 

	std::cout << tot << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
