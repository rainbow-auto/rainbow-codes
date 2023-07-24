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
#include <ctime>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 300005;

int n, minn;

struct Node {
	int l, r;
	int key, siz, val;
};

Node fhq[maxn];

int root, cnt;

inline int newNode (int val) {
	cnt ++;
	fhq[cnt].val = val;
	fhq[cnt].key = rand();
	fhq[cnt].siz = 1;
	return cnt;
}

inline void update (int x) { fhq[x].siz = fhq[fhq[x].l].siz + fhq[fhq[x].r].siz + 1; }

void split (int now, int val, int &x, int &y) {
	if (not now) {x = y = 0;}
	else if (fhq[now].val <= val) {x = now; split (fhq[now].r, val, fhq[now].r, y); update (now);}
	else {y = now; split (fhq[now].l, val, x, fhq[now].l); update (now);}
}

int merge (int x, int y) {
	if (not x or not y) {return x | y;}
	else if (fhq[x].key > fhq[y].key) {fhq[x].r = merge (fhq[x].r, y); update (x); return x;}
	else {fhq[y].l = merge (x, fhq[y].l); update (y); return y;}
}

int get_num (int rank) {
	int now = root;

	while (now) {
		if (fhq[fhq[now].l].siz + 1 == rank) {return now;}
		else if (fhq[fhq[now].l].siz >= rank) { now = fhq[now].l; }
		else {rank -= fhq[fhq[now].l].siz + 1; now = fhq[now].r; }
	}

	return 0;
}

void insert (int val) {
	int x, y;
	split (root, val, x, y); // x <= val
	root = merge (merge (x, newNode(val)), y);	
}

int remove (int val) {
	int x, y;
	split (root, val - 1, x, y);
	root = y;
	return fhq[x].siz;
}

int main () {
	fastread
	
	cin >> n >> minn;
	
	int delta = 0; // 用 delta 记录整体工资变化 (相当于一个整体懒标记)
	int leave = 0;

	for (int i = 1; i <= n; i++) {
		char opt; int k;
		cin >> opt >> k;

		switch (opt) {
			case 'I': if (k >= minn) {insert (k - delta);} break;
			case 'A': delta += k; break;
			case 'S': delta -= k; leave += remove (minn - delta); break;
			case 'F': 
				if (fhq[root].siz < k) { cout << -1 << endl; } 
				else { cout << fhq[get_num (fhq[root].siz - k + 1)].val + delta << endl; } 
				break; // 注意是第k大
		}
	}
	cout << leave << endl;

	return 0;
}
