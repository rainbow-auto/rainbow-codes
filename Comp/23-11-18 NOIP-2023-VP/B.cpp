#include <iostream>
#include <cstring>

using i64 = long long;

int C, T;

int n, m;

namespace Subtask1 {

    const int maxn = 15;

    int pow[maxn];

    inline void get_pow () {
        pow[0] = pow[1] = 1;
        for (int i = 2; i <= 11; i++) {
            pow[i] = pow[i - 1] * 3;
        }
    }

    struct Command {
        int v;
        int i, j;
    } cmds[maxn];

    int curr[maxn];
    int start[maxn];
    
    inline void get (int S) {
        int tot = 0;
        while (S) {
            ++tot;
            curr[tot] = S % 3;
            start[tot] = S % 3;
            S /= 3;
        }
    }

    inline void solve () {
        get_pow ();
        
        while (T--) {
            std::cin >> n >> m;

            for (int i = 1; i <= m; i++) {
                char c; std::cin >> c;
                if (c == '+') { int x, y; std::cin >> x >> y; cmds[i] = Command { 3, x, y }; }
                if (c == '-') { int x, y; std::cin >> x >> y; cmds[i] = Command { 4, x, y }; }
                if (c == 'F') { int x; std::cin >> x; cmds[i] = Command { 0, x, 0 }; }
                if (c == 'T') { int x; std::cin >> x; cmds[i] = Command { 1, x, 0 }; }
                if (c == 'U') { int x; std::cin >> x; cmds[i] = Command { 2, x, 0 }; }
            }

            int ans = 0x3f3f3f3f;

            for (int S = 0; S < pow[n + 1]; S++) {
                memset (curr, 0, sizeof (curr));
                memset (start, 0, sizeof (start));
                
                get (S);

                for (int i = 1; i <= m; i++) {
                    if (cmds[i].v < 3) { curr[cmds[i].i] = cmds[i].v; continue; }

                    if (cmds[i].v == 3) {
                        curr[cmds[i].i] = curr[cmds[i].j];
                    }

                    if (cmds[i].v == 4) {
                        int other = curr[cmds[i].j];
                        if (other == 2) { curr[cmds[i].i] = other; }
                        if (other == 1) { curr[cmds[i].i] = 0; }
                        if (other == 0) { curr[cmds[i].i] = 1; }
                    }
                }   

                bool flag = true;
                for (int i = 1; i <= n; i++) { if (curr[i] != start[i]) { flag = false; break; } }

                if (flag) { 
                    int u_cnt = 0;
                    for (int i = 1; i <= n; i++) { if (start[i] == 2) { u_cnt ++; } }
                    ans = std::min (ans, u_cnt);
                }
            }

            std::cout << ans << "\n";
        }   
    }
}

namespace Subtask2 {
    
    const int maxn = 100005;

    char a[maxn];

    inline void solve () {

        while (T--) {
            memset (a, 0, sizeof (a));

            std::cin >> n >> m;

            for (int i = 1; i <= m; i++) {
                char v; std::cin >> v;
                int x; std::cin >> x;
                
                a[x] = v;
            }

            int u_cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 'U') { u_cnt ++; }
            }

            std::cout << u_cnt << "\n";
        }
    }
}

int main () {

    std::cin >> C >> T;

    if (C == 1 or C == 2) { Subtask1::solve (); return 0; }
    if (C == 3 or C == 4) { Subtask2::solve (); return 0; }

    return 0;
}