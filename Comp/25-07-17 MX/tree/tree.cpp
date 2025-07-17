#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;

int q;
i64 w[maxn];

namespace Subtask1 {
    i64 s1[maxn], s2[maxn];
    int tot;
    i64 ans;

    int fa[maxn];

    inline void display() {
        db << "s1: "; rep (k, 1, tot) db << s1[k] << " "; dbendl;
        db << "s2: "; rep (k, 1, tot) db << s2[k] << " "; dbendl;
    }

    inline void add(int id, int _w, int f) {
        fa[id] = f;
        w[id] = _w;
        
        s1[id] = 1ll * w[id]; // w[now] * siz[now]
        s2[id] = 1ll * w[fa[id]];

        // qry
        int now = fa[id];
        while (now) {
            ans += s1[now];
            now = fa[now];
        }
        now = fa[id];
        while (now) {
            ans -= s2[now];
            now = fa[now];
        }

        ans += w[id];

        // upd
        now = fa[id];
        while (now) {
            s1[now] += w[now];
            now = fa[now];
        }

        now = fa[id];
        while (fa[now]) {
            s2[now] += w[fa[now]];
            now = fa[now];
        }

        // display();
        // dbg(ans);
    }

    inline void solve() {
        std::cin >> w[1];
        fa[1] = 0;
        s1[1] = w[1];

        ans = w[1];

        tot = 1;

        while (q--) {
            int op; std::cin >> op;
            if (op == 1) {
                int w, f; std::cin >> w >> f;
                add(++tot, w, f);
            } else {
                std::cout << ans << "\n";
            }
        }        
    }
}

namespace Subtask2 {
    struct Query {
        int op;
        int id, w;
    } qs[maxn];

    int tot;
    i64 ans;

    std::vector<int> g[maxn];
    int fa[maxn], dep[maxn], siz[maxn], son[maxn];

    void dfs1(int now) {
        siz[now] = 1;
        for (auto t : g[now]) {
            dep[t] = dep[now] + 1;
            dfs1(t);
            siz[now] += siz[t];
            if (siz[t] > siz[son[now]]) son[now] = t;
        }
    }

    int dfn[maxn], dpos, top[maxn];
    void dfs2(int now, int topnow) {
        dfn[now] = ++dpos;
        top[now] = topnow;
        if (not son[now]) return;
        dfs2(son[now], topnow);

        for (auto t : g[now]) {
            if (t != son[now]) dfs2(t, t);
        }
    }

    struct SegTree {
        struct Node {
            i64 tag;
            i64 sum_w;
            i64 sum_s;
        } tr[maxn << 2];

        inline void apply(int now, int c) {
            tr[now].sum_s += tr[now].sum_w * c;
            tr[now].tag += c;
        }

        inline void pushdown(int now) {
            if (not tr[now].tag) return;
            apply(now << 1, tr[now].tag);
            apply(now << 1 | 1, tr[now].tag);
            tr[now].tag = 0;
        }

        inline void pushup(int now) {
            tr[now].sum_w = tr[now << 1].sum_w + tr[now << 1 | 1].sum_w;
            tr[now].sum_s = tr[now << 1].sum_s + tr[now << 1 | 1].sum_s;
        }

        void mdf_w(int now, int l, int r, int pos, int v) {
            if (l == r) return tr[now].sum_s = tr[now].sum_w = v, void(0);
            pushdown(now);
            int mid = (l + r) >> 1;
            if (pos <= mid) mdf_w(now << 1, l, mid, pos, v);
            else mdf_w(now << 1 | 1, mid + 1, r, pos, v);
            pushup(now);
        }

        void mdf_rg(int now, int l, int r, int L, int R) {
            if (L <= l and r <= R) return apply(now, 1);
            pushdown(now);
            int mid = (l + r) >> 1;
            if (L <= mid) mdf_rg(now << 1, l, mid, L, R);
            if (R > mid) mdf_rg(now << 1 | 1, mid + 1, r, L, R);
            pushup(now);
        }

        i64 qry_s(int now, int l, int r, int L, int R) {
            if (L <= l and r <= R) return tr[now].sum_s;
            pushdown(now);
            int mid = (l + r) >> 1;
            if (R <= mid) return qry_s(now << 1, l, mid, L, R);
            if (L > mid) return qry_s(now << 1 | 1, mid + 1, r, L, R);
            return qry_s(now << 1, l, mid, L, R) + qry_s(now << 1 | 1, mid + 1, r, L, R);
        }

    } t1, t2;

    inline i64 qry_s1(int u) {
        i64 res = 0;
        while (top[u] != 1) {
            res += t1.qry_s(1, 1, dpos, dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        res += t1.qry_s(1, 1, dpos, dfn[1], dfn[u]);
        return res;
    }

    inline i64 qry_s2(int u) {
        i64 res = 0;
        while (top[u] != 1) {
            res += t2.qry_s(1, 1, dpos, dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        res += t2.qry_s(1, 1, dpos, dfn[1], dfn[u]);
        return res;
    }
    
    inline void mdf_s1(int u) {
        while (top[u] != 1) {
            t1.mdf_rg(1, 1, dpos, dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        t1.mdf_rg(1, 1, dpos, dfn[1], dfn[u]);
    }

    inline void mdf_s2(int u) {
        while (top[u] != 1) {
            t2.mdf_rg(1, 1, dpos, dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        t2.mdf_rg(1, 1, dpos, dfn[1], dfn[u]);
    }

    inline void add(int id) {
        t1.mdf_w(1, 1, dpos, dfn[id], w[id]);
        t2.mdf_w(1, 1, dpos, dfn[id], w[fa[id]]);
        ans += w[id];
        
        ans += qry_s1(fa[id]);
        ans -= qry_s2(fa[id]);

        mdf_s1(fa[id]);
        mdf_s2(fa[id]);
    }

    inline void solve() {
        std::cin >> w[1];
        fa[1] = 0;
        ans = w[1];

        tot = 1;

        rep (t, 1, q) {
            int op; std::cin >> op;
            if (op == 1) {
                int _w, f; std::cin >> _w >> f;
                ++tot;
                fa[tot] = f;
                g[f].push_back(tot);
                w[tot] = _w;
                qs[t] = Query{1, tot, w[tot]};
            } else {
                qs[t] = Query{2, 0, 0};
            }
        }    

        dfs1(1);
        dfs2(1, 1);
        
        t1.mdf_w(1, 1, dpos, dfn[1], w[1]);
        
        
        rep (t, 1, q) {
            auto qcur = qs[t];
            if (qcur.op == 1) {
                add(qcur.id);
            } else {
                std::cout << ans << "\n";
            }
        }
    }
}

void solve() {
    std::cin >> q;
    // Subtask1::solve();
    Subtask2::solve();
}

bool MemED;
int main() {
	fastread
	lookMem	

    file("tree")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

    lookTime

	return 0;
}
