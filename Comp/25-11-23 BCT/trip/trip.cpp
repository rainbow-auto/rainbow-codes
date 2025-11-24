#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++) 
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--) 
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";

using i64 = long long;

constexpr int maxn = 100005;
constexpr i64 inf = 1e18;

int n, q, m;
int w[maxn];
i64 c[maxn];

namespace Task1 {
    constexpr int maxn = 1005;

    i64 f[maxn][maxn];

    struct Tree {
        struct Node {
            i64 mn;
            int ls, rs;
        } tr[maxn << 5];
        int rt, tot;
        
        Node $0 = { inf, 0, 0 };

        inline void pushUp(int now) {
            tr[now].mn = std::min(tr[tr[now].ls].mn, tr[tr[now].rs].mn);
        }   

        void mdf(int &now, int l, int r, int pos, i64 v) {
            if (not now) {
                now = ++tot;
                tr[now] = $0;
            }
            
            if (l == r) return tr[now].mn = std::min(tr[now].mn, v), void(0);
            int mid = (l + r) >> 1;
            if (pos <= mid) mdf(tr[now].ls, l, mid, pos, v);
            else mdf(tr[now].rs, mid + 1, r, pos, v);

            pushUp(now);
        }

        i64 qry(int now, int l, int r, int L, int R) {
            if (L > R) return inf;
            if (not now) return inf;
            if (L <= l and r <= R) return tr[now].mn;
            int mid = (l + r) >> 1;
            if (R <= mid) return qry(tr[now].ls, l, mid, L, R);
            if (L > mid) return qry(tr[now].rs, mid + 1, r, L, R);
            return std::min(qry(tr[now].ls, l, mid, L, R), qry(tr[now].rs, mid + 1, r, L, R));
        }

        inline void init() {
            rep (i, 0, tot) tr[i] = $0;
            rt = tot = 0;
        }
    } tr[2];

    inline void solve() {
        rep (to, 1, n) {
            rep (i, 1, n) f[to][i] = inf;
            f[to][to] = 0;
            
            tr[0].init();
            tr[1].init();
            
            rep (i, to, n) {
                f[to][i] = std::min(f[to][i], tr[0].qry(tr[0].rt, 0, 1e9, 0, w[i] - m - 1) + 1);
                f[to][i] = std::min(f[to][i], tr[1].qry(tr[1].rt, 0, 1e9, w[i] - m, 1e9) + 1);

                // rep (j, to, i - 1) {
                //     if (w[i] > w[j] + m) {
                //         f[to][i] = std::min(f[to][i], f[to][j] + c[j] + 1);
                //     } else {
                //         f[to][i] = std::min(f[to][i], f[to][j] + 1);
                //     }
                // }
                
                tr[0].mdf(tr[0].rt, 0, 1e9, w[i], f[to][i] + c[i]);
                tr[1].mdf(tr[1].rt, 0, 1e9, w[i], f[to][i]);
            }
        }
        
        rep (from, 1, n) {
            i64 pre = inf;
            rep (to, 1, from) {
                pre = std::min(pre, f[to][from]);
                f[to][from] = std::min(f[to][from], pre + 1);
            }
        }

        rep (t, 1, q) {
            int x, y; std::cin >> x >> y;
            if (x <= y) std::cout << "1\n";
            else std::cout << f[y][x] << "\n";
        }
        
        lookTime
    }
}

namespace TaskA {
    inline int getpos(int now) {
        int l = 1, r = now;
        int res = now;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (w[now] - w[mid] <= m) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }

    int nxt[19][maxn];

    inline int calc(int now, int to) {
        int res = 0;
        per (b, 18, 0) {
            if (nxt[b][now] > to) {
                now = nxt[b][now];
                res |= (1 << b);
            }
        }
        return res + 1;
    }

    inline void solve() {
        db << "TaskA\n";
        rep (i, 1, n) {
            int t = getpos(i);
            nxt[0][i] = t;
        }

        rep (b, 1, 18) {
            rep (i, 1, n) {
                nxt[b][i] = nxt[b - 1][nxt[b - 1][i]];
            }
        }

        rep (t, 1, q) {
            int x, y; std::cin >> x >> y;
            if (x <= y) std::cout << "1\n";
            else std::cout << calc(x, y) << "\n";
        }
    }
}

inline void solve() {
    std::cin >> n >> q >> m;
    rep (i, 1, n) std::cin >> w[i];
    rep (i, 1, n) std::cin >> c[i];

    bool flg = true;   
    rep (i, 1, n) flg &= (c[i] == int(1e9));

    if (flg) return TaskA::solve();
    Task1::solve();
}

int main() {
    fastread

    file("trip03")

    solve();

    return 0;
}