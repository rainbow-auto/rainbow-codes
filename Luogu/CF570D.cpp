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

const int maxn = 500050;

int n, m;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

struct Query {
    int dep;
    int ord;

    bool ans;

    friend bool operator < (Query a, Query b) {
        return a.ord < b.ord;
    }    
};

std::vector <Query> qs[maxn];

struct Node {
    int ls, rs;
    int val;
} tr[maxn << 5];
int rt[maxn], tot;

void modify (int& now, int l, int r, int pos, int val) {
	if (not now) { now = ++tot; }
    if (l == r) { tr[now].val ^= val; return; }

    int mid = (l + r) >> 1;
    if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
    else { modify (tr[now].rs, mid + 1, r, pos, val); }

    tr[now].val = tr[tr[now].ls].val xor tr[tr[now].rs].val;
}

int query (int now, int l, int r, int pos) {
    if (not now) { return 0; }
    if (l == r) { return tr[now].val; }

    int mid = (l + r) >> 1;
    if (pos <= mid) { return query (tr[now].ls, l, mid, pos); }
    else { return query (tr[now].rs, mid + 1, r, pos); }
}

int merge (int a, int b, int l, int r) {
    if (not a or not b) { return a + b; }
    if (l == r) { tr[a].val ^= tr[b].val; return a; }

    int mid = (l + r) >> 1;
    tr[a].ls = merge (tr[a].ls, tr[b].ls, l, mid);
    tr[a].rs = merge (tr[a].rs, tr[b].rs, mid + 1, r);

    tr[a].val = tr[tr[a].ls].val xor tr[tr[a].rs].val;

	return a;
}

int dep[maxn];
void get_dep (int now, int fa) {
    dep[now] = dep[fa] + 1;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }
        get_dep (t, now);
    }
}

bool check (int x) { int res = 0; while (x) { if (x & 1) { res ++; } x >>= 1; } return res <= 1; }

int make_val (char ch) { return 1 << (ch - 'a'); }

void get_ans (int now, int fa) {
	for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }
		
		get_ans (t, now);

        rt[now] = merge (rt[now], rt[t], 1, n);
    }

	if (qs[now].size ()) {
		for (auto &q : qs[now]) {
			q.ans = check (query (rt[now], 1, n, q.dep));
		}
	}
}

int main () {
	fastread

    std::cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        int p; std::cin >> p;
        addEdge (p, i);
        addEdge (i, p);
    }

    get_dep (1, 0);
    for (int i = 1; i <= n; i++) { char c; std::cin >> c; modify (rt[i], 1, n, dep[i], make_val (c)); }

    for (int i = 1; i <= m; i++) {
        int a, b; std::cin >> a >> b;
        qs[a].push_back (Query { b, i });
    }


    get_ans (1, 0);

	std::vector <Query> ans;
	for (int i = 1; i <= n; i++) { for (auto now : qs[i]) { ans.push_back (now); } qs[i].clear (); }
	std::sort (ans.begin (), ans.end ());

    for (auto now : ans) {
        std::cout << (now.ans ? "Yes" : "No") << "\n";
    }

    return 0;
}
