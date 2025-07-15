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

int A[3];
int a[3];

namespace Task1 {
    using Tuple = std::array<int, 3>;

    i64 base = 100000;
    inline i64 get(Tuple v) {
        return 1ll * v[0] * base * base + 1ll * v[1] * base + 1ll * v[2];
    }

    inline Tuple get_val(i64 h) {
        return Tuple {h / (base * base) % base, (h / base) % base, h % base};
    } 

    std::unordered_map<i64, int> ans;
    i64 qwq[maxn];
    
    inline void solve() {
        std::queue<i64> q;
        auto st = Tuple { a[0], a[1], a[2] };
        q.push(get(st));
        ans[get(st)] = 0;

        while (not q.empty()) {
            auto c = get_val(q.front()); q.pop();

            rep (i, 0, 2) {
                // to i
                rep (j, 0, 2) {
                    if (i == j) continue;
                    auto old = c;

                    if (c[i] + c[j] <= A[i]) {
                        c[i] += c[j];
                        c[j] = 0;
                    } else {
                        c[j] = old[i] + old[j] - A[i];
                        c[i] = A[i];
                    }
                    
                    Tuple t = {c[0], c[1], c[2]};

                    c = old;
                    
                    if (not ans.count(get(t))) {
                        ans[get(t)] = ans[get(c)] + 1;
                        q.push(get(t));
                    }
                }
            }
        }

        std::memset(qwq, 0x3f, sizeof qwq);
        for (auto x : ans) {
            auto cur = get_val(x.first);
            rep (k, 0, 2) {
                qwq[cur[k]] = std::min(qwq[cur[k]], 1ll * x.second);
            }
        }

        rep (i, 0, A[2]) {
            if (qwq[i] == 0x3f3f3f3f3f3f3f3f) std::cout << "-1 ";
            else std::cout << qwq[i] << " ";
        }
    }
}

void solve() {
    rep (i, 0, 2) std::cin >> A[i];
    rep (i, 0, 2) std::cin >> a[i];

    Task1::solve();

    lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("juice")

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
