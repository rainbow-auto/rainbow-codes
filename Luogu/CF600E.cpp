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

const int maxn = 100005;

int n;
int col[maxn];

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) { 
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

int rt[maxn];

struct Node {
    i64 mx_cnt;
    i64 id_sum;

    friend Node operator + (Node a, Node b) {
		if (a.mx_cnt == b.mx_cnt) { return Node { a.mx_cnt, a.id_sum + b.id_sum }; }
		if (a.mx_cnt < b.mx_cnt) { return b; }
		else { return a; }
	}
}; 

struct Tree {
    int ls, rs;
    Node val;
} tr[maxn << 5];
int tot;

void modify (int& now, int l, int r, int val) {
	if (not now) { now = ++tot; }
    if (l == r) { tr[now].val = Node { 1, val }; return; }

    int mid = (l + r) >> 1;
	if (val <= mid) { modify (tr[now].ls, l, mid, val); }
    if (val > mid) { modify (tr[now].rs, mid + 1, r, val); }
	tr[now].val = tr[tr[now].ls].val + tr[tr[now].rs].val;
}

int merge (int a, int b, int l, int r) {
	if (not a or not b) { return a + b; }
	if (l == r) { tr[a].val.mx_cnt = tr[a].val.mx_cnt + tr[b].val.mx_cnt; return a; }

	int mid = (l + r) >> 1;
	tr[a].ls = merge (tr[a].ls, tr[b].ls, l, mid);
	tr[a].rs = merge (tr[a].rs, tr[b].rs, mid + 1, r);
	tr[a].val = tr[tr[a].ls].val + tr[tr[a].rs].val;
	
	return a;
}

i64 ans[maxn];

void get_ans (int now, int fa) {
    modify (rt[now], 1, n, col[now]);
	for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
		if (t == fa) { continue; }

    	get_ans (t, now);
		merge (rt[now], rt[t], 1, n);
    }    
	ans[now] = tr[rt[now]].val.id_sum;
}

int main () {
	fastread

    std::cin >> n;

	for (int i = 1; i <= n; i++) { std::cin >> col[i]; }

    for (int i = 1; i <= n - 1; i++) {
        int u, v; std::cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
	}


	get_ans (1, -1);

	for (int i = 1; i <= n; i++) { std::cout << ans[i] << " "; }

    return 0;
} 
