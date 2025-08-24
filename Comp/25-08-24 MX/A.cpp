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

constexpr char a[5][4] = {
    { ' ', '/', '*', '-' }, 
    { '7', '8', '9', '+' },
    { '4', '5', '6', '+' },
    { '1', '2', '3', ' ' },
    { '0', '0', '.', ' ' }
};

inline bool chk(std::string s) {
    if (s[0] == s[1] or s[1] == s[2]) return false;
    
    rep (i, 0, 4) rep (j, 0, 1) {
        bool flg = true;
        rep (k, 0, s.size() - 1) flg &= s[k] == a[i][j + k];
        if (flg) return true;
    }
    
    rep (j, 0, 3) rep (i, 0, 2) {
        bool flg = true;
        rep (k, 0, s.size() - 1) flg &= s[k] == a[i + k][j];
        if (flg) return true;
    }

    return false;
}

void solve() {
    std::string s; std::cin >> s;
    
    if (chk(s)) return std::cout << "Yes\n", void(0);
    std::reverse(s.begin(), s.end());
    if (chk(s)) return std::cout << "Yes\n", void(0);

    std::cout << "No\n";
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
