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

const int maxn = 1000005;

int n, m;
int fa[maxn];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    fa[v] = u;
}

void init() {
    rep (i, 1, n) fa[i] = i;
}

std::vector<std::pair<int, int>> a[12][12];

int dif[maxn];
void add(int l, int r) {
    if (l > r) return;
    dif[l] ++; dif[r + 1] --;
}

void solve() {
    std::cin >> n >> m;
    init();

    rep (i, 1, 10) {
        rep (j, 0, 9) {
            a[i][j].clear();
        }
    }

    rep (i, 1, m) {
        int l, d, k; std::cin >> l >> d >> k;
        int bll = (l / d) + 1;
        int blr = ((l + k * d) / d) + 1;
        a[d][l % d].push_back({ bll, blr });
    }
    
    rep (d, 1, 10) {
        rep (rst, 0, 9) {
            if (a[d][rst].empty()) continue;

            for (auto [l, r] : a[d][rst]) {
                add(l + 1, r);
            }
            
            int mx = 0;
            rep (i, 1, n) mx = std::max(mx, int(i / d + 1));
            rep (i, 1, mx + 1) dif[i] += dif[i - 1];

            int last = -1;
            rep (i, 1, n) {
                if (i % d != rst) continue;

                int bl = (i / d) + 1;

                if (dif[bl]) {
                    if (~last) {
                        merge(i, last);
                    } 
                }

                last = i;
            }

            rep (i, 0, mx + 1) dif[i] = 0;
        }
    }

    int cnt = 0;
    rep (i, 1, n) cnt += find(i) == i;
    std::cout << cnt << "\n";
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
