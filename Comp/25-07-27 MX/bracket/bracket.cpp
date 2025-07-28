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

constexpr int maxn = 35;

int n;
char a[maxn];

namespace Task1 {
    char b[maxn];

    std::vector<int> pos;
    inline bool chk() {
        std::vector<char> st;
        rep (i, 1, n) {
            if (b[i] == ']') {
                if (st.empty() or st.back() != '[') return false;
                st.pop_back();
                continue;
            }
            if (b[i] == ')') {
                if (st.empty() or st.back() != '(') return false;
                st.pop_back();
                continue;
            }
            if (b[i] == '>') {
                if (st.empty() or st.back() != '<') return false;
                st.pop_back();
                continue;
            }
            if (b[i] == '}') {
                if (st.empty() or st.back() != '{') return false;
                st.pop_back();
                continue;
            }

            st.push_back(b[i]);
        }

        return st.empty();
    }

    inline void solve() {
        rep (i, 1, n) b[i] = a[i];
        rep (i, 1, n) if (b[i] == '?') pos.push_back(i);

        int ans = 0;
        rep (S, 0, (1 << (3 * pos.size())) - 1) {
            rep (i, 0, pos.size() - 1) {
                int x1 = !!(S & (1 << (3 * i)));
                int x2 = !!(S & (1 << (3 * i + 1)));
                int x3 = !!(S & (1 << (3 * i + 2)));

                int x = (x1 << 2) | (x2 << 1) | (x3);

                if (x == 0) b[pos[i]] = '[';
                if (x == 1) b[pos[i]] = ']';
                if (x == 2) b[pos[i]] = '(';
                if (x == 3) b[pos[i]] = ')';
                if (x == 4) b[pos[i]] = '<';
                if (x == 5) b[pos[i]] = '>';
                if (x == 6) b[pos[i]] = '{';
                if (x == 7) b[pos[i]] = '}';
            }

            if (chk()) {
                ans++;
            }
        }

        std::cout << ans << "\n";
    }
}

void solve() {
    std::string s; std::cin >> s;
    n = s.size();

    rep (i, 0, s.size() - 1) a[i + 1] = s[i];

    Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("bracket")

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
