#include <iostream>

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

	return 0;
}