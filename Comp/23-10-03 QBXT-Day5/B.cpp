#include <iostream>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

const int maxn = 300005;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
//                 L, R, D, U 

int n;
int c[maxn];

namespace Task1 {

    const int maxn = 2005 << 1;

    int vis[maxn][maxn];

    inline pair<int, int> getPos (int x, int y) { return pair<int, int> { x + 2005, y + 2005 }; }
    inline pair<int, int> getRealPos (int x, int y) { return pair<int, int> { x - 2005, y - 2005 }; }

    int walk (int disable) {
        memset (vis, 0, sizeof (vis));
        int nowx = getPos (0, 0).first;
        int nowy = getPos (0, 0).second;

        int res = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (i == disable) { continue; }
            vis[nowx][nowy] ++;

            int realX = getRealPos (nowx, nowy).first;
            int realY = getRealPos (nowx, nowy).second;

            res += 1ll * vis[nowx][nowy] * ((abs (realX) + 1) xor (abs (realY) + 1)) + vis[nowx][nowy];

            nowx += dx[c[i]];
            nowy += dy[c[i]];
        }

        return res;
    }

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            cout << walk (i) << endl;
        }
    }

}

int main () {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        char now; cin >> now;

        if (now == 'L') { c[i] = 0; }
        if (now == 'R') { c[i] = 1; }
        if (now == 'D') { c[i] = 2; }
        if (now == 'U') { c[i] = 3; }
    }

    Task1::solve ();

    return 0;
}