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

constexpr int maxn = 1000005;

int n;
int l[maxn], r[maxn];

// namespace Task1 {
//     inline void solve() {
//         int ans = 0;
//         rep (L, 1, n) {
//             int mx = -0x3f3f3f3f;
//             int len = 0;
//             rep (i, L, n) {
//                 mx = std::max(mx, l[i]);
//                 if (mx <= r[i]) len++;
//                 else break;
//             }

//             ans = std::max(ans, len);
//         }
//         std::cout << ans << "\n";
//     }
// }

std::vector<int> vals;

namespace Sol {
    struct SegTree{
        struct Node {
            int mn;
            Node() {
                mn = 0x3f3f3f3f;
            }
        } tr[maxn << 4];

        inline void pushup(int now) {
            tr[now].mn = std::min(tr[now << 1].mn, tr[now << 1 | 1].mn);
        }

        void mdf(int now, int l, int r, int pos, int v) {
            if (l == r) return tr[now].mn = std::min(tr[now].mn, v), void(0);
            int mid = (l + r) >> 1;
            if (pos <= mid) mdf(now << 1, l, mid, pos, v);
            else mdf(now << 1 | 1, mid + 1, r, pos, v);
            pushup(now);
        }

        int qry(int now, int l, int r, int R) {
            // dbg(now);
            // db << "l: " << l << " " << r << "\n";
            // dbg(R);
            if (r <= R) return tr[now].mn;
            int mid = (l + r) >> 1;
            if (R <= mid) return qry(now << 1, l, mid, R);
            return std::min(tr[now << 1].mn, qry(now << 1 | 1, mid + 1, r, R));
        }
    } tr;

    inline void solve() {
        rep (i, 1, n) vals.push_back(l[i]);
        rep (i, 1, n) vals.push_back(r[i]);

        std::sort(vals.begin(), vals.end());
        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());

        rep (i, 1, n) l[i] = std::lower_bound(vals.begin(), vals.end(), l[i]) - vals.begin() + 1;
        rep (i, 1, n) r[i] = std::lower_bound(vals.begin(), vals.end(), r[i]) - vals.begin() + 1;

        // rep (i, 1, n) db << l[i] << " "; dbendl;
        // rep (i, 1, n) db << r[i] << " "; dbendl;

        int ans = 0;
        int R = n;
        per (L, n, 1) {
            int t = tr.qry(1, 0, vals.size() - 1, l[L] - 1);
            // db << "kkk\n";
            tr.mdf(1, 0, vals.size() - 1, r[L], L);
            // db << "kkkkk\n";

            // int t = L;
            // for (; r[t] >= l[L] and t <= n; t++);
            
            if (t <= n) R = std::min(R, t - 1);
            ans = std::max(ans, R - (int) L + 1);
        }

        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> n;
    rep (i, 1, n) std::cin >> l[i] >> r[i];

    Sol::solve();
}

bool MemED;
int main() {
	fastread
	lookMem	

    // file("sequence")

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
