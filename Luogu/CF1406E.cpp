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

const int maxn = 100005;

int n;

int A(int x) {
	std::cout << "A " << x << std::endl;
	int res; std::cin >> res;
	return res;
}

int B(int x) {
	std::cout << "B " << x << std::endl;
	int res; std::cin >> res;
	return res;
}

void C(int x) {
	std::cout << "C " << x << std::endl;
}

std::bitset<maxn> np;

const int Bsiz = 100;

i64 query(i64 p) {
	i64 res = 1;
	for (i64 j = p * p; j <= n; j *= p) {
		if (A(j)) {
			res *= p;
		} else {
			break;
		}
	}
	return res;
}

int ps[maxn];
void solve() {
	std::cin >> n;

	int rst = n;
	int tot = 0;

	bool foundFST = false;

	i64 res = 1;
	int lst = 1;

	np.reset();
	rep (i, 2, n) {
		if (np[i]) continue;

		ps[++tot] = i;

		int cur = 0;
		for (i64 j = i; j <= n; j += i) {
			rst -= not np[j];
			cur += not np[j];
			np.set(j);
		}

		if (B(i) != cur) {
			res *= i;
			res *= query(i);
		}

		if (foundFST) continue;
 
		if (tot % Bsiz == 0) {
			if (A(1) != rst) {
				rep (j, lst, tot) {
					int p = ps[j];
					if (A(p)) {
						res *= p;
						res *= query(p);
						foundFST = true;
						break;
					}
				}
			}
			lst = tot + 1;
		}
	}

	if (not foundFST and lst <= tot) {
		if (A(1) != rst) {
			rep (j, lst, tot) {
				i64 p = ps[j];
				if (A(p)) {
					res *= p;
					res *= query(p);
					foundFST = true;
					break;
				}
			}
		}
	}

	C(res);
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
