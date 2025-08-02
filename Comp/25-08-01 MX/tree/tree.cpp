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

constexpr int maxn = 500005;

int n;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;
int deg[maxn];

inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
    deg[v]++;
}

namespace TaskB {
    inline void solve(int rt) {
        std::array<i64, 2> cnt; cnt.fill(0);
        for (int i = last[rt]; i; i = es[i].pre) {
            int t = es[i].v;
            cnt[t > rt]++;
        }        
        std::cout << cnt[0] * cnt[1] + (n - 1) << "\n";
    }
}

namespace TaskA {
    /*
    1 4
    1 5
    2 3
    2 4
    2 5
    3 5
    */
    
    int a[maxn];
    
    void dfs(int now, int fa) {
        a[++a[0]] = now;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now);
        }
    }

    int pos[maxn];

    int mn_l[maxn], mn_r[maxn];
    int mx_l[maxn], mx_r[maxn];

    inline void init() {
        rep (i, 1, n) pos[a[i]] = i;
        
        std::set<int> vis;
        vis.insert(0); vis.insert(n + 1);
        rep (i, 1, n) {
            auto it = vis.lower_bound(pos[i]);   
            mn_r[pos[i]] = (*it) - 1;
            mn_l[pos[i]] = (*std::prev(it)) + 1;
            vis.insert(pos[i]);
        }
    
        std::set<int>().swap(vis);
        vis.insert(0); vis.insert(n + 1);
        per (i, n, 1) {
            auto it = vis.lower_bound(pos[i]);
            mx_r[pos[i]] = (*it) - 1;
            mx_l[pos[i]] = (*std::prev(it)) + 1;
            vis.insert(pos[i]);
        }
    }

    struct Tree {
        struct Node {
            int ls, rs;
            i64 sum;
        } tr[maxn << 4];

        int rt[maxn], tot;
        void mdf(int &now, int old, int l, int r, int pos, int v) {
            now = ++tot;
            tr[now] = tr[old];
            if (l == r) return tr[now].sum += v, void(0);
            int mid = (l + r) >> 1;
            if (pos <= mid) mdf(tr[now].ls, tr[old].ls, l, mid, pos, v);
            else mdf(tr[now].rs, tr[old].rs, mid + 1, r, pos, v);
            tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum;
        }
        
        i64 qry(int now, int l, int r, int L, int R) {
            if (not now) return 0;
            if (L <= l and r <= R) return tr[now].sum;
            int mid = (l + r) >> 1;
            if (R <= mid) return qry(tr[now].ls, l, mid, L, R);
            if (L > mid) return qry(tr[now].rs, mid + 1, r, L, R);
            return qry(tr[now].ls, l, mid, L, R) + qry(tr[now].rs, mid + 1, r, L, R);
        }

        inline void clr() {
            std::memset(rt, 0, sizeof rt);
            tot = 0;
        }
    } tr;

    inline void solve() {
        rep (i, 1, n) if (deg[i] == 1) { dfs(i, 0); break; }
        
        // rep (i, 1, n) db << a[i] << " "; dbendl;
        init();

        i64 ans = 0;

        tr.rt[0] = ++tr.tot;
        rep (i, 1, n) {
            i64 R = tr.qry(tr.rt[i - 1], 0, n + 1, i, n + 1);
            i64 L = tr.qry(tr.rt[mx_l[i] - 1], 0, n + 1, i, n + 1);

            ans += R - L;

            tr.mdf(tr.rt[i], tr.rt[i - 1], 0, n + 1, mn_r[i], 1);
        }
        
        tr.clr();
        
        tr.rt[0] = ++tr.tot;
        rep (i, 1, n) {
            i64 R = tr.qry(tr.rt[i - 1], 0, n + 1, i, n + 1);
            i64 L = tr.qry(tr.rt[mn_l[i] - 1], 0, n + 1, i, n + 1);

            ans += R - L;

            tr.mdf(tr.rt[i], tr.rt[i - 1], 0, n + 1, mx_r[i], 1);
        }
        
        std::cout << ans << "\n";
    }
}

namespace Task0 {
    int fa[maxn], siz[maxn], son[maxn], dep[maxn];
    void dfs1(int now) {
        siz[now] = 1;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) continue;
            fa[t] = now;
            dep[t] = dep[now] + 1;
            dfs1(t);
            siz[now] += siz[t];
            if (siz[t] > siz[son[now]]) son[now] = t;
        }
    }

    int top[maxn], dfn[maxn], dpos;
    int id[maxn];
    void dfs2(int now, int topnow) {
        dfn[now] = ++dpos;
        id[dfn[now]] = now;
        top[now] = topnow;

        if (not son[now]) return;
        dfs2(son[now], topnow);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) continue;
            if (t == son[now]) continue;

            dfs2(t, t);
        }
    }

    struct Info {
        int mx, mn;
    };

    inline Info mrg(Info a, Info b) {
        return Info { std::max(a.mx, b.mx), std::min(a.mn, b.mn) };
    }

    struct SegTree {
        Info tr[maxn << 2];

        void build(int now, int l, int r) {
            if (l == r) return tr[now] = Info { id[l], id[l] }, void(0);
            int mid = (l + r) >> 1;
            build(now << 1, l, mid);
            build(now << 1 | 1, mid + 1, r);
            tr[now] = mrg(tr[now << 1], tr[now << 1 | 1]);
        }

        Info qry(int now, int l, int r, int L, int R) {
            if (L <= l and r <= R) return tr[now];
            int mid = (l + r) >> 1;
            if (R <= mid) return qry(now << 1, l, mid, L, R);
            if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
            return mrg(qry(now << 1, l, mid, L, R), qry(now << 1 | 1, mid + 1, r, L, R));
        }
    } tr;

    inline Info qry(int u, int v) {
        Info res = Info { 0, 0x3f3f3f3f };
        while (top[u] != top[v]) {
            if (dep[top[v]] < dep[top[u]]) {
                res = mrg(res, tr.qry(1, 1, dpos, dfn[top[u]], dfn[u]));
                u = fa[top[u]];
            } else {
                res = mrg(res, tr.qry(1, 1, dpos, dfn[top[v]], dfn[v]));
                v = fa[top[v]];
            }
        }
        if (dep[u] < dep[v]) res = mrg(res, tr.qry(1, 1, dpos, dfn[u], dfn[v]));
        else res = mrg(res, tr.qry(1, 1, dpos, dfn[v], dfn[u]));

        return res;
    }

    inline void solve() {
        dfs1(1);
        dfs2(1, 1);
        tr.build(1, 1, dpos);

        i64 ans = 0;
        rep (u, 1, n) {
            rep (v, u + 1, n) {
                auto res = qry(u, v);
                if (res.mx == u and res.mn == v) {
                    db << u << " " << v << "\n";
                    ans++;
                } else if (res.mx == v and res.mn == u) {
                    db << u << " " << v << "\n";
                    ans++;
                }
            }
        }

        std::cout << ans << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    rep (i, 1, n) if (deg[i] == n - 1) return TaskB::solve(i), void(0);
    
    bool flgA = true;
    rep (i, 1, n) flgA &= (deg[i] <= 2);
    if (flgA) return TaskA::solve(), void(0);
    
    Task0::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("tree")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
