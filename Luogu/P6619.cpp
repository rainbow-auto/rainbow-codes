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
	int op;

	int t, x, y; // 1
	int id;      // 2
} infos[maxn];
int infoCnt;

int ice[maxn]; 
int fire[maxn];

int vals[maxn], valCnt;

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
	int fireSum = queryFire (valCnt);
	
	int firepre = 0, icepre = 0;
	int p = 0;

	for (int i = 20; i >= 0; i--) {
		int nxt = p + (1 << i);
		
		if (nxt > valCnt) { continue; }
		
		if (icepre + ice[nxt] < fireSum - (firepre + fire[nxt])) { p = nxt; icepre += ice[nxt]; firepre += fire[nxt]; }
	}

	return p + 1;
}

inline int find2 (int x) { // 最大的k 使得 E(k) = x
	int fireSum = queryFire (valCnt);

	int firepre = 0, icepre = 0;
	int p = 0;

	for (int i = 20; i >= 0; i--) {
		int nxt = p + (1 << i);

		if (nxt > valCnt) { continue; }

		if (icepre + ice[nxt] < fireSum - (firepre + fire[nxt])) { p = nxt; icepre += ice[nxt]; firepre += fire[nxt]; }
		else if (std::min (icepre + ice[nxt], fireSum - (firepre + fire[nxt])) == x) { p = nxt; icepre += ice[nxt]; firepre += fire[nxt]; }
	}

	return p + 1;
}

inline int calc (int k) {
	return std::min (queryIce (k), queryFire (valCnt) - queryFire (k - 1)); // q(r) - q(l - 1)
}

inline void solve () {
	int k1 = find1 ();

	int resk;
	if (k1 == valCnt) { resk = k1; }
	else {
		int k2 = find2 (calc (k1 + 1));

		if (calc (k2) >= calc (k1)) { resk = k2; }
		else { resk = k1; }
	}

	if (calc (resk) == 0) { std::cout << "Peace" << "\n"; }
	else { std::cout << vals[resk] << " " << calc (resk) * 2 << "\n"; }
}

int main () {
	fastread

	std::cin >> Q;

	for (int now = 1; now <= Q; now ++) {
		int op; std::cin >> op;
		
		if (op == 1) {
			int t, x, y; std::cin >> t >> x >> y;
			infos[++infoCnt] = Info { 1, t, x, y, 0 };
			
			vals[++valCnt] = x;	
		} else {
			int id; std::cin >> id;
			infos[++infoCnt] = Info { 2, 0, 0, 0, id };
		}
	}

	std::sort (vals + 1, vals + valCnt + 1);
	valCnt = std::unique (vals + 1, vals + valCnt + 1) - (vals + 1);

	for (int i = 1; i <= infoCnt; i ++) {
		if (infos[i].op == 2) { continue; } 

		infos[i].x = std::lower_bound (vals + 1, vals + valCnt + 1, infos[i].x) - vals;
	}
	
	for (int i = 1; i <= infoCnt; i ++) {
		if (infos[i].op == 1) {
			if (infos[i].t == 0) { modifyIce (infos[i].x, infos[i].y); }
			if (infos[i].t == 1) { modifyFire (infos[i].x, infos[i].y); }
		} else {
			int id = infos[i].id;

			if (infos[id].t == 0) { modifyIce (infos[id].x, -infos[id].y); }
			if (infos[id].t == 1) { modifyFire (infos[id].x, -infos[id].y); }
		}

		solve ();
	}

	return 0;
}
