// Solved
// 100pts

#include <iostream>
#include <set>
#include <cstring>

const int maxn = 45;

int n;
char a[maxn];

bool vis[maxn][maxn];
bool mark[maxn][maxn];

std::set< std::pair<int, int> > ans;

int main () {

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    for (int S = 0; S <= (1 << n) - 1; S++) {
        memset (mark, 0, sizeof (mark));
        memset (vis, 0, sizeof (vis));
        int now_x = 0, now_y = 0;
        
        for (int i = 1; i <= n; i++) {
            vis[now_x + 22][now_y + 22] = true;
            
            int nx = now_x; int ny = now_y;
            if (a[i] == 'L') { nx --; }
            if (a[i] == 'R') { nx ++; }
            if (a[i] == 'U') { ny ++; }
            if (a[i] == 'D') { ny --; }
            
            if ((S & (1 << (i - 1))) and not mark[nx + 22][ny + 22]) {
                now_x = nx; now_y = ny;
            } else {
                mark[nx + 22][ny + 22] = true;
                if (vis[nx + 22][ny + 22]) { goto illegal; }
            }
        }

        ans.insert ({ now_x, now_y });

        illegal: continue;
    }

    std::cout << ans.size () << "\n";
    for (auto now : ans) {
        std::cout << now.first << " " << now.second << "\n";
    }

    return 0;
}