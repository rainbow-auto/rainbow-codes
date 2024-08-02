#include <iostream>
#include <vector>
#include <set>
#include <map>

const int maxn = 100005;

int n;

std::map <int, std::set<int>> ns;

struct Node {
    int mx;
    int ls, rs;
} tr[maxn << 3];

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

int query (int now, int l, int r, int k) {
    if (not now) { return -1; }
    if (l == r) { return (tr[now].mx > k ? l : -1); }

    int mid = (l + r) >> 1;
    if (tr[tr[now].ls].mx > k) { return query (tr[now].ls, l, mid, k); }
    if (tr[tr[now].rs].mx > k) { return query (tr[now].rs, mid + 1, r, k); }
    return -1;
}

int main () {

    std::cin >> n;

    while (n--) {
        int x, y; std::string s; 
        std::cin >> s >> x >> y;

        if (s == "add") {
            ns[x].insert (y);
            modify (rt, 0, 1e9, x, (*ns[x].rbegin ()));
        } else if (s == "remove") {
            ns[x].erase (y);
            if (not ns[x].size ()) { modify (rt, 0, 1e9, x, 0); }
            else { modify (rt, 0, 1e9, x, (*ns[x].rbegin ())); }
        } else {
            int res = query (rt, 0, 1e9, y);
            if (res == -1) { std::cout << "-1\n"; }
            else { std::cout << res << " " << (*ns[res].upper_bound (y)) << "\n"; }
        }
    }

    return 0;
}