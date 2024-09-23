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

i64 n;

inline int getlen (i64 n) {
    int len = 0;
    while (n) {
        len ++;
        n /= 10;
    }
    return len;
}

const int maxn = 23;

int a[maxn];
bool s[maxn];

int curr[maxn][2];
int vis[maxn];
bool dfs (int pos, bool id, int* l) {
    if (vis[pos] == 1) return true;
    vis[pos] ++;

    // db << "pos: " << pos << " id: " << id << "\n";
    // db << "l: " << l[0] << " " << l[1] << "\n";
    // assert (pos <= l[id]);
    if (pos > l[id]) { return true; }

    curr[pos][id] = s[pos] * 10 + a[pos] - curr[pos][id ^ 1] - s[pos - 1];
    if (curr[pos][id] < 0 or curr[pos][id] > 9) return false;
    curr[l[id] - pos + 1][id] = curr[pos][id];
    return dfs (l[id] - pos + 1, id ^ 1, l);
}

inline int f (int S, int len) {
    rep (i, 1, len) s[i] = (S & (1 << (i - 1)));

    rep (i, 1, len) db << s[i] << " ";
    dbendl;

    std::cerr<<((std::bitset<4>(S)))<<'\n'; 

    i64 ans = 0;

    rep (l, 1, len - 1) {
        int lens[2] = { len, l };

        memset (curr, 0, sizeof (curr));
        memset (vis, 0, sizeof (vis));

        bool flag = true;
        rep (j, l + 1, len - 1) {
            int k = len - j + 1;
            curr[j][0] = s[j] * 10 + a[j] - curr[j][1] - s[j - 1];
            curr[k][0] = curr[j][0];
            if (k >= l + 1) {
                if (curr[k][0] != curr[k][0]) {
                    
                }
            }
            if (curr[j][0] < 0 or curr[j][0] > 9 or curr[j][0] != curr[k][0]) {
                flag = false; break;
            }
        }
        bool flag = dfs (len, 0, lens);
        dbendl;
        ans += flag;
    }
    // db<<"ans1:"<<ans<<'\n';
    ans *= 2;

    rep (i, len - 1, len) {
        i64 ansnow = 1;
        rep (j, 1, i / 2 + i % 2) {
            i64 k = 0;
            int t = i - j + 1;

            db << "t: " << t << "\n";

            rep (x, (j == i), 9) {
                int y = s[j] * 10 + a[j] - x - s[j - 1];
                db << x << " " << y << "\n";
                if ((y < (0 + (j == i)) or y > 9) or (x + y != s[t] * 10 + a[t] - s[t - 1])) {
                    db << "case1: " << s[t] * 10 + a[t] - s[t - 1] << "\n";
                    db << s[t] << "\n";
                    db << a[t] << "\n";
                    db << s[t - 1] << "\n";
                    continue;
                }
                if (t == i and (y == 0 or x == 0)) {
                    continue;
                }
                // db << "kkkk\n";
                k ++;
            }
            dbg (k);
            ansnow *= k;
        }
        if (i == len - 1 and s[len - 1] != a[len]) { ansnow = 0; } 
        // dbg (ansnow);
        ans += ansnow;
    }

    db << ans << "\n";

    return ans;
}

inline void solve () {
    std::string s; std::cin >> s;
    int len = s.length ();
    rep (i, 1, len) a[i] = s[i - 1] - '0';
    std::reverse (a + 1, a + len + 1);

    db << "a:";
    rep (i, 1, len) db << a[i] << " ";
    dbendl;

    i64 ans = 0;
    rep (S, 0, (1 << (len-1)) - 1) {
        ans += f (S, len);
    }

    std::cout << ans << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// freopen ("palindrome.in", "r", stdin);
	// freopen ("palindrome.out", "w", stdout);

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}
