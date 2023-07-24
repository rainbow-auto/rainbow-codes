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

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 100005;

int n;

struct Node {
	int l, r;
	int val, key, size;
};

Node fhq[maxn];
int cnt, root;

inline int newNode (int val) {
	cnt ++;
	fhq[cnt].val = val;
	fhq[cnt].key = rand();
	fhq[cnt].size = 1;
	return cnt;	
}

inline void update (int x) {
	fhq[x].size = fhq[fhq[x].l].size + fhq[fhq[x].r].size + 1;
}

void split (int now, int val, int& x, int& y) { // x <= val y > val
	if (not now) {
		x = y = 0;
	} else if (fhq[now].val > val) { 
		y = now; // now 和 它的右子树都一定 > val
		split (fhq[now].l, val, x, fhq[now].l); // 左小右大
		update (now);
	} else {
		x = now; // now 和 它的左子树都一定 <= val
		split (fhq[now].r, val, fhq[now].r, y); // 左小右大
		update (now);
	}
}

int merge (int x, int y) { // 把 y 合并到 x 上 (x 小 y 大)
	if (not x or not y) {
		return x | y; // 有一个是零, 因此加/或起来的一定是那个不为0的
	} else if (fhq[x].key < fhq[y].key) { // 考虑维护key是堆的性质
		fhq[x].r = merge (fhq[x].r, y); // x 放在上面
		update (x);
		return x;
	} else {
		fhq[y].l = merge (x, fhq[y].l); // y 放在上面
		update (y);
		return y;
	}
}

inline void insert (int val) {
	int x, y;
	split (root, val, x, y); // x: <= val
	x = merge (x, newNode(val));
	root = merge (x, y);
}

int remove (int val) {
	int x, y;
	split (root, val - 1, x, y);
	root = y;
	return fhq[x].size;
}

inline int pre (int val) {
	int x, y;
	split (root, val - 1, x, y);

	int now = x; // 小于 val
	while (fhq[now].r) {now = fhq[now].r;} // 中最大的
	
	root = merge (x, y);

	return fhq[now].val;
}	

inline int nxt (int val) {
	int x, y;
	split (root, val, x, y);
	
	int now = y; // 大于 val
	while (fhq[now].l) {now = fhq[now].l;} // 中最小的

	root = merge (x, y);

	return fhq[now].val;
}

inline int get_rank (int val) {
	int x, y;
	split (root, val - 1, x, y); // 比 val 的数
	int rank = fhq[x].size + 1;
	merge (x, y);

	return rank;
}

inline int get_num (int rank) {
	int now = root;
	while (now) {
		if (fhq[fhq[now].l].size + 1 == rank) {return fhq[now].val;}
		else if (fhq[fhq[now].l].size >= rank) {now = fhq[now].l;}
		else {rank -= fhq[fhq[now].l].size + 1; now = fhq[now].r;}
	}
	return -1; // 不存在
}

int main () {
	fastread

	// srand(time(0));

    int minn, leave = 0, delta = 0;
	cin >> n >> minn;

	while (n --) {
		char opt; int k;
		cin >> opt >> k;

		switch (opt) {
			case 'I': if (k >= minn) {insert (k - delta); } break;
			case 'A': delta += k; break;
			case 'S': delta -= k; leave += remove (minn - delta); break;
			case 'F': 
				if (fhq[root].size < k) {
					// cout << "small ";
					cout << -1 << endl; 
				} else { 
					// cout << "getnum = " << get_num (k - fhq[root].siz + 1) << endl;
					cout << fhq[get_num (k - fhq[root].size + 1)].val + delta << endl;  // 注意是第k大
				} break;
		}
	}

	return 0;
}
