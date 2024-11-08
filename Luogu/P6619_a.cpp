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

const int maxn = 2000005;

int Q;

struct Info {
	int t, x, y; 
} infos[maxn];

int vals[maxn], valCnt;

int ice[maxn], fire[maxn];

inline int lowbit (int x) { return x & (-x); }

inline void modifyIce (int pos, int val) {
	for (int i = pos; i <= valCnt; i += lowbit (i)) { ice[i] += val; }
}

inline int queryIce (int pos) {
	int res = 0;
	for (int i = pos; i; i -= lowbit (i)) { res += ice[i]; }
	return res;
}

inline void modifyFire (int pos, int val) {
	for (int i = pos; i <= valCnt; i += lowbit (i)) { fire[i] += val; }
}

inline int queryFire (int pos) {
	int res = 0;
	for (int i = pos; i; i -= lowbit (i)) { res += fire[i]; }
	return res;
}

inline int find1 () { // 最大的k 使得 ice(k) < fire(k)
	int firesum = queryFire (valCnt);

	int icepre = 0, firepre = 0;
	int p = 0;

	for (int i = 20; i >= 0; i--) {
		int nxt = p + (1 << i);

		if (nxt > valCnt) { continue; }

		if (icepre + ice[nxt] < firesum - (firepre + fire[nxt])) { p = nxt; icepre += ice[nxt]; firepre += fire[nxt]; }
	}

	return p + 1; // 刚才二分出来的p刚好是我们所求后缀的l - 1, 前缀的r - 1
}

inline int find2 (int x) { // 最大的k 使得 E(k) = x
	int firesum = queryFire (valCnt);

	int icepre = 0, firepre = 0;
	int p = 0;

	for (int i = 20; i >= 0; i--) {
		int nxt = p + (1 << i);

		if (nxt > valCnt) { continue; }

		if (icepre + ice[nxt] < firesum - (firepre + fire[nxt])) { p = nxt; icepre += ice[nxt]; firepre += fire[nxt]; }
		else if (std::min (icepre + ice[nxt], firesum - (firepre + fire[nxt])) == x) { p = nxt; icepre += ice[nxt]; firepre += fire[nxt]; }
	}

	return p + 1; // 同理
}

inline int calc (int k) {
	return std::min (queryIce (k), queryFire (valCnt) - queryFire (k - 1)); // q(r) - q(l - 1) => [l, r]
}

inline void solve () {
	int k1 = find1 ();

	int resk;
	if (k1 == valCnt) { resk = k1; }
	else {
		int k2 = find2 (calc (k1 + 1));
		
		if (calc (k2) >= calc (k1)) { resk = k2; } // 等于也应取k2 (显然k2 > k1)
		else { resk = k1; }
	}

	if (calc (resk) == 0) { std::cout << "Peace" << "\n"; }
	else { std::cout << vals[resk] << " " << calc (resk) * 2 << "\n"; }
}

int main () {
	fastread

	std::cin >> Q;

	for (int i = 1; i <= Q; i++) {
		int op; std::cin >> op;

		if (op == 1) {
			int t, x, y; std::cin >> t >> x >> y;
			infos[i] = Info { t, x, y };
			vals[++valCnt] = x;
		} else {
			int id; std::cin >> id;
			infos[i] = Info { infos[id].t, infos[id].x, -infos[id].y };
		}
	}

	std::sort (vals + 1, vals + valCnt + 1);
	valCnt = std::unique (vals + 1, vals + valCnt + 1) - (vals + 1);

	for (int i = 1; i <= Q; i++) {
		infos[i].x = std::lower_bound (vals + 1, vals + valCnt + 1, infos[i].x) - vals;
	}

	for (int i = 1; i <= Q; i++) {
		if (infos[i].t == 0) { modifyIce (infos[i].x, infos[i].y); }
		else { modifyFire (infos[i].x, infos[i].y); }
	
		solve ();
	}

	return 0;
}
