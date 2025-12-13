// 别样的做法

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

constexpr int maxn = 5005;

int n, m;
std::string s, t;

struct Trie {
    struct Node {
        std::array<int, 26> ch;
        int ed;
    };

    int rt, tot;
    Node tr[10000000];
    
    Trie() {
        init();
    }
    
    inline void init() {
        tot = 1;
        rt = 1;
        tr[rt] = Node { {}, 0 };
    }

    Node& operator[](int x) {
        return tr[x];
    }

    inline void ins(const std::string &s) {
        int now = rt;
        for (char c : s) {
            int x = c - 'a';
            if (not tr[now].ch[x]) {
                tr[now].ch[x] = ++tot;
                tr[tot] = Node { {}, 0 };
            }
            now = tr[now].ch[x];
            tr[now].ed++;
        }
    }
} tr;

inline i64 calc(std::string s, std::string t, bool flg = false) {
    // db << "calc " << s << " " << t << "\n";

    std::vector<std::vector<int>> f(s.size() + 1, std::vector<int>(s.size() + 1));
    per (i, (int) s.size() - 1, 0) {
        per (j, (int) s.size() - 1, 0) {
            f[i][j] = 0;
            if (s[i] == s[j]) f[i][j] = f[i + 1][j + 1] + 1;
        }
    }

    std::reverse(t.begin(), t.end());

    tr.init();

    rep (i, 0, (int) t.size() - 1) tr.ins(t.substr(i));

    i64 res = 0;
    rep (i, 0, (int) s.size() - 1) {
        // dbg(i);

        std::vector<i64> sum(s.size());

        int now = tr.rt;
        per (j, i - 1, 0) {
            if (not tr[now].ch[s[j] - 'a']) break;
            now = tr[now].ch[s[j] - 'a'];
            sum[j] = tr[now].ed;
        }
        rep (j, 1, i - 1) sum[j] += sum[j - 1];

        auto qry = [&](int l, int r) -> i64 {
            if (l > r) return 0;
            if (l == 0) return sum[r];
            return sum[r] - sum[l - 1];
        };

        rep (j, 0, i - 1) {
            // dbg(j);
            // dbg(f[i][j]);
            int l = j + 1;
            int r = std::min(j + f[i][j], i - 1);
            // dbg(l); dbg(r);
            // dbg(qry(l, r));
            res += qry(l, r);
            // dbendl;
        }

        // db << "-----------\n";
    }

    if (flg) {
        std::reverse(s.begin(), s.end());
        rep (i, 0, s.size() - 1) {
            int now = tr.rt;
            rep (j, i, s.size() - 1) {
                int x = s[j] - 'a';
                if (not tr[now].ch[x]) break;
                now = tr[now].ch[x];
                res += tr[now].ed;
            }
        }
    }

    return res;
}

// 4 + 4 + 2 + 2 + 2 + 2

void solve() {
    std::cin >> s >> t;
    std::cout << calc(s, t) + calc(t, s, 1) << "\n";
}   

bool MemED;
int main() {
	fastread
	// lookMem	

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
