#include <iostream>
#include <cstring>

using i64 = long long;

int n, T, Q;

namespace Subtask1 {
    const int maxn = 105;

    const int dx[] = { 0, 1, 0, -1 };
    const int dy[] = { 1, 0, -1, 0 };

    int times[maxn][maxn];

    void dfs (int nowx, int nowy, int step) {
        if (nowx < 0 or nowx > n or nowy < 0 or nowy > n) { return; }
        
        if (step == T) { times[nowx][nowy]++; return; }
        
        for (int i = 0; i < 4; i++) {
            int tx = nowx + dx[i];
            int ty = nowy + dy[i];

            dfs (tx, ty, step + 1);
        }   
    }

    inline void solve (int x1, int y1, int x2, int y2) {
        memset (times, 0, sizeof (times));
        
        dfs (x1, y1, 0);

        std::cout << times[x2][y2] << "\n";
    }

}

int main () {
    
    std::cin >> n >> T >> Q;


    while (Q--) {
        int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

        Subtask1::solve (x1, y1, x2, y2);
    }

    return 0;
}