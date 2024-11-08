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

const int maxn = 50005;

int n, m;

struct Node {
	int l, r;
	int val, key, size;
};

Node fhq[maxn]; 

int root, cnt;

inline int newNode (int val) {
	cnt ++;
	fhq[cnt].val = val;
	fhq[cnt].key = rand ();
	fhq[cnt].size = 1;
	return cnt;
}

inline void update (int x) {
	fhq[x].size = fhq[fhq[x].l].size + fhq[fhq[x].r].size + 1;
}

void split (int now, int val, int &x, int &y) { // x <= val, y > val
	if (not now) {
		x = y = 0;
	} else if (fhq[now].val <= val) {
		x = now;
		split (fhq[now].r, val, fhq[now].r, y);
		update (now);
	} else {
		y = now;
		split (fhq[now].l, val, x, fhq[now].l);
		update (now);
	}
}

int merge (int x, int y) {
	if (not x or not y) {
		return x | y;
	} else if (fhq[x].key > fhq[y].key) {
		fhq[x].r = merge (fhq[x].r, y); // x 放在上面
		update (x);
		return x;
	} else {
		fhq[y].l = merge (x, fhq[y].l);
		update (y);
		return y;
	}
}

inline void remove (int val) {
	int x, y, z;
	split (root, val, x, y); // x <= val
	split (x, val - 1, x, z); // x < val, z = val
	z = merge (fhq[z].l, fhq[z].r);
	root = merge (merge (x, z), y); 	
}

inline void insert (int val) {
	int x, y;
	split (root, val, x, y);
	root = merge (merge (x, newNode(val)), y);
}

inline int pre (int val) {
	int x, y;
	split (root, val, x, y); // 此处可以相等
	
	int now = x;
	while (fhq[now].r) {now = fhq[now].r;}

	merge (x, y);
	return fhq[now].val;
}

inline int nxt (int val) {
	int x, y;
	split (root, val, x, y);

	int now = y;
	while (fhq[now].l) {now = fhq[now].l;}

	merge (x, y);
	return fhq[now].val; 
}

bool vis[maxn];

int main () {
	fastread
	
	cin >> n >> m;

	stack<int> s;
	
	insert (0);
	insert (n + 1);

	while (m --) {
		char opt; int x;
		cin >> opt;

		switch (opt) {
			case 'D': cin >> x; insert(x); s.push (x); vis[x] = true; break; // 维护被删除的
			case 'R': remove (s.top()); vis[s.top()] = false; s.pop(); break; 
			case 'Q': cin >> x; if (vis[x]) {cout << 0 << endl;} else {cout << (nxt (x) - 1) - (pre (x) + 1) + 1 << endl;} break;
		}
	}

	return 0;
}
