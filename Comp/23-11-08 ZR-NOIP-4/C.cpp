/*
    Faild

    终究还是寄了
*/


#include <iostream>
#include <queue>
#include <cstring>

using i64 = long long;

const int maxn = 10000005;

namespace Reader {
    template <int T>
    struct fast_io {
        char p[T], *p1, *p2;
        fast_io() {
            p1 = p2 = p;
            fread(p, 1, T, stdin);    
        }
        char gc() {
            return *p1++;
        }

    };
    fast_io<110'000'000> io;
    int read() {
        int r = 0, neg = 1;
        char ch;
        do ch = io.gc();while (ch < 48 || ch > 57);
        do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
        return r;
    }
}

int n, m;
int a[maxn];

namespace Solution {

    int t[maxn];
    i64 cnt[maxn];
    i64 w[maxn];

    struct BigNode {
        i64 val;
        friend bool operator < (BigNode a, BigNode b) { return a.val < b.val; }
    };

    struct SmallNode {
        i64 val;
        friend bool operator < (SmallNode a, SmallNode b) { return a.val > b.val; }
    };

    std::priority_queue <BigNode> A;
    std::priority_queue <SmallNode> B;

    inline void clear () {
        memset (cnt, 0, sizeof (cnt));
        memset (w, 0, sizeof (w));
        memset (t, 0, sizeof (t));
        while (not A.empty ()) { A.pop (); }
        while (not B.empty ()) { B.pop (); }
    }

    inline void solve () {
        clear ();

        for (int i = 1; i <= n; i++) { t[a[i]]++; }
        
        for (int i = 1; i <= m; i++) { cnt[i] = t[i] ? 0 : 1; }
        for (int i = 1; i <= m; i++) { cnt[i] += cnt[i - 1]; }
        
        for (int i = 1; i <= m; i++) { w[i] = t[i]; }
        for (int i = m; i >= 1; i--) { w[i] += w[i + 1]; }

        i64 ans = 0;
        for (int i = 1; i <= m; i++) { ans += t[i] ? 0 : w[i]; }

        std::cerr << "t: "; for (int i = 1; i <= m; i++) { std::cerr << t[i] << " "; } std::cerr << "\n";
        std::cerr << "w: "; for (int i = 1; i <= m; i++) { std::cerr << w[i] << " "; } std::cerr << "\n";
        std::cerr << "ans = " << ans << "\n";

        for (int i = 1; i <= m; i++) {
            if (not t[i]) { A.push (BigNode { i - cnt[i - 1] - 1 + w[i] }); std::cerr << i - cnt[i - 1] - 1 + w[i] << " "; }
        }

        std::cerr << "\n";

        for (int i = 1; i <= m; i++) {
            for (int j = 2; j <= t[i]; j++) { B.push (SmallNode { i - cnt[i] }); std::cerr << i - cnt[i] << " "; }
        }

        std::cerr << "\n";

        while (not A.empty () and not B.empty ()) {
            ans += B.top ().val - A.top ().val;
            A.pop (); B.pop ();
        }

        std::cout << ans << "\n";
    }
}


int main () {

    int Q = Reader::read ();

    while (Q--) {
        n = Reader::read ();
        m = Reader::read ();

        for (int i = 1; i <= n; i++) { a[i] = Reader::read (); }

        Solution::solve ();
    }    

    return 0;
}