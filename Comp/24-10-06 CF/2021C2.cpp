#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 200005;

int n, m, q;
int a[maxn], b[maxn];

int fst[maxn];

struct Tree {
    struct Node {
        bool sum;
    } tr[maxn << 2];

    void clear(int now, int l, int r) {
        tr[now] = { false };
        if (l == r) return;
        int mid = (l + r) >> 1;
        clear(now << 1, l, mid);
        clear(now << 1 | 1, mid + 1, r);
    }

    void pushUp(int now) {
        tr[now].sum = tr[now << 1].sum and tr[now << 1 | 1].sum;
    }

    void modify(int now, int l, int r, int pos, bool val) {
        if (pos > r) return;
        if (l == r) return tr[now].sum = val, void(0);
        int mid = (l + r) >> 1;
        if (pos <= mid) modify(now << 1, l, mid, pos, val);
        else modify(now << 1 | 1, mid + 1, r, pos, val);
        pushUp(now);
    }
    
    bool chk() {
        return tr[1].sum;
    }
} tr;

std::set<int> s[maxn];

int w[maxn];
int apos[maxn];

void solve() {
    std::cin >> n >> m >> q;

    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, m) std::cin >> b[i];

    rep (i, 1, m) s[b[i]].insert(i);

    rep (i, 1, n) apos[a[i]] = i;

    rep (i, 1, n) w[i] = s[a[i]].empty() ? (m + 1) : (*s[a[i]].begin());
    w[n + 1] = m + 1;

    rep (i, 1, n + 1) tr.modify(1, 1, n + 1, i, w[i] >= w[i - 1]);

    auto out = [&]() -> void {
        std::cout << (tr.chk() ? "YA\n" : "TIDAK\n");
    };

    out();

    rep (i, 1, q) {
        int pos, val; std::cin >> pos >> val;
        
        int old = b[pos];
        s[old].erase(pos);
        w[apos[old]] = s[old].empty() ? (m + 1) : (*s[old].begin());
        tr.modify(1, 1, n + 1, apos[old], w[apos[old]] >= w[apos[old] - 1]);
        tr.modify(1, 1, n + 1, apos[old] + 1, w[apos[old] + 1] >= w[apos[old]]);

        b[pos] = val;
        s[val].insert(pos);
        w[apos[val]] = s[val].empty() ? (m + 1) : (*s[val].begin());
        tr.modify(1, 1, n + 1, apos[val], w[apos[val]] >= w[apos[val] - 1]);
        tr.modify(1, 1, n + 1, apos[val] + 1, w[apos[val] + 1] >= w[apos[val]]);

        out();
    }

    // clear
    tr.clear(1, 1, n + 1);
    rep (i, 1, n) s[i].clear();
    rep (i, 1, n + 1) apos[i] = w[i] = 0;
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
