#include <iostream>

using i64 = long long;

const int maxn = 1000005;

int n, m;

bool filled[maxn];
int a[maxn];

namespace Subtask1 {
    int a_edited[maxn];

    bool check () {
        int tot = 0;
        for (int i = 1; i < n; i++) {
            tot += bool(a_edited[i] != a_edited[i + 1]);
        }
        return tot == m;
    }

    inline void display () {
        for (int i = 1; i <= n; i++) { std::cout << a_edited[i]; } std::cout << "\n";
    }

    inline void solve () {
        for (int S = 0; S < (1 << m); S++) {
            for (int i = 1; i <= n; i++) { a_edited[i] = a[i]; }
            
            int Sid = 0;
            for (int i = n; i >= 1; i--) {
                if (filled[i]) { continue; }
                bool now = S & (1 << Sid); Sid++;
                a_edited[i] = now;
            }

            if (check ()) { display (); return; }
        }

        std::cout << -1 << "\n";
    }
}

namespace Subtask2 {
    inline void solve () {
        if (m + 1 > n) { std::cout << -1 << "\n"; return; }
        
        int aid = n;

        int curr = m % 2;
        for (int i = 1; i <= m + 1; i++) {
            a[aid--] = curr;
            curr ^= 1;
        }   

        for (int i = 1; i <= n; i++) { std::cout << a[i]; } std::cout << "\n";
    }
}

int main () {

    // freopen ("A_test.out", "w", stdout);

    std::cin >> n >> m;

    int filled_cnt = 0;

    for (int i = 1; i <= n; i++) {
        char ch; std::cin >> ch;
        if (ch == '0') { filled[i] = true; a[i] = 0; }
        if (ch == '1') { filled[i] = true; a[i] = 1; }
        filled_cnt += filled[i];
    }

    if (filled_cnt == 0) { Subtask2::solve (); }
    else { Subtask1::solve (); }

    return 0;
}

/*
00100101
010110

*/