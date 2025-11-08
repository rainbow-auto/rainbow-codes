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

constexpr int maxn = 2000005;
constexpr int maxq = 200005;

int n, q;

u64 get(std::string s) {
    u64 h = 0;
    rep (i, 1, n) h = h * base + s[i] - 'a';
    return h;
}

std::map<std::pair<u64, u64>, int> id;
int tot;

int pos[maxn];

struct Trie {
    int tr[maxn][26], tot;
    std::bitset<maxn * 26> ed;
    int rt[maxq];

    void ins(int id, const std::string &s) {
        if (not rt[id]) rt[id] = ++tot;
        int now = rt[id];
        for (auto c : s) {
            int x = c - 'a';
            if (not tr[now][x]) tr[now][x] = ++tot;
            now = tr[now][x];
        }
        ed.set(now);
        return now;
    }

    int dfn[maxn], dpos;
    void dfs(int now) {
        dfn[now] = ++dpos;
        rep (c, 0, 25) {
            if (not tr[now][c]) continue;
            dfs(tr[now][c]);
        } 
    }
} tr0, tr1;

struct Query {
    int id;
    std::string t0, t1;
};

std::vector<Query> qs[maxq];

inline void solve(int h) {

}

void solve() {
	std::cin >> n >> q;
    rep (i, 1, n) {
        std::string s0, s1; std::cin >> s0 >> s1;
        s0 = " " + s0;
        s1 = " " + s1;

        int sl = 1; while (s0[sl] == s1[sl]) sl++;
        int sr = s0.size() - 1; while (s0[sr] == s1[sr]) sr--;
        
        std::string ss0 = "", ss1 = "";
        rep (k, sl, sr) ss0 += s0[k];
        rep (k, sl, sr) ss1 += s1[k];
        
        std::string pre = "";
        per (i, sl - 1, 1) pre += s0[k];
        rep (i, sr + 1, s0.size() - 1) suf += s0[k];
        
        u64 h0 = get(ss0);
        u64 h1 = get(ss1);
        
        if (not id.count({h0, h1})) {
            tot++;
            id[{h0, h1}] = tot;
        } 
        
        int x = id[{h0, h1}];
        tr0.ins(x, pre);
        tr1.ins(x, suf);
    }
    
    rep (i, 1, q) {
        std::cin >> t0 >> t1;
        if (t0.size() != t1.size()) continue;

        int tl = 1; while (t0[sl] == t1[sl]) sl++;
        int tr = t0.size() - 1; while (t0[sr] == t1[sr]) sr--;
        
        std::string tt0 = "", tt1 = "";
        rep (k, tl, tr) tt0 += t0[k];
        rep (k, tl, tr) tt1 += t1[k];
        
        u64 h0 = get(tt0);
        u64 h1 = get(tt1);
        if (not id.count({h0, h1})) continue;
        qry[id[{h0, h1}]].push_back({i, t0, t1});
    }   

    rep (i, 1, tot) {
        solve(i);
    }
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
