#include <iostream>
#include <cstring>

#pragma gcc Optimize (3)

using i64 = long long;

#define db(x) std::cerr << #x << " : " << x << "\n";

const int maxn = 200005;
const int mod = 1e9 + 7;
const int maxS = (1 << 10) + 5;

int n;

int a[2][maxn];

int req;

int mem[maxS];
inline int popcount (int S) {
    if (mem[S]) { return mem[S]; }

    int res = 0;
    while (S) { res += (S & 1); S >>= 1; }
    return res;
}

namespace Task1 {

    inline bool chkL () {
        int S = 0;
        for (int i = 1; i <= n; i++) { S |= (1 << a[0][i]); }
        return (popcount (S) == req);
    }

    inline void add (int& a, int b) {
        if (a + b > mod) { a = a + b - mod; }
        else { a = a + b; }
    }

    int id;
    int mem[maxn][maxS];

    int dp (int now, bool lim, int S) {
        if (now == n + 1) { return (popcount (S) == req); }
        if (popcount (S) > req) { return 0; }

        if (not lim and mem[now][S] != -1) { return mem[now][S]; }

        int mx = lim ? a[id][now] : 9;

        int res = 0;
        for (int i = 0; i <= mx; i++) {
            add (res, dp (now + 1, (lim and i == a[id][now]), (S | (1 << i))));
        }
        
        if (not lim) { mem[now][S] = res; }
        return res;
    }

    inline void clear_mem () {
        for (int i = 1; i <= n + 1; i++) {
            for (int S = 0; S < (1 << 10); S++) { mem[i][S] = -1; }
        }
    }

    inline void solve () {
        int ans = chkL ();

        id = 1;        
        clear_mem ();
        add (ans, dp (1, true, 0));

        id = 0;
        clear_mem ();
        ans = (ans - dp (1, true, 0) + mod) % mod;

        std::cout << ans << "\n";
    }
}

namespace Task0 {

    i64 L, R;

    inline void init () {
        for (int i = 1; i <= n; i++) { L *= 10ll; L += ::a[0][i]; }
        for (int i = 1; i <= n; i++) { R *= 10ll; R += ::a[1][i]; }
    }

    inline bool chk (i64 now) {
        int S = 0;
        for (int i = 1; i <= n; i++) { S |= (1 << (now % 10ll)); now /= 10ll; }
        return (popcount (S) == req);
    }

    inline void solve () {
        init ();

        i64 ans = 0;
        for (i64 now = L; now <= R; now++) {
            ans += chk (now);
        }
        std::cout << ans << "\n";
    }
}

int main () {

    freopen ("math.in", "r", stdin);
    freopen ("math.out", "w", stdout);

    std::ios::sync_with_stdio (false); std::cin.tie (0);

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        char c; std::cin >> c;
        a[0][i] = c - '0';
    }

    for (int i = 1; i <= n; i++) {
        char c; std::cin >> c;
        a[1][i] = c - '0';
    }

    std::cin >> req;

    if (n <= 10) {
        Task0::solve ();
    } else {
        Task1::solve ();
    }

    return 0;
}