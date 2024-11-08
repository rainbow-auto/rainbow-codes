#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

#pragma GCC Optimize(3)

const int maxn = 200005;

int n;

// std::unordered_map <int, std::set<int>> ns;

std::set <int> ns[maxn];

struct Node {
    int mx;
    int ls, rs;
} tr[maxn << 5];

int rt, tot;

inline void pushUp (int now) {
    tr[now].mx = std::max (tr[tr[now].ls].mx, tr[tr[now].rs].mx);
}

void modify (int& now, int l, int r, int pos, int val) {
    if (not now) { now = ++tot; }
    if (l == r) { tr[now].mx = val; return; }

    int mid = (l + r) >> 1;
    if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
    if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }

    pushUp (now);
}

int query (int now, int l, int r, int x, int y) {
    if (not now) { return -1; }
    if (l == r) { return (tr[now].mx > y ? l : -1); }

    int mid = (l + r) >> 1;
    int res = -1;
    if (x <= mid and tr[tr[now].ls].mx > y) { res = query (tr[now].ls, l, mid, x, y); }
    if (res != -1) { return res; }
    if (tr[tr[now].rs].mx > y) { return query (tr[now].rs, mid + 1, r, x, y); }
    return -1;
}

struct Query {
    int op;
    int x, y;
};

std::vector <Query> qs;

int vals[maxn], valCnt;

int main () {

    std::cin >> n;

    while (n--) {
        std::string s; int x, y;
        std::cin >> s >> x >> y;

        if (s[0] == 'a') { qs.push_back (Query { 1, x, y }); vals[++valCnt] = x; }        
        if (s[0] == 'r') { qs.push_back (Query { 2, x, y }); }
        if (s[0] == 'f') { qs.push_back (Query { 3, x, y }); vals[++valCnt] = x; }
    }

    std::sort (vals + 1, vals + valCnt + 1);
    valCnt = std::unique (vals + 1, vals + valCnt + 1) - vals - 1;

    for (auto &q : qs) { q.x = std::lower_bound (vals + 1, vals + valCnt + 1, q.x) - vals; }

    for (auto q : qs) {
        int x = q.x;
        int y = q.y;
        int op = q.op;

        if (op == 1) {
            ns[x].insert (y);
            modify (rt, 1, valCnt + 1, x, (*ns[x].rbegin ()));
        } else if (op == 2) {
            ns[x].erase (y);
            if (not ns[x].size ()) { modify (rt, 1, valCnt + 1, x, 0); }
            else { modify (rt, 1, valCnt + 1, x, (*ns[x].rbegin ())); }
        } else {
            int res = query (rt, 1, valCnt + 1, x + 1, y);
            if (res == -1) { std::cout << "-1\n"; }
            else { std::cout << vals[res] << " " << (*ns[res].upper_bound (y)) << "\n"; }
        }
    }

    return 0;
}